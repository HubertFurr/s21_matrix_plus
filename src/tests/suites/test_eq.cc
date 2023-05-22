#include "./../test.h"

TEST(TestEq, TestEq0) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};

  matrix1(0, 0) = -1;
  matrix2(0, 0) = 2;
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq00) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};

  matrix1(0, 0) = 1;
  matrix2(0, 0) = -2;
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq1) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result2);
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(1, 0) = 3;
  matrix2(1, 1) = 4;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(TestEq, TestEq3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 2.0);
}

TEST(TestEq, TestEq4) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{3, 3};
  EXPECT_EQ(matrix2.get_cols(), 3);
  EXPECT_EQ(matrix2.get_rows(), 3);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result1);
  EXPECT_FALSE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result2);
  EXPECT_FALSE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 2.0);
}

TEST(TestEq, TestEq04) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result1);
  EXPECT_FALSE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result2);
  EXPECT_FALSE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 2.0);
}

TEST(TestEq, TestEq5) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  S21Matrix matrix2{1, 1};
  EXPECT_EQ(matrix2.get_cols(), 1);
  EXPECT_EQ(matrix2.get_rows(), 1);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  matrix1(0, 0) = 2.5;
  matrix2(0, 0) = 2.5;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5);
  s21_matrix_test_helper::CheckMatrix(matrix2, 2.5);

  matrix1(0, 0) = 2.5000001;
  matrix2(0, 0) = 2.5;

  bool result3 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result3);
  EXPECT_TRUE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5);
  s21_matrix_test_helper::CheckMatrix(matrix2, 2.5);
}

TEST(TestEq, TestEq6) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  matrix2(0, 0) = 0.0000001;

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);

  matrix1(0, 0) = 0.0000001;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix2, 0.0);
}
