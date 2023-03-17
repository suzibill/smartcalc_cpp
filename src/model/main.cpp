#include <iostream>

#include "model.h"

int main() {
  // try {
  Model model("1 + unknown");
  std::cout << "res:" << model.Calculate() << std::endl;
  // } catch (std::invalid_argument &e) {
  //   std::cout << e.what() << std::endl;
  // }

  return 0;
}
