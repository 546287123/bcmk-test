
#include "cmd_task_runner.h"

bool CmdTaskRunner::Start() {
    _thread = thread(&CmdTaskRunner::run, this);
    _thread.detach();
    return true;
}

bool CmdTaskRunner::Stop() {
    _over = true;
    return true;
}

bool CmdTaskRunner::SkipCur() {

}

shared_ptr<cmd_task_info> CmdTaskRunner::GetTask() {
    return _task;
}

bool CmdTaskRunner::SetTask(shared_ptr<cmd_task_info> task) {
    _task = task;
    return true;
}

void CmdTaskRunner::run() {
    
    return;
}