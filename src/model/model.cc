#include "model.h"

// model recieve a string, parse it to a stack and translate it to reverse
// polish notation then calculate the result
Model::Model(const char *input) {
  if (parseString(input) == false) {
    // std::cout << "Exeption suka" << std::endl;
    throw std::invalid_argument("Invalid expression");
  }
  reversedPolish();
  // std::cout << "Model created" << std::endl;
}

// model destructor
// Model::~Model() { std::cout << "Model destroyed" << std::endl; }