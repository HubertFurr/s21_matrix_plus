#include "./../test.h"

TEST(TestConstructor, TestConstructorBasic) {
  S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.get_rows(), 3);
  EXPECT_EQ(matrix_check.get_cols(), 3);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConstructor, TestConstructorBasicConst) {
  const S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.get_rows(), 3);
  EXPECT_EQ(matrix_check.get_cols(), 3);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConstructor, TestConstructorParams1) {
  S21Matrix matrix_check(5, 4);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_check.get_cols(), 4);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConstructor, TestConstructorParams2) {
  S21Matrix matrix_check(999, 1999);
  EXPECT_EQ(matrix_check.get_rows(), 999);
  EXPECT_EQ(matrix_check.get_cols(), 1999);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConstructor, TestConstructorParamsConst) {
  const S21Matrix matrix_check(4, 5);
  EXPECT_EQ(matrix_check.get_rows(), 4);
  EXPECT_EQ(matrix_check.get_cols(), 5);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConstructor, TestConstructorCopy1) {
  S21Matrix matrix_check = S21Matrix(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  S21Matrix matrix_copy = matrix_check;

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 4.0);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 4.0);
}

TEST(TestConstructor, TestConstructorCopy2) {
  S21Matrix matrix_check = S21Matrix(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  S21Matrix matrix_copy(matrix_check);

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 4.0);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 4.0);
}

TEST(TestConstructor, TestConstructorCopyConst1) {
  const S21Matrix matrix_check = S21Matrix(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  const S21Matrix matrix_copy = matrix_check;

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 4.0);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 4.0);
}

TEST(TestConstructor, TestConstructorCopyConst2) {
  const S21Matrix matrix_check = S21Matrix(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  const S21Matrix matrix_copy(matrix_check);

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 4.0);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 4.0);
}

TEST(TestConstructor, TestConstructorMove1) {
  S21Matrix matrix_check =
      s21_matrix_test_helper::TestMoveConstructor(S21Matrix{5, 5});

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConstructor, TestConstructorMove2) {
  S21Matrix matrix_test{14, 14};
  s21_matrix_test_helper::FillMatrix(matrix_test, 2.0);

  S21Matrix matrix_check = std::move(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 14);
  EXPECT_EQ(matrix_check.get_rows(), 14);
  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_rows(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestConstructor, TestConstructorMoveConst) {
  S21Matrix matrix_test{14, 14};
  s21_matrix_test_helper::FillMatrix(matrix_test, 2.0);

  const S21Matrix matrix_check = std::move(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 14);
  EXPECT_EQ(matrix_check.get_rows(), 14);
  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_rows(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}
