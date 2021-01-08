#ifndef __SILLA_ASYNC_TASK_TASK_PROCESSOR_MANAGER_HH__
#define __SILLA_ASYNC_TASK_TASK_PROCESSOR_MANAGER_HH__

#include <thread>
#include <atomic>
#include <list>
#include <functional>
#include <mutex>
#include <vector>
#include "task-processor.hh"
#include "sptr.hh"


namespace silla {

class TaskProcessorManager {
  public:
    TaskProcessorManager(const int& size) noexcept;
    ~TaskProcessorManager() noexcept;

    void Assign(const Task& task) noexcept;
    int GetTaskProcessorPoolSize() const noexcept;
    void Interrupt() noexcept;
    
  private:
    $<TaskQueue> task_queue_;
    std::vector<$<TaskProcessor>> task_processor_pool_;
};

}


#endif
