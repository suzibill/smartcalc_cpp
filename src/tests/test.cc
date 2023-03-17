#include "test.h"

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

namespace {

// TEST(Calculate, Basic) {
//   Model model("1+x");
//   EXPECT_EQ(model.Calculate(2), 3);
// }

// TEST(Calculate, Basic2) {
//   Model model("1+1 - 12 * (5^3) ");
//   EXPECT_EQ(model.Calculate(0), -1498.0);
// }

TEST(Calculate, TrigFunctions) {
  Model model("sin(x)+cos(x)-tan(x)");
  double expected = sin(2) + cos(2) - tan(2);
  EXPECT_DOUBLE_EQ(model.Calculate(2), expected);
}

// TEST(Calculate, Exponentiation) {
//   Model model("x^2");
//   EXPECT_DOUBLE_EQ(model.Calculate(3), 9);
// }

// TEST(Calculate, SquareRoot) {
//   Model model("sqrt(x)");
//   EXPECT_DOUBLE_EQ(model.Calculate(4), 2);
// }

// TEST(Calculate, Logarithm) {
//   Model model("log(x)");
//   EXPECT_DOUBLE_EQ(model.Calculate(100), 2);
// }

// // TEST(Calculate, WrongExpression) {
// //   Model model("1+1-12*(5^3");
// //   EXPECT_DOUBLE_EQ(model.Calculate(100), 2);
// // }

// TEST(Calculate, PowerFunctions) {
//   Model model("x^2 + sqrt(x)");
//   double expected = pow(3.5, 2) + sqrt(3.5);
//   EXPECT_DOUBLE_EQ(model.Calculate(3.5), expected);
// }

// TEST(Calculate, LogarithmicFunctions) {
//   Model model("ln(x) + log(x)");
//   double expected = log(2.7) + log10(2.7);
//   EXPECT_DOUBLE_EQ(model.Calculate(2.7), expected);
// }

// TEST(Calculate, DivisionByZero) {
//   Model model("1 / (x - 2)");
//   EXPECT_TRUE(std::isnan(model.Calculate(2)));
// }

// TEST(Calculate, InvalidFunction) {
//   EXPECT_THROW(
//       {
//         try {
//           Model model("1 + unknown(x)");
//         } catch (std::invalid_argument &e) {
//           std::cout << e.what() << std::endl;
//           throw;
//         }
//       },
//       std::invalid_argument

//   );
// }

}  // namespace