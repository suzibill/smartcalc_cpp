#ifndef MODEL_H
#define MODEL_H
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>

/// @brief enum type_t contains all types of tokens
typedef enum type_t {
  NONE = 0,
  NUM = 1,
  X = 2,
  PLUS = 3,
  MINUS = 4,
  MUL = 5,
  DIV = 6,
  MOD = 7,
  EXP = 8,
  COS = 9,
  SIN = 10,
  TAN = 11,
  ACOS = 12,
  ASIN = 13,
  ATAN = 14,
  SQRT = 15,
  LN = 16,
  LOG = 17,
  BRACK_O = 18,
  BRACK_C = 19,
} type_t;

/// @brief class Model contains all methods for calculating the expression
class Model {
 public:
  /// @brief parametric constructor, default constructor is private
  /// @param input the input string
  Model(const char *input);

  /// @brief method calculate return the result of the expression
  /// @return the result of the expression
  double Calculate();

  /// @brief method calculate recieve x and return the result of the expression
  /// @param x the value of x
  /// @return the result of the expression
  double Calculate(double x);

 private:
  std::queue<std::pair<type_t, double> > _queue;

  Model();
  /// @brief method parseString parse the input string and store the result in
  /// _queue
  /// @param input the input string
  /// @return true if the input string is valid, false otherwise
  bool parseString(const char *input);
  /// @brief method checkString check the input string
  /// @param input the input string
  /// @return true if the input string is valid, false otherwise
  bool checkString();

  /// @brief method reversedPolish convert the infix expression to postfix
  void reversedPolish();
  /// @brief method getPriority return the priority of the operator
  /// @param op the operator
  /// @return the priority of the operator
  int getPriority(int op);
};

#endif  // MODEL_H