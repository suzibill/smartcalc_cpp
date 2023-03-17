#include "model.h"

int Model::getPriority(int op) {
  switch (op) {
    case PLUS:
    case MINUS:
      return 1;
    case MUL:
    case DIV:
    case MOD:
      return 2;
    case EXP:
      return 3;
    case COS:
    case SIN:
    case TAN:
    case ACOS:
    case ASIN:
    case ATAN:
    case SQRT:
    case LN:
    case LOG:
      return 4;
    case BRACK_O:
    case BRACK_C:
      return 0;
    default:
      return -1;
  }
}
void Model::reversedPolish() {
  std::stack<std::pair<type_t, double> > stack;
  std::queue<std::pair<type_t, double> > res_queue;
  while (!_queue.empty()) {
    std::pair<type_t, double> p = _queue.front();
    _queue.pop();
    if (p.first == NUM || p.first == X) {
      res_queue.push(p);
    } else if (p.first == BRACK_O) {
      stack.push(p);
    } else if (p.first == BRACK_C) {
      while (stack.top().first != BRACK_O) {
        res_queue.push(stack.top());
        stack.pop();
      }
      stack.pop();
    } else {
      while (!stack.empty() &&
             getPriority(stack.top().first) >= getPriority(p.first)) {
        res_queue.push(stack.top());
        stack.pop();
      }
      stack.push(p);
    }
  }

  while (!stack.empty()) {
    res_queue.push(stack.top());
    stack.pop();
  }

  _queue = res_queue;
}