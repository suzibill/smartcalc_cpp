#ifndef MODEL_H
#define MODEL_H
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>

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

class Model {
 public:
  Model(const char *input);

  double Calculate();
  double Calculate(double x);

 private:
  Model();
  bool parseString(const char *input);
  bool checkString();
  void reversedPolish();
  std::queue<std::pair<type_t, double> > _queue;
  int getPriority(int op);
};

#endif  // MODEL_H