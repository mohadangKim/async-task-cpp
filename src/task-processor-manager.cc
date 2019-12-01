#include <iostream>
#include <chrono>
#include <async-task/task-processor-manager.hh>


using namespace silla;

TaskProcessorManager::TaskProcessorManager(const int& size) noexcept
  : pool_(size)
{
  task_queue_ = new$<TaskQueue>();
  for(int i = 0; i < size; i++) {
    pool_[i] = new$<TaskProcessor>(task_queue_);
  }
}

TaskProcessorManager::~TaskProcessorManager() {
  pool_.clear();
}

void TaskProcessorManager::Assign(const Task& task) noexcept {
  task_queue_->PushBack(task);
}
