#include <iostream>
#include <async-task/task-processor-pool.hh>
#include <chrono>


using namespace silla;

int main() {
  TaskProcessorPool task_processor_pool;
  std::this_thread::sleep_for(std::chrono::seconds(10));
  task_processor_pool.Interrupt();
  return 0;
}
