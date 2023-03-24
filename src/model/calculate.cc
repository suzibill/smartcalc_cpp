#include "model.h"

double Model::Calculate() { return Calculate(0); }

double Model::Calculate(double x) {
  double result = 0;
  std::stack<double> stack;
  std::queue<std::pair<type_t, double> > res_queue = _queue;

  while (!res_queue.empty()) {
    std::pair<type_t, double> p = res_queue.front();
    res_queue.pop();
    double num = p.second;
    if (p.first == NUM) {
      stack.push(num);
    } else if (p.first == X) {
      stack.push(x);
    } else {
      double a = stack.top();
      stack.pop();
      bool is_binary_op = false;
      switch (p.first) {
        case COS:
          stack.push(cos(a));
          break;
        case SIN:
          stack.push(sin(a));
          break;
        case TAN:
          stack.push(tan(a));
          break;
        case ACOS:
          stack.push(acos(a));
          break;
        case ASIN:
          stack.push(asin(a));
          break;
        case ATAN:
          stack.push(atan(a));
          break;
        case SQRT:
          stack.push(sqrt(a));
          break;
        case LN:
          stack.push(log(a));
          break;
        case LOG:
          stack.push(log10(a));
          break;
        default:
          is_binary_op = true;
          break;
      }
      if (is_binary_op == false) continue;
      double b = stack.top();
      stack.pop();
      switch (p.first) {
        case PLUS:
          stack.push(a + b);
          break;
        case MINUS:
          stack.push(b - a);
          break;
        case MUL:
          stack.push(a * b);
          break;
        case DIV:
          if (a < 1E-06) {
            stack.push(NAN);
          } else {
            stack.push(b / a);
          }
          break;
        case EXP:
          stack.push(pow(b, a));
          break;
        case MOD:
          stack.push(fmod(b, a));
          break;
        default:
          break;
      }
    }
  }
  result = stack.top();
  stack.pop();
  return result;
}