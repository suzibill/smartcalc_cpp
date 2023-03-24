#include "model.h"

// model recieve a string, parse it to a stack and translate it to reverse
// polish notation then calculate the result
Model::Model(const char *input) {
  if (parseString(input) == false) {
    throw std::invalid_argument("Invalid expression");
  }
  reversedPolish();
}
