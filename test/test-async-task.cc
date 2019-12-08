#include <iostream>
#include <mutex>
#include <async-task/async-task.hh>


using namespace silla;

int main() {
  
  std::cout << AsyncTask::GetThreadPoolSize() << std::endl;

  $<std::mutex> m = new$<std::mutex>();
  int loop_time = 10;
  for(int i = 0; i < AsyncTask::GetThreadPoolSize(); i++) {
    int id = i;
    AsyncTask::Execute([=](){
      for(int j = 0; j < loop_time; j++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "async task" << id << " " << j << std::endl;
      }
    });
  }

  for(int i = 0; i < loop_time + 2; i++) {
    std::cout << "main task " << i << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}

