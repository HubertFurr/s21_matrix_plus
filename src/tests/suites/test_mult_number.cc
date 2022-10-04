#include "./../test.h"

TEST(test_class, test_mul_number) {
  S21Matrix matrix1{2, 2};
  double number = 2.0;
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 1.0;
  matrix1(1, 0) = 1.0;
  matrix1(1, 1) = 1.0;

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.0);
}

TEST(test_class, test_mul_number_operator1) {
  S21Matrix matrix1{2, 2};
  double number = 2.0;
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 1.0;
  matrix1(1, 0) = 1.0;
  matrix1(1, 1) = 1.0;

  S21Matrix result = matrix1 * number;

  s21_matrix_test_helper::CheckMatrix(result, 2.0);
}

TEST(test_class, test_mul_number_operator2) {
  S21Matrix matrix1{2, 2};
  double number = 2;
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 1;
  matrix1(1, 0) = 1;
  matrix1(1, 1) = 1;

  S21Matrix result = number * matrix1;

  s21_matrix_test_helper::CheckMatrix(result, 2);
}

TEST(test_class, test_mul_number_operator3) {
  S21Matrix matrix1{2, 2};
  double number = 2;
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 1;
  matrix1(1, 0) = 1;
  matrix1(1, 1) = 1;

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.get_cols(), 2);
  EXPECT_EQ(result_check.get_rows(), 2);

  result_check(0, 0) = 8;
  result_check(0, 1) = 8;
  result_check(1, 0) = 8;
  result_check(1, 1) = 8;

  S21Matrix result = matrix1;
  result *= number;
  result *= number;
  result *= number;

  ASSERT_TRUE(result_check == result);
}

TEST(test_class, test_mul_number_const_operator) {
  const S21Matrix matrix1{2, 2};
  const double number = 2;
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  // matrix1(0, 0) = 1;
  // matrix1(0, 1) = 1;
  // matrix1(1, 0) = 1;
  // matrix1(1, 1) = 1;

  S21Matrix result = matrix1 * number;

  s21_matrix_test_helper::CheckMatrix(result, 2);
}
