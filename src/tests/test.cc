#include "test.h"

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

namespace {

TEST(Calculate, Basic) {
  Model model("1+x");
  EXPECT_EQ(model.Calculate(2), 3);
}

TEST(Calculate, Basic2) {
  Model model("1+1 - 12 * (5^3) ");
  EXPECT_EQ(model.Calculate(0), -1498.0);
}

TEST(Calculate, Basic3) {
  Model model1("1-(2-(3-(4/8)*(-1-7))-3) ");
  EXPECT_EQ(model1.Calculate(),
            1.0 - (2.0 - (3.0 - (4.0 / 8.0) * (-1.0 - 7.0)) - 3.0));
}

TEST(Calculate, Basic4) {
  Model model1("1e-2");
  EXPECT_EQ(model1.Calculate(), 0.01);
}

TEST(Calculate, TrigFunctions) {
  Model model("sin(x)+cos(x)-tan(x)");
  double expected = sin(2) + cos(2) - tan(2);
  EXPECT_DOUBLE_EQ(model.Calculate(2), expected);
}

TEST(Calculate, Exponentiation) {
  Model model("x^2");
  EXPECT_DOUBLE_EQ(model.Calculate(3), 9);
}

TEST(Calculate, SquareRoot) {
  Model model("sqrt(x)");
  EXPECT_DOUBLE_EQ(model.Calculate(4), 2);
}

TEST(Calculate, Logarithm) {
  Model model("log(x)");
  EXPECT_DOUBLE_EQ(model.Calculate(100), 2);
}

TEST(Calculate, Mod) {
  Model model("10 % 2");
  EXPECT_DOUBLE_EQ(model.Calculate(), fmod(10, 2));
}

TEST(Calculate, PowerFunctions) {
  Model model("x^2 + sqrt(x)");
  double expected = pow(3.5, 2) + sqrt(3.5);
  EXPECT_DOUBLE_EQ(model.Calculate(3.5), expected);
}

TEST(Calculate, LogarithmicFunctions) {
  Model model("ln(x) + log(x)");
  double expected = log(2.7) + log10(2.7);
  EXPECT_DOUBLE_EQ(model.Calculate(2.7), expected);
}

TEST(Calculate, DivisionByZero) {
  Model model("1 / (x - 2)");
  EXPECT_TRUE(std::isnan(model.Calculate(2)));
}

TEST(Calculate, NegativeRoot) {
  Model model("sqrt(-1)");
  EXPECT_TRUE(std::isnan(model.Calculate()));
}

TEST(Calculate, InvalidExpression) {
  EXPECT_THROW(Model model("1 + unknown(x)"), std::invalid_argument);
}

TEST(Calculate, InvalidExpression1) {
  EXPECT_THROW(Model model("1+1)"), std::invalid_argument);
}

TEST(Calculate, InvalidExpression2) {
  EXPECT_THROW(Model model(")1+1 - 12 * (5^3) "), std::invalid_argument);
}

TEST(Calculate, InvalidExpression3) {
  EXPECT_THROW(Model model("(23_32-3)"), std::invalid_argument);
}

TEST(Calculate, InvalidExpression4) {
  EXPECT_THROW(Model model(")1+2("), std::invalid_argument);
}

TEST(Calculate, InvalidExpression5) {
  EXPECT_THROW(Model model("1.1.1+1"), std::invalid_argument);
}

TEST(Calculate, InvalidExpression6) {
  EXPECT_THROW(Model model("1+1-12*(5^3"), std::invalid_argument);
}

TEST(Calculate, InvalidExpression7) {
  EXPECT_THROW(Model model("(12))+(12"), std::invalid_argument);
}

TEST(Calculate, Spizdil) {
  EXPECT_ANY_THROW(Model model("(1+2"));
  EXPECT_ANY_THROW(Model model("13 13"));
  EXPECT_ANY_THROW(Model model("sin(x)) - f"));
  EXPECT_ANY_THROW(Model model("(1+2))2"));
  EXPECT_ANY_THROW(Model model("s i n (x))"));
  EXPECT_ANY_THROW(Model model("12+3))"));
  EXPECT_ANY_THROW(Model model("1+(2+(-3)"));
  EXPECT_ANY_THROW(Model model("cossinp"));
  EXPECT_ANY_THROW(Model model("1-(2-(3.3.3)-4)"));
  EXPECT_ANY_THROW(Model model("sin(X^(cos(x))"));
  EXPECT_ANY_THROW(Model model("1e3.4"));
  EXPECT_ANY_THROW(Model model("sinnnn"));
}

}  // namespace