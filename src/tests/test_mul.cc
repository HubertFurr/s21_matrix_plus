#include "test.h"

TEST(test_class, test_mul) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.get_cols(), 2);
  EXPECT_EQ(result_check.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  result_check(0, 0) = 10;
  result_check(0, 1) = 13;
  result_check(1, 0) = 22;
  result_check(1, 1) = 29;

  matrix1.MulMatrix(matrix2);

  ASSERT_TRUE(matrix1 == result_check);
}

TEST(test_class, test_operator_mul1) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.get_cols(), 2);
  EXPECT_EQ(result_check.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  result_check(0, 0) = 10;
  result_check(0, 1) = 13;
  result_check(1, 0) = 22;
  result_check(1, 1) = 29;

  S21Matrix result = matrix1 * matrix2;

  ASSERT_TRUE(result_check == result);
}

TEST(test_class, test_operator_mul2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.get_cols(), 2);
  EXPECT_EQ(result_check.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  result_check(0, 0) = 11;
  result_check(0, 1) = 16;
  result_check(1, 0) = 19;
  result_check(1, 1) = 28;

  S21Matrix result = matrix2 * matrix1;

  ASSERT_TRUE(result_check == result);
}

TEST(test_class, test_const_operator_mul1) {
  const S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  const S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  const S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.get_cols(), 2);
  EXPECT_EQ(result_check.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  result_check(0, 0) = 10;
  result_check(0, 1) = 13;
  result_check(1, 0) = 22;
  result_check(1, 1) = 29;

  S21Matrix result = matrix1 * matrix2;

  ASSERT_TRUE(result_check == result);
}
