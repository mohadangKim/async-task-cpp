#ifndef __SILLA_ASYNC_TASK_TASK_HH__
#define __SILLA_ASYNC_TASK_TASK_HH__

#include <functional>


namespace silla {
  
using Task = std::function<void()>;

}


#endif
