#include <async-task/task-queue.hh>


using namespace silla;

void TaskQueue::PushBack(const Task& task) noexcept {
  {
    std::unique_lock<std::mutex> lock(m_);
    queue_.push_front(task);
  }
  conv_.notify_one();
}

Task TaskQueue::Pop() noexcept(false) {
  std::unique_lock<std::mutex> lock(m_);
  conv_.wait(lock, [=](){
    if(is_interrupted_) {
      throw InterruptedException();
    }
    return !queue_.empty();
  });
  Task task = queue_.back();
  queue_.pop_back();
  return task;
}

void TaskQueue::Interrupt() noexcept {
  std::unique_lock<std::mutex> lock(m_);
  is_interrupted_ = true;
  conv_.notify_one();
}

int TaskQueue::Size() noexcept {
  std::unique_lock<std::mutex> lock(m_);
  return queue_.size();
}
