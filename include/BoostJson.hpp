
#pragma once
#include <boost/fusion/include/sequence.hpp>
#include <boost/fusion/include/algorithm.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/adapt_adt.hpp>
#include <boost/fusion/include/is_sequence.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits.hpp> 

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/lexical_cast.hpp>

#include <boost/foreach.hpp>

#include <type_traits>
#include <typeinfo>
#include <vector>
#include <list>
#include <map>

static std::string type_name_to_recover = "";

template<typename type_t> 
struct is_container : public std::false_type {};

template<typename type_t, typename allocator_t> 
struct is_container < std::vector < type_t , allocator_t> > : public std::true_type {};

template<typename type_t, typename allocator_t> 
struct is_container < std::list < type_t , allocator_t> >  : public std::true_type {};

template <typename type_t> 
struct simple_serializer;

template <typename type_t> 
struct resolve_serializer_type;


template <typename sequence_t, typename index_t>
struct sequence_iterator
{
    typedef typename boost::fusion::result_of::value_at<sequence_t, index_t>::type current_type_t;
    typedef typename boost::mpl::next<index_t>::type next_index_t;
    typedef boost::fusion::extension::struct_member_name<sequence_t, index_t::value> type_name_t;

    static inline void read_json( boost::property_tree::ptree  &pt, sequence_t& sequence) 
    {
        type_name_to_recover = type_name_t::call();
        simple_serializer<current_type_t>::read_json(pt, boost::fusion::at<index_t>(sequence));
        type_name_to_recover = "";
        sequence_iterator<sequence_t, next_index_t>::read_json(pt, sequence);
    }

};


//tail of the sequence
template <typename sequence_t>
struct sequence_iterator<sequence_t, typename boost::fusion::result_of::size<sequence_t>::type > 
{
    static inline void read_json( boost::property_tree::ptree  &pt, sequence_t& sequence) { }
};

template < typename sequence_t >
struct sequence_iterator_final : sequence_iterator < sequence_t, boost::mpl::int_< 0 > > {};



////////////////////////////////////////////////////////
//Plain old types serializer
////////////////////////////////////////////////////////
template <typename type_t> 
struct serialize_pod
{
    typedef serialize_pod<type_t> type;
    static inline void read_json( boost::property_tree::ptree  &pt, type_t& t) 
    {
        auto v = pt.get_child(type_name_to_recover);
        t =  boost::lexical_cast<type_t>(v.data());
    }
};

////////////////////////////////////////////////////////
//Sequence serializer
////////////////////////////////////////////////////////

template <typename sequence_t> 
struct serialize_sequence 
{
typedef serialize_sequence<sequence_t> type;

static inline void read_json( boost::property_tree::ptree  &pt, sequence_t& sequence) 
{
    sequence_iterator_final<sequence_t>::read_json(pt, sequence);
}

};


//
template <typename type_t> 
struct simple_serializer : public resolve_serializer_type<type_t>::type { };


////////////////////////////////////////////////////////
//Container serializer
////////////////////////////////////////////////////////
template <typename container_type_t> 
struct serialize_container 
{
typedef serialize_container<container_type_t> type;

template <typename type_t>
static void read_json( boost::property_tree::ptree  &pt, std::vector<type_t> &t) 
{
    std::string temp_name = type_name_to_recover;
    type_name_to_recover = "";
    BOOST_FOREACH( boost::property_tree::ptree::value_type &tree_node_value, pt.get_child(temp_name) )
    {
        boost::property_tree::ptree subtree = (boost::property_tree::ptree) tree_node_value.second ;
        if( subtree.empty() )
        {
            type_t type_val;
            simple_serializer<type_t>::read_json(subtree, type_val);
            t.push_back(type_val);
        }
        else
        {
            type_t type_val;

            std::stringstream os;
            boost::property_tree::write_json(os, subtree);

            boost::property_tree::ptree pt_x;
            boost::property_tree::json_parser::read_json(os, pt_x);

            simple_serializer<type_t>::read_json(pt_x, type_val);

            t.push_back(type_val);
        }
    }
}

};



template <typename type_t> 
struct resolve_serializer_type 
{
    typedef 
    typename boost::mpl::eval_if< boost::fusion::traits::is_sequence < type_t > , serialize_sequence < type_t > , 
    typename boost::mpl::eval_if< is_container < type_t > , boost::mpl::identity < serialize_container < type_t > >,
    serialize_pod < type_t >  >  > 
    ::type type;
};

