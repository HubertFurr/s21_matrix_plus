#include "./../../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на const матрицы
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты создания/присваивания const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestConstructorParamsConst) {
  const S21Matrix matrix_check(4, 5);
  EXPECT_EQ(matrix_check.get_rows(), 4);
  EXPECT_EQ(matrix_check.get_cols(), 5);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConst, TestConstructorCopyConst1) {
  S21Matrix matrix_check = S21Matrix(2, 2);

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

TEST(TestConst, TestConstructorCopyConst2) {
  S21Matrix matrix_check = S21Matrix(2, 2);

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

TEST(TestConst, TestConstructorMoveConst1) {
  S21Matrix matrix_test{14, 14};
  s21_matrix_test_helper::FillMatrix(matrix_test, 2.0);

  const S21Matrix matrix_check = std::move(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 14);
  EXPECT_EQ(matrix_check.get_rows(), 14);
  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_rows(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestConst, TestConstructorMoveConst2) {
  S21Matrix matrix_test{14, 14};
  s21_matrix_test_helper::FillMatrix(matrix_test, 2.0);

  const S21Matrix matrix_check(std::move(matrix_test));

  EXPECT_EQ(matrix_check.get_cols(), 14);
  EXPECT_EQ(matrix_check.get_rows(), 14);
  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_rows(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты сравнения const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestEq1) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};
  S21Matrix matrix3{1, 1};
  S21Matrix matrix4{1, 2};
  S21Matrix matrix5{2, 1};
  S21Matrix matrix6{2, 1};
  S21Matrix matrix7{2, 2};

  matrix1(0, 0) = -1.0;
  matrix2(0, 0) = 2.0;
  matrix3(0, 0) = 2.0;

  const S21Matrix matrix1_const = matrix1;
  const S21Matrix matrix2_const = matrix2;
  const S21Matrix matrix3_const = matrix3;
  const S21Matrix matrix4_const = matrix4;
  const S21Matrix matrix5_const = matrix5;
  const S21Matrix matrix6_const = matrix6;
  const S21Matrix matrix7_const = matrix7;

  EXPECT_FALSE(matrix1_const == matrix2_const);
  EXPECT_TRUE(matrix2_const == matrix3_const);
  EXPECT_FALSE(matrix3_const == matrix4_const);
  EXPECT_FALSE(matrix4_const == matrix5_const);
  EXPECT_TRUE(matrix5_const == matrix6_const);
  EXPECT_FALSE(matrix6_const == matrix7_const);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты оператора() для const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestOperatorBracketsConst1) {
  S21Matrix matrix_check{3, 3};
  EXPECT_EQ(matrix_check.get_rows(), 3);
  EXPECT_EQ(matrix_check.get_cols(), 3);

  ASSERT_NEAR(matrix_check(0, 0), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(0, 1), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 0), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 1), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, s21_matrix_test_helper::kEpsilon);

  matrix_check(0, 0) = 1.0;
  matrix_check(0, 1) = 2.0;
  matrix_check(1, 0) = 3.0;
  matrix_check(1, 1) = 4.0;

  ASSERT_NEAR(matrix_check(0, 0), 1.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(0, 1), 2.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 0), 3.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 1), 4.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, s21_matrix_test_helper::kEpsilon);

  const S21Matrix matrix_copy = matrix_check;

  ASSERT_NEAR(matrix_copy(0, 0), 1.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(0, 1), 2.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(0, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(1, 0), 3.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(1, 1), 4.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(1, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(2, 0), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(2, 1), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(2, 2), 0.0, s21_matrix_test_helper::kEpsilon);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на сложения для const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestSumConst1) {
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

  S21Matrix matrix2_before = matrix2;
  const S21Matrix matrix2_const = matrix2;

  matrix1.SumMatrix(matrix2_const);

  s21_matrix_test_helper::CheckMatrix(matrix1, 5);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

TEST(TestConst, TestSumConst2) {
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

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  const S21Matrix matrix1_const = matrix1;
  const S21Matrix matrix2_const = matrix2;

  S21Matrix result;
  result = matrix1_const + matrix2_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(result, 5);
  EXPECT_TRUE(matrix1_before == matrix1_const);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

TEST(TestConst, TestSumConst3) {
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

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  const S21Matrix matrix1_const = matrix1;
  const S21Matrix matrix2_const = matrix2;

  S21Matrix result{2, 2};
  result += matrix1_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_TRUE(result == matrix1);

  result += matrix2_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);
  s21_matrix_test_helper::CheckMatrix(result, 5);
  EXPECT_TRUE(matrix1_before == matrix1_const);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на вычитание для const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestSubConst1) {
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

  matrix2(0, 0) = -4;
  matrix2(0, 1) = -3;
  matrix2(1, 0) = -2;
  matrix2(1, 1) = -1;

  S21Matrix matrix2_before = matrix2;
  const S21Matrix matrix2_const = matrix2;

  matrix1.SubMatrix(matrix2_const);

  s21_matrix_test_helper::CheckMatrix(matrix1, 5);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

TEST(TestConst, TestSubConst2) {
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

  matrix2(0, 0) = -4;
  matrix2(0, 1) = -3;
  matrix2(1, 0) = -2;
  matrix2(1, 1) = -1;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  const S21Matrix matrix1_const = matrix1;
  const S21Matrix matrix2_const = matrix2;

  S21Matrix result;
  result = matrix1_const - matrix2_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(result, 5);
  EXPECT_TRUE(matrix1_before == matrix1_const);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

TEST(TestConst, TestSubConst3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix1(0, 0) = 2;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 2;

  matrix2(0, 0) = -4;
  matrix2(0, 1) = -4;
  matrix2(1, 0) = -4;
  matrix2(1, 1) = -4;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  const S21Matrix matrix1_const = matrix1;
  const S21Matrix matrix2_const = matrix2;

  S21Matrix result{2, 2};
  result -= matrix1_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);
  s21_matrix_test_helper::CheckMatrix(result, -2);

  result -= matrix2_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);
  s21_matrix_test_helper::CheckMatrix(result, 2);
  EXPECT_TRUE(matrix1_before == matrix1_const);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestMulMatrix1) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  check_matrix(0, 0) = 10;
  check_matrix(0, 1) = 13;
  check_matrix(1, 0) = 22;
  check_matrix(1, 1) = 29;

  S21Matrix matrix1_const = matrix1;

  const S21Matrix result = matrix1_const * matrix2;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  ASSERT_TRUE(result == check_matrix);
}

TEST(TestConst, TestMulMatrix2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  check_matrix(0, 0) = 10;
  check_matrix(0, 1) = 13;
  check_matrix(1, 0) = 22;
  check_matrix(1, 1) = 29;

  S21Matrix matrix2_const = matrix2;

  const S21Matrix result = matrix1 * matrix2_const;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  ASSERT_TRUE(result == check_matrix);
}

TEST(TestConst, TestMulMatrix3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  check_matrix(0, 0) = 10;
  check_matrix(0, 1) = 13;
  check_matrix(1, 0) = 22;
  check_matrix(1, 1) = 29;

  const S21Matrix matrix1_const = matrix1;
  const S21Matrix matrix2_const = matrix2;

  S21Matrix result = matrix1_const * matrix2_const;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  ASSERT_TRUE(result == check_matrix);
}

TEST(TestConst, TestMulMatrix4) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  check_matrix(0, 0) = 10;
  check_matrix(0, 1) = 13;
  check_matrix(1, 0) = 22;
  check_matrix(1, 1) = 29;

  const S21Matrix matrix1_const = matrix1;
  const S21Matrix matrix2_const = matrix2;

  const S21Matrix result = matrix1_const * matrix2_const;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  ASSERT_TRUE(result == check_matrix);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения числа на const-матрицу
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestMulNumberConst1) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  S21Matrix check_matrix = matrix1;
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  double number = -9.87;

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  check_matrix(0, 0) = -1437841865.8035598;
  check_matrix(0, 1) = 44829.54;
  check_matrix(1, 0) = -6647963.62362348;
  check_matrix(1, 1) = -1437841865.80355978;

  S21Matrix matrix1_before = matrix1;
  const S21Matrix matrix1_const = matrix1;
  S21Matrix result1 = matrix1_const * number;
  S21Matrix result2 = number * matrix1_const;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result2 == check_matrix);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix1_const == matrix1_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты транспонирования const-матрицы
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestTransposeConst1) {
  S21Matrix matrix1{1, 99};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 99);

  S21Matrix result_check{99, 1};
  EXPECT_EQ(result_check.get_rows(), 99);
  EXPECT_EQ(result_check.get_cols(), 1);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.99);
  s21_matrix_test_helper::FillMatrix(result_check, 1.99);

  s21_matrix_test_helper::CheckMatrix(matrix1, 1.99);
  s21_matrix_test_helper::CheckMatrix(result_check, 1.99);

  const S21Matrix const_matrix1 = matrix1;
  const S21Matrix const_result_check = result_check;

  S21Matrix result = const_matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(result == const_result_check);
  EXPECT_TRUE(matrix1 == const_matrix1);
}

