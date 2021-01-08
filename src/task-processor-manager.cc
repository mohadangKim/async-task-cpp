#include <async-task/task-processor-manager.hh>


using namespace silla;

TaskProcessorManager::TaskProcessorManager(const int& size) noexcept
  : task_processor_pool_(size)
{
  task_queue_ = new$<TaskQueue>();
  for(int i = 0; i < size; i++) {
    task_processor_pool_[i] = new$<TaskProcessor>(task_queue_);
  }
}

TaskProcessorManager::~TaskProcessorManager() noexcept {
  Interrupt();
}

void TaskProcessorManager::Assign(const Task& task) noexcept {
  task_queue_->PushBack(task);
}

int TaskProcessorManager::GetTaskProcessorPoolSize() const noexcept {
  return task_processor_pool_.size();
}

void TaskProcessorManager::Interrupt() noexcept {
  if (task_queue_ != nullptr) {
    task_queue_->Interrupt();
  }
}