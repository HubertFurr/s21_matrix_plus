#include "test.h"

TEST(test_class, test_mult_number) {
  S21Matrix matrix1{2, 2};
  double number = 2;
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 1;
  matrix1(1, 0) = 1;
  matrix1(1, 1) = 1;

  matrix1.MulNumber(number);

  test_matrix_value(matrix1, 2);
}

TEST(test_class, test_mult_number_operator1) {
  S21Matrix matrix1{2, 2};
  double number = 2;
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 1;
  matrix1(1, 0) = 1;
  matrix1(1, 1) = 1;

  S21Matrix result = matrix1 * number;

  test_matrix_value(result, 2);
}

TEST(test_class, test_mult_number_operator2) {
  S21Matrix matrix1{2, 2};
  double number = 2;
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 1;
  matrix1(1, 0) = 1;
  matrix1(1, 1) = 1;

  S21Matrix result = number * matrix1;

  test_matrix_value(result, 2);
}

TEST(test_class, test_mult_number_const_operator) {
  const S21Matrix matrix1{2, 2};
  const double number = 2;
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 1;
  matrix1(1, 0) = 1;
  matrix1(1, 1) = 1;

  S21Matrix result = matrix1 * number;

  test_matrix_value(result, 2);
}
