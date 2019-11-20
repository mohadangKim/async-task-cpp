#ifndef __SILLA_ASYNC_TASK_SPTR_HH__
#define __SILLA_ASYNC_TASK_SPTR_HH__

#include <memory> 


namespace silla {

template <class T>
using $ = std::shared_ptr<T>;

template <typename T, typename... Args>
$<T> new$(Args&&... args)
{
    return std::make_shared<T>(args...);
}

}


#endif
