#include <async-task/task-processor.hh>
#include <chrono>
#include <iostream>


using namespace silla;

TaskProcessor::TaskProcessor(const $<TaskQueue>& task_queue) noexcept
    : task_queue_(task_queue)
{
  thread_ = new$<std::thread>([&](){
    try {
      while(true) {
          Process(task_queue_->Pop());
      }
    } catch (const TaskQueue::InterruptedException& e) {
      return;
    }
  });
}

TaskProcessor::~TaskProcessor() noexcept(false) {
  if(is_processing_) {
    throw TaskUncompletedException();
  } else {
    task_queue_->Interrupt();
    thread_->detach();
  }
}

bool TaskProcessor::IsProcessing() const noexcept {
  return is_processing_;
}

void TaskProcessor::Process(const Task& task) noexcept {
  is_processing_ = true;
  task();
  is_processing_ = false;
}
