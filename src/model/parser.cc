

#include "model.h"

bool Model::parseString(const char *input) {
  char operators[] = "+-/()^x*%";
  char numbers[] = "1234567890.";
  _queue.push(std::make_pair(BRACK_O, 0));
  for (char *p = (char *)input; *p != '\0'; p++) {
    if (strchr(numbers, *p)) {
      char *ptr;
      _queue.push(std::make_pair(NUM, strtod(p, &ptr)));
      p = ptr - 1;
    } else if (strchr(operators, *p) != NULL) {
      switch (*p) {
        case '+':
          _queue.push(std::make_pair(PLUS, 0));
          break;
        case '-':
          _queue.push(std::make_pair(MINUS, 0));
          break;
        case '*':
          _queue.push(std::make_pair(MUL, 0));
          break;
        case '/':
          _queue.push(std::make_pair(DIV, 0));
          break;
        case '^':
          _queue.push(std::make_pair(EXP, 0));
          break;
        case 'x':
          _queue.push(std::make_pair(X, 0));
          break;
        case '(':
          _queue.push(std::make_pair(BRACK_O, 0));
          if (*(p + 1) == '-') {
            _queue.push(std::make_pair(NUM, 0));
          } else if (*(p + 1) == '+') {
            p++;
          }
          break;
        case ')':
          _queue.push(std::make_pair(BRACK_C, 0));
          break;
        case '%':
          _queue.push(std::make_pair(MOD, 0));
          break;
      }
    } else if (strnstr(p, "cos", 3)) {
      _queue.push(std::make_pair(COS, 0));
      p += 2;
    } else if (strnstr(p, "sin", 3)) {
      _queue.push(std::make_pair(SIN, 0));
      p += 2;
    } else if (strnstr(p, "tan", 3)) {
      _queue.push(std::make_pair(TAN, 0));
      p += 2;
    } else if (strnstr(p, "acos", 4)) {
      _queue.push(std::make_pair(ACOS, 0));
      p += 3;
    } else if (strnstr(p, "asin", 4)) {
      _queue.push(std::make_pair(ASIN, 0));
      p += 3;
    } else if (strnstr(p, "atan", 4)) {
      _queue.push(std::make_pair(ATAN, 0));
      p += 3;
    } else if (strnstr(p, "sqrt", 4)) {
      _queue.push(std::make_pair(SQRT, 0));
      p += 3;
    } else if (strnstr(p, "ln", 2)) {
      _queue.push(std::make_pair(LN, 0));
      p += 1;
    } else if (strnstr(p, "log", 3)) {
      _queue.push(std::make_pair(LOG, 0));
      p += 2;
    } else if (*p == ' ') {
      continue;
    } else {
      return false;
    }
  }

  _queue.push(std::make_pair(BRACK_C, 0));

#ifdef DEBUG
  for (std::queue<std::pair<type_t, double> > dump = _queue; !dump.empty();
       dump.pop()) {
    std::cout << dump.front().first << " " << dump.front().second << std::endl;
  }
#endif

  return checkString();
}

// check if the string is valid
// true on success, false on failure
bool Model::checkString() {
  bool status = true;
  type_t prev = NONE;
  int brack_o_counter = 0;
  int brack_c_counter = 0;
  int final_close = 0;

  for (std::queue<std::pair<type_t, double> > dump = _queue; !dump.empty();
       dump.pop()) {
    type_t type = dump.front().first;
    if (type == NUM || type == X) {
      if (prev == NUM || prev == BRACK_C || prev == X) {
        status = false;
        break;
      }
    } else if (type == PLUS || type == MINUS || type == MUL || type == DIV ||
               type == MOD || type == EXP) {
      if (prev == PLUS || prev == MINUS || prev == MUL || prev == DIV ||
          prev == MOD || prev == EXP || prev == BRACK_O || prev == NONE) {
        status = false;
        break;
      }
    } else if (type == COS || type == SIN || type == TAN || type == ACOS ||
               type == ASIN || type == ATAN || type == SQRT || type == LN ||
               type == LOG) {
      if (prev == NUM || prev == BRACK_C || prev == X) {
        status = false;
        break;
      }
    } else if (type == BRACK_O) {
      if (prev == NUM || prev == BRACK_C || prev == X) {
        status = false;
        break;
      }
      brack_o_counter++;
    } else if (type == BRACK_C) {
      if (prev == PLUS || prev == MINUS || prev == MUL || prev == DIV ||
          prev == MOD || prev == EXP || prev == BRACK_O || prev == NONE) {
        status = false;
        break;
      }
      brack_c_counter++;
      if (brack_o_counter < brack_c_counter) {
        status = false;
        break;
      }
      if (brack_c_counter == brack_o_counter) final_close++;
    }
    prev = type;
  }

  if (brack_o_counter != brack_c_counter) status = false;
  if (final_close > 1) status = false;

  return status;
}
