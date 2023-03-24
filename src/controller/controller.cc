#include "controller.h"

std::string Controller::proccess(std::string input, double x) {
  const char* input_c = input.c_str();
  std::string result;
  try {
    Model model(input_c);
    return std::to_string(model.Calculate(x));
  } catch (...) {
    return std::string("error");
  }
}

bool Controller::checkString(std::string input) {
  const char* input_c = input.c_str();

  try {
    _model = new Model(input_c);
    return true;
  } catch (...) {
    return false;
  }
}

double Controller::proccessGraph(double x) { return _model->Calculate(x); }

Controller::~Controller() { delete _model; }
