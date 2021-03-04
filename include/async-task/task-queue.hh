#ifndef __SILLA_ASYNC_TASK_TASK_QUEUE_HH__
#define __SILLA_ASYNC_TASK_TASK_QUEUE_HH__

#include <functional>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <deque>
#include "task.hh"


namespace silla {

class TaskQueue {
  public:
    class InterruptedException : public std::exception {
      public:
        virtual const char* what() const noexcept override {
          return "TaskQueue : Interrupted";
        }
    };

    TaskQueue() noexcept;
    void PushBack(const Task& task) noexcept;
    Task Pop();
    void Interrupt() noexcept;

    int Size() noexcept;
    
  private:
    std::atomic<bool> is_interrupted_;
    std::mutex m_;
    std::condition_variable conv_;
    std::deque<Task> queue_;
};

}


#endif
