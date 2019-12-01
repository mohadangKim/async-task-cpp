#ifndef __SILLA_ASYNC_TASK_TASK_PROCESSOR_HH__
#define __SILLA_ASYNC_TASK_TASK_PROCESSOR_HH__

#include <memory>
#include <thread>
#include <mutex>
#include <atomic>
#include <functional>
#include "task-queue.hh"
#include "task.hh"
#include "sptr.hh"


namespace silla {

class TaskProcessor {
  public:
    class TaskUncompletedException : public std::exception {
      public: 
        virtual const char* what() const noexcept override {
          return "TaskProcessor : TaskUncomplitedException";
        }
    };

    TaskProcessor(const $<TaskQueue>& task_queue) noexcept;
    ~TaskProcessor();
    
    bool IsProcessing() const noexcept;

  private:  
    $<std::thread> thread_;
    std::atomic<bool> is_processing_;
    $<TaskQueue> task_queue_;

    void Process(const Task& task) noexcept;
}; 

}


#endif
