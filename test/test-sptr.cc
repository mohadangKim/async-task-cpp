#include <async-task/sptr.hh>
#include <iostream>


using namespace silla;

class Test {
  public:
    void p() {
      std::cout << "Test" << std::endl;
    }
};

int main() {
  $<Test> test = new_$<Test>();
  test->p();
  return 0;
}
