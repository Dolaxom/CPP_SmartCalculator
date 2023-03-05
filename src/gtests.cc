#include <gtest/gtest.h>

#include "model.h"

using namespace s21;

Model model;

TEST(SC, test_1) {
  double result = model.Calculate(
      "-(1+3*(5%3+100))/50/1*20+-(50^2*(5+3^2)%(3*2)+31*20/"
      "(10*-5^(2+1)))+39^2*48*10*123-50-10");
  ASSERT_EQ(result, 89799655.696);
}

TEST(SC, test_1_with_spaces) {
  double result = model.Calculate(
      "-(1+3 *(5%3+ 100))/50 / 1*20+-( 50^2*(5+3^2  "
      ")%(3*2)+31*20/(10*-5^(2+1)) )+39^2*48*10*123-50-10");
  ASSERT_EQ(result, 89799655.696);
}

TEST(SC, test_2_long_values) {
  double result = model.Calculate("15120.150+4961254.9271/2.5^2");
  ASSERT_EQ(result, 808920.938336);
}

TEST(SC, test_3_functions) {
  double result = model.Calculate(
      "acos(-0.5)+asin(-0.5)+atan(0.1)*cos(30)*sin(20)*tan(45)");
  ASSERT_EQ(result, 1.593531);
}

TEST(SC, test_4_log_ln_sqrt) {
  double result =
      model.Calculate("(ln(50)+100)%(2+2.5)+(log(100)*20)^(2+2)+sqrt(25)");
  ASSERT_EQ(result, 2560005.412023);
}

TEST(SC, test_5_unary_minis) {
  double result = model.Calculate("-(cos(20)+-10)%2");
  ASSERT_EQ(result, 1.591918);
}

TEST(SC, test_6_unary_plus) {
  double result = model.Calculate("5++5++135++(10++10)");
  ASSERT_EQ(result, 165);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
