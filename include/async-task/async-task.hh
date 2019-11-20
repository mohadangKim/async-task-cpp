#ifndef __SILLA_ASYNC_TASK_CPP_ASYNC_TASK_HH__
#define __SILLA_ASYNC_TASK_CPP_ASYNC_TASK_HH__

#include "task.hh"
#include "task-processor-manager.hh"


namespace silla {

class AsyncTask {
  public:
    static void Execute(const Task& task) noexcept;

  private:  
    static TaskProcessorManager MANAGER_;
};

}


#endif 
