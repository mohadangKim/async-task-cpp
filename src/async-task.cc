#include <async-task/async-task.hh>


using namespace silla;

TaskProcessorManager AsyncTask::
    Manager_((std::thread::hardware_concurrency() * 2) + 1);

void AsyncTask::Execute(const Task& task) noexcept {
  Manager_.Assign(task);
}

int AsyncTask::GetThreadPoolSize() noexcept {
  return Manager_.GetTaskProcessorPoolSize();
}