TEST(TestConst, TestTransposeConst2) {
  S21Matrix matrix1{2, 3};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 3);

  S21Matrix result_check{3, 2};
  EXPECT_EQ(result_check.get_rows(), 3);
  EXPECT_EQ(result_check.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;

  result_check(0, 0) = 1;
  result_check(1, 0) = 2;
  result_check(2, 0) = 3;
  result_check(0, 1) = 4;
  result_check(1, 1) = 5;
  result_check(2, 1) = 6;

  const S21Matrix const_matrix1 = matrix1;
  const S21Matrix const_result_check = result_check;

  S21Matrix result = const_matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(result == const_result_check);
  EXPECT_TRUE(matrix1 == const_matrix1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на определитель const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestDeterminantConst1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  matrix1(0, 0) = 1.5;

  double result_check = 1.5;
  const S21Matrix const_matrix1 = matrix1;
  double result = const_matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == const_matrix1);
}

TEST(TestConst, TestDeterminantConst2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;

  double result_check = -0.02;
  const S21Matrix const_matrix1 = matrix1;
  double result = const_matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == const_matrix1);
}

TEST(TestConst, TestDeterminantConst3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(1, 0) = 1.4;
  matrix1(1, 1) = 1.5;
  matrix1(1, 2) = 1.6;
  matrix1(2, 0) = 1.7;
  matrix1(2, 1) = 1.8;
  matrix1(2, 2) = 1.9;

  double result_check = 0.0;
  const S21Matrix const_matrix1 = matrix1;
  double result = const_matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == const_matrix1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты алгебраических дополнений для const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestCalcComplementsConst1) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.get_cols(), 2);
  EXPECT_EQ(result_check.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  result_check(0, 0) = 4;
  result_check(0, 1) = -3;
  result_check(1, 0) = -2;
  result_check(1, 1) = 1;

  const S21Matrix const_matrix1 = matrix1;
  const S21Matrix const_result_check = result_check;

  const S21Matrix result = const_matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(result == const_result_check);
  EXPECT_TRUE(matrix1 == const_matrix1);
}

