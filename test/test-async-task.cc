#include <iostream>
#include <mutex>
#include <async-task/async-task.hh>


using namespace silla;

int main() {
  std::mutex m;
  int size = 5;
  AsyncTask::Execute([&](){
    for(int i = 0; i < size; i++) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::unique_lock<std::mutex> lock(m);
      std::cout << "task1 " << i << std::endl;
    }
  });

  AsyncTask::Execute([&](){
    for(int i = 0; i < size; i++) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::unique_lock<std::mutex> lock(m);
      std::cout << "task2 " << i << std::endl;
    }
  });

  for(int i = 0; i < size - 1; i++) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex> lock(m);
    std::cout << "main " << i << std::endl;
  }
  /*
  for(int i = 0; i < 1000000; i++) {
    std::cout << "task" << i << std::endl;
  }
  std::cout << "end" << std::endl;
  */
  return 0;
}

