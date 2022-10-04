#include "./../test.h"

TEST(test_class, test_summ) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  matrix1.SumMatrix(matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 5);
}

TEST(test_class, test_operator_add1) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  S21Matrix result;  // = matrix1 + matrix2;
  result = matrix1 + matrix2;

  s21_matrix_test_helper::CheckMatrix(result, 5);
}

TEST(test_class, test_operator_add2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  S21Matrix result = matrix2 + matrix1;

  s21_matrix_test_helper::CheckMatrix(result, 5);
}

TEST(test_class, test_operator_add3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.get_cols(), 2);
  EXPECT_EQ(result_check.get_rows(), 2);

  result_check(0, 0) = 3;
  result_check(0, 1) = 5;
  result_check(1, 0) = 7;
  result_check(1, 1) = 9;

  S21Matrix result{2, 2};
  result += matrix1;
  result += matrix2;

  ASSERT_TRUE(result_check == result);
}

TEST(test_class, test_const_operator_add1) {
  const S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  const S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  // matrix1(0, 0) = 1;
  // matrix1(0, 1) = 2;
  // matrix1(1, 0) = 3;
  // matrix1(1, 1) = 4;

  // matrix2(0, 0) = 4;
  // matrix2(0, 1) = 3;
  // matrix2(1, 0) = 2;
  // matrix2(1, 1) = 1;

  S21Matrix result;  // = matrix1 + matrix2;
  result = matrix1 + matrix2;

  s21_matrix_test_helper::CheckMatrix(result, 5);
}
