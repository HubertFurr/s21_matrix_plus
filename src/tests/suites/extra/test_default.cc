#include <utility>

#include "./../../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты для default-матриц (0x0)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты создания default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestConstructorBasicConst1) {
  const S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.get_rows(), 0);
  EXPECT_EQ(matrix_check.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);

  S21Matrix matrix_copy{matrix_check};

  EXPECT_EQ(matrix_copy.get_rows(), 0);
  EXPECT_EQ(matrix_copy.get_cols(), 0);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 0.0);

  // Интересный факт - в данном случае используется конструктор копирования
  S21Matrix matrix_move{std::move(matrix_check)};
  EXPECT_EQ(matrix_move.get_rows(), 0);
  EXPECT_EQ(matrix_move.get_cols(), 0);
  s21_matrix_test_helper::CheckMatrix(matrix_move, 0.0);
}

TEST(TestDefault, TestConstructorBasic1) {
  S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.get_rows(), 0);
  EXPECT_EQ(matrix_check.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);

  S21Matrix matrix_copy{matrix_check};

  EXPECT_EQ(matrix_copy.get_rows(), 0);
  EXPECT_EQ(matrix_copy.get_cols(), 0);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 0.0);

  S21Matrix matrix_move{std::move(matrix_check)};
  EXPECT_EQ(matrix_move.get_rows(), 0);
  EXPECT_EQ(matrix_move.get_cols(), 0);
  s21_matrix_test_helper::CheckMatrix(matrix_move, 0.0);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты присваивания default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestAssignmentCopy1) {
  S21Matrix matrix_test{5, 5};
  S21Matrix matrix_check;

  EXPECT_EQ(matrix_test.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 0);
  EXPECT_EQ(matrix_check.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_test, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);

  matrix_test = matrix_check;

  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_cols(), 0);
  EXPECT_EQ(matrix_check.get_rows(), 0);
  EXPECT_EQ(matrix_check.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_test, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestDefault, TestAssignmentMove1) {
  S21Matrix matrix_test{5, 5};
  S21Matrix matrix_check;

  EXPECT_EQ(matrix_test.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 0);
  EXPECT_EQ(matrix_check.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_test, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);

  matrix_test = std::move(matrix_check);

  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_test, 0.0);
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты равенства default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestEq1) {
  S21Matrix matrix1;
  S21Matrix matrix2;

  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(TestDefault, TestEq2) {
  S21Matrix matrix1;
  S21Matrix matrix2{1, 1};

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestDefault, TestEq3) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2;

  EXPECT_FALSE(matrix1 == matrix2);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты мутаторов для default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestMutators1) {
  S21Matrix test_matrix;

  test_matrix.set_cols(1);
  EXPECT_TRUE(test_matrix == S21Matrix(0, 1));
  test_matrix.set_rows(1);
  EXPECT_TRUE(test_matrix == S21Matrix(1, 1));
}

TEST(TestDefault, TestMutators2) {
  S21Matrix test_matrix;

  EXPECT_NO_THROW(test_matrix.set_rows(1));
  EXPECT_TRUE(test_matrix == S21Matrix(1, 0));
  test_matrix.set_cols(1);
  EXPECT_TRUE(test_matrix == S21Matrix(1, 1));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты сложения default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestSum1) {
  S21Matrix matrix1;
  S21Matrix matrix2;

  S21Matrix result = matrix2 + matrix1;
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(result == S21Matrix(0, 0));

  matrix1 += matrix2;
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(matrix1 == S21Matrix(0, 0));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты вычитания default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestSub1) {
  S21Matrix matrix1;
  S21Matrix matrix2;

  S21Matrix result = matrix2 - matrix1;
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(result == S21Matrix(0, 0));

  matrix1 -= matrix2;
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(matrix1 == S21Matrix(0, 0));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestMulMatrix1) {
  S21Matrix matrix1;
  S21Matrix matrix2;
  S21Matrix check;

  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 0);

  S21Matrix result = matrix1 * matrix2;

  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(result == check);

  matrix1 *= matrix2;

  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_TRUE(matrix1 == check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения default-матриц на число
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestMulNumber1) {
  S21Matrix matrix1;
  S21Matrix matrix2;
  S21Matrix check;

  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 0);

  S21Matrix result1 = matrix1 * 2.0;

  EXPECT_EQ(result1.get_rows(), 0);
  EXPECT_EQ(result1.get_cols(), 0);
  EXPECT_TRUE(result1 == check);

  S21Matrix result2 = 2.0 * matrix1;

  EXPECT_EQ(result2.get_rows(), 0);
  EXPECT_EQ(result2.get_cols(), 0);
  EXPECT_TRUE(result2 == check);

  matrix2 *= 2.0;

  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 0);
  EXPECT_TRUE(matrix2 == check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты транспонирования default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestTranspose1) {
  S21Matrix matrix;
  S21Matrix result = matrix.Transpose();
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(result == S21Matrix(0, 0));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на определитель default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestDeterminant1) {
  S21Matrix matrix;

  double result_check = 1.0;
  S21Matrix matrix_before = matrix;
  double result = matrix.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix == matrix_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты алгебраических дополнений для default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestCalcComplements1) {
  S21Matrix test_matrix;
  S21Matrix matrix_before = test_matrix;

  S21Matrix result = test_matrix.CalcComplements();
  EXPECT_TRUE(matrix_before == result);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на обратную матрицу для default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestInverse1) {
  S21Matrix matrix;
  EXPECT_EQ(matrix.get_cols(), 0);
  EXPECT_EQ(matrix.get_rows(), 0);

  s21_matrix_test_helper::TestInverse(matrix);
}
