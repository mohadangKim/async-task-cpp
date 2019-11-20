#include <async-task/async-task.hh>


using namespace silla;

TaskProcessorManager AsyncTask::
    MANAGER_(std::thread::hardware_concurrency() + 1);

void AsyncTask::Execute(const Task& task) noexcept {
  MANAGER_.Assign(task);
}
