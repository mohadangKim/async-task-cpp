#include <iostream>
#include <async-task/async-task.hh>


using namespace silla;

int main() {
  std::cout << "start" << std::endl;
  AsyncTask::Execute([=](){
    std::cout << "async task" << std::endl;
  });
  return 0;
}

