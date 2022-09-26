#include "test.h"

TEST(test_class, basic_constructor) {
  S21Matrix M;
  EXPECT_EQ(M.get_cols(), 3);
  EXPECT_EQ(M.get_rows(), 3);
}

TEST(test_class, basic_constructor_const) {
  const S21Matrix M;
  EXPECT_EQ(M.get_cols(), 3);
  EXPECT_EQ(M.get_rows(), 3);
}

TEST(test_class, params_constructor) {
  S21Matrix M(5, 5);
  EXPECT_EQ(M.get_cols(), 5);
  EXPECT_EQ(M.get_rows(), 5);
}

TEST(test_class, params_constructor_const) {
  // Способы инициализации - https://habr.com/ru/company/jugru/blog/469465/
  //   const S21Matrix M(5, 5);
  //   const S21Matrix M = S21Matrix(5, 5);
  auto M = S21Matrix(5, 5);
  EXPECT_EQ(M.get_cols(), 5);
  EXPECT_EQ(M.get_rows(), 5);
}