TEST(TestConst, TestCalcComplementsConst2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.get_cols(), 2);
  EXPECT_EQ(result_check.get_rows(), 2);

  matrix1(0, 0) = 12.452;
  matrix1(0, 1) = 3.34245;
  matrix1(1, 0) = 3.356;
  matrix1(1, 1) = 3.543;

  result_check(0, 0) = 3.543;
  result_check(0, 1) = -3.356;
  result_check(1, 0) = -3.34245;
  result_check(1, 1) = 12.452;

  const S21Matrix const_matrix1 = matrix1;
  const S21Matrix const_result_check = result_check;

  const S21Matrix result = const_matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(result == const_result_check);
  EXPECT_TRUE(matrix1 == const_matrix1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на обратную матрицу от const-матрицы
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestInverseConst1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  matrix1(0, 0) = 1.5;

  const S21Matrix matrix_const = matrix1;

  s21_matrix_test_helper::TestInverse(matrix_const);
}

TEST(TestConst, TestInverseConst2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;

  const S21Matrix matrix_const = matrix1;

  s21_matrix_test_helper::TestInverse(matrix_const);
}

TEST(TestConst, TestInverseConst3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = -7.00037610391155;
  matrix1(1, 0) = -6.32839397341013;
  matrix1(2, 0) = 10.222164043691;
  matrix1(0, 1) = -9.82599597726949;
  matrix1(1, 1) = 3.03237457247451;
  matrix1(2, 1) = 0.587724786484614;
  matrix1(0, 2) = 8.27683520526625;
  matrix1(1, 2) = -4.28063526446931;
  matrix1(2, 2) = -6.93227237439714;

  const S21Matrix matrix_const = matrix1;

  s21_matrix_test_helper::TestInverse(matrix_const);
}
