#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>

#include "../model/model.h"

/// @brief class Controller contains all methods for bring information
/// from view to model and vice versa
class Controller {
 public:
  /// @brief default constructor
  Controller() = default;

  /// @brief default destructor
  ~Controller();

  /// @brief method proccess recieve input string and return result
  /// @param input the input string
  /// @param x the value of x
  /// @return the result of the expression
  std::string proccess(std::string input, double x);

  /// @brief  method checkString check the input string
  /// @param input
  /// @return true if the input string is valid, false otherwise
  bool checkString(std::string input);

  /// @brief method proccessGraph recieve x and return the result of the
  /// expression
  /// @param x the value of x
  /// @return the result of the expression
  double proccessGraph(double x);

 private:
  Model *_model = nullptr;
};

#endif  // CONTROLLER_H
