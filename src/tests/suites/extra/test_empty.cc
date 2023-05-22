#include <utility>

#include "./../../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты для пустых матриц (m×0 и 0×n)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты конструкторов/присваиваний
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConstructor, TestConstructor1) {
  S21Matrix matrix(0, 3);

  EXPECT_EQ(matrix.get_rows(), 0);
  EXPECT_EQ(matrix.get_cols(), 3);

  S21Matrix matrix_copy = matrix;
  EXPECT_EQ(matrix_copy.get_rows(), 0);
  EXPECT_EQ(matrix_copy.get_cols(), 3);
  EXPECT_TRUE(matrix_copy == matrix);

  S21Matrix matrix1(3, 3);
  matrix1 = matrix;
  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_TRUE(matrix1 == matrix);

  S21Matrix matrix_move = std::move(matrix);
  EXPECT_EQ(matrix_move.get_rows(), 0);
  EXPECT_EQ(matrix_move.get_cols(), 3);
  EXPECT_TRUE(matrix_move == matrix_copy);

  S21Matrix matrix2(3, 3);
  matrix2 = std::move(matrix_copy);
  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 3);
  EXPECT_TRUE(matrix2 == matrix_move);
}

TEST(TestConstructor, TestConstructor2) {
  S21Matrix matrix(3, 0);

  EXPECT_EQ(matrix.get_rows(), 3);
  EXPECT_EQ(matrix.get_cols(), 0);

  S21Matrix matrix_copy = matrix;
  EXPECT_EQ(matrix_copy.get_rows(), 3);
  EXPECT_EQ(matrix_copy.get_cols(), 0);
  EXPECT_TRUE(matrix_copy == matrix);

  S21Matrix matrix1(3, 3);
  matrix1 = matrix;
  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_TRUE(matrix1 == matrix);

  S21Matrix matrix_move = std::move(matrix);
  EXPECT_EQ(matrix_move.get_rows(), 3);
  EXPECT_EQ(matrix_move.get_cols(), 0);
  EXPECT_TRUE(matrix_move == matrix_copy);

  S21Matrix matrix2(3, 3);
  matrix2 = std::move(matrix_copy);
  EXPECT_EQ(matrix2.get_rows(), 3);
  EXPECT_EQ(matrix2.get_cols(), 0);
  EXPECT_TRUE(matrix2 == matrix_move);
}

TEST(TestConstructor, TestConstructor3) {
  S21Matrix matrix(0, 0);

  EXPECT_EQ(matrix.get_rows(), 0);
  EXPECT_EQ(matrix.get_cols(), 0);

  S21Matrix matrix_copy = matrix;
  EXPECT_EQ(matrix_copy.get_rows(), 0);
  EXPECT_EQ(matrix_copy.get_cols(), 0);
  EXPECT_TRUE(matrix_copy == matrix);

  S21Matrix matrix1(3, 3);
  matrix1 = matrix;
  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_TRUE(matrix1 == matrix);

  S21Matrix matrix_move = std::move(matrix);
  EXPECT_EQ(matrix_move.get_rows(), 0);
  EXPECT_EQ(matrix_move.get_cols(), 0);
  EXPECT_TRUE(matrix_move == matrix_copy);

  S21Matrix matrix2(3, 3);
  matrix2 = std::move(matrix_copy);
  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 0);
  EXPECT_TRUE(matrix2 == matrix_move);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты равенства
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestEq1) {
  EXPECT_TRUE(S21Matrix(3, 0) == S21Matrix(3, 0));
  EXPECT_TRUE(S21Matrix(1, 0) == S21Matrix(1, 0));
  EXPECT_TRUE(S21Matrix(0, 1) == S21Matrix(0, 1));
  EXPECT_TRUE(S21Matrix(0, 3) == S21Matrix(0, 3));
  EXPECT_FALSE(S21Matrix(0, 3) == S21Matrix(3, 0));
  EXPECT_FALSE(S21Matrix(1, 0) == S21Matrix(0, 1));
  EXPECT_FALSE(S21Matrix(0, 3) == S21Matrix(0, 2));
  EXPECT_FALSE(S21Matrix(2, 0) == S21Matrix(1, 0));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты мутаторов (сеттеров)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestMutators1) {
  S21Matrix test_matrix{2, 2};
  S21Matrix check{0, 2};

  EXPECT_NO_THROW(test_matrix.set_rows(0));
  EXPECT_TRUE(test_matrix == check);
}

TEST(TestEmpty, TestMutators2) {
  S21Matrix test_matrix{2, 2};
  S21Matrix check{2, 0};

  EXPECT_NO_THROW(test_matrix.set_cols(0));
  EXPECT_TRUE(test_matrix == check);
}

TEST(TestEmpty, TestMutators3) {
  S21Matrix test_matrix(2, 3);
  S21Matrix check{0, 3};

  EXPECT_NO_THROW(test_matrix.set_rows(0));
  EXPECT_TRUE(test_matrix == check);
}

TEST(TestEmpty, TestMutators4) {
  S21Matrix test_matrix(2, 3);
  S21Matrix check{2, 0};

  EXPECT_NO_THROW(test_matrix.set_cols(0));
  EXPECT_TRUE(test_matrix == check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты сложения
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestSum1) {
  S21Matrix matrix1(3, 0);
  S21Matrix matrix2(3, 0);
  S21Matrix matrix1_copy = matrix1;
  S21Matrix matrix2_copy = matrix2;

  S21Matrix result1 = matrix1 + matrix2;
  EXPECT_TRUE(result1 == S21Matrix(3, 0));

  S21Matrix result2 = matrix2 + matrix1;
  EXPECT_TRUE(result2 == S21Matrix(3, 0));

  matrix1_copy += matrix2_copy;
  EXPECT_TRUE(matrix1_copy == S21Matrix(3, 0));

  matrix2_copy += matrix1;
  EXPECT_TRUE(matrix2_copy == S21Matrix(3, 0));
}

TEST(TestEmpty, TestSum2) {
  S21Matrix matrix1(0, 3);
  S21Matrix matrix2(0, 3);
  S21Matrix matrix1_copy = matrix1;
  S21Matrix matrix2_copy = matrix2;

  S21Matrix result1 = matrix1 + matrix2;
  EXPECT_TRUE(result1 == S21Matrix(0, 3));

  S21Matrix result2 = matrix2 + matrix1;
  EXPECT_TRUE(result2 == S21Matrix(0, 3));

  matrix1_copy += matrix2_copy;
  EXPECT_TRUE(matrix1_copy == S21Matrix(0, 3));

  matrix2_copy += matrix1;
  EXPECT_TRUE(matrix2_copy == S21Matrix(0, 3));
}

TEST(TestEmpty, TestSum3) {
  S21Matrix matrix1(0, 2);
  S21Matrix matrix2(3, 0);

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix1 += matrix2);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты вычитания
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestSub1) {
  S21Matrix matrix1(3, 0);
  S21Matrix matrix2(3, 0);
  S21Matrix matrix1_copy = matrix1;
  S21Matrix matrix2_copy = matrix2;

  S21Matrix result1 = matrix1 - matrix2;
  EXPECT_TRUE(result1 == S21Matrix(3, 0));

  S21Matrix result2 = matrix2 - matrix1;
  EXPECT_TRUE(result2 == S21Matrix(3, 0));

  matrix1_copy -= matrix2_copy;
  EXPECT_TRUE(matrix1_copy == S21Matrix(3, 0));

  matrix2_copy -= matrix1;
  EXPECT_TRUE(matrix2_copy == S21Matrix(3, 0));
}

TEST(TestEmpty, TestSub2) {
  S21Matrix matrix1(0, 3);
  S21Matrix matrix2(0, 3);
  S21Matrix matrix1_copy = matrix1;
  S21Matrix matrix2_copy = matrix2;

  S21Matrix result1 = matrix1 - matrix2;
  EXPECT_TRUE(result1 == S21Matrix(0, 3));

  S21Matrix result2 = matrix2 - matrix1;
  EXPECT_TRUE(result2 == S21Matrix(0, 3));

  matrix1_copy -= matrix2_copy;
  EXPECT_TRUE(matrix1_copy == S21Matrix(0, 3));

  matrix2_copy -= matrix1;
  EXPECT_TRUE(matrix2_copy == S21Matrix(0, 3));
}

TEST(TestEmpty, TestSub3) {
  S21Matrix matrix1(0, 2);
  S21Matrix matrix2(3, 0);

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix1 -= matrix2);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestMulMatrix1) {
  S21Matrix matrix1(3, 0);
  S21Matrix matrix2(0, 3);
  S21Matrix matrix1_copy = matrix1;
  S21Matrix matrix2_copy = matrix2;

  S21Matrix result1 = matrix1 * matrix2;
  EXPECT_TRUE(result1 == S21Matrix(3, 3));

  S21Matrix result2 = matrix2 * matrix1;
  EXPECT_TRUE(result2 == S21Matrix(0, 0));

  matrix1_copy *= matrix2_copy;
  EXPECT_TRUE(matrix1_copy == S21Matrix(3, 3));

  matrix2_copy *= matrix1;
  EXPECT_TRUE(matrix2_copy == S21Matrix(0, 0));
}

TEST(TestEmpty, TestMulMatrix2) {
  S21Matrix matrix1(0, 2);
  S21Matrix matrix2(3, 0);

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix1 *= matrix2);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения на число
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestMulNumber1) {
  S21Matrix matrix1(1, 0);
  S21Matrix matrix2(1, 0);
  S21Matrix check(1, 0);

  S21Matrix result1 = matrix1 * 2.0;
  EXPECT_TRUE(result1 == check);

  S21Matrix result2 = 2.0 * matrix1;
  EXPECT_TRUE(result2 == check);

  matrix2 *= 2.0;
  EXPECT_TRUE(matrix2 == check);
}

TEST(TestEmpty, TestMulNumber2) {
  S21Matrix matrix1(0, 1);
  S21Matrix matrix2(0, 1);
  S21Matrix check(0, 1);

  S21Matrix result1 = matrix1 * 2.0;
  EXPECT_TRUE(result1 == check);

  S21Matrix result2 = 2.0 * matrix1;
  EXPECT_TRUE(result2 == check);

  matrix2 *= 2.0;
  EXPECT_TRUE(matrix2 == check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты транспонирования
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestTranspose1) {
  S21Matrix matrix(1, 0);
  S21Matrix result = matrix.Transpose();
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 1);
  EXPECT_TRUE(result == S21Matrix(0, 1));
}

TEST(TestEmpty, TestTranspose2) {
  S21Matrix matrix(0, 1);
  S21Matrix result = matrix.Transpose();
  EXPECT_EQ(result.get_rows(), 1);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(result == S21Matrix(1, 0));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на определитель
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestDeterminant1) {
  S21Matrix test_matrix(1, 0);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestEmpty, TestDeterminant2) {
  S21Matrix test_matrix(0, 1);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты алгебраических дополнений для default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestCalcComplements1) {
  S21Matrix test_matrix(1, 0);
  S21Matrix check_matrix = test_matrix;
  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == check_matrix);
}

TEST(TestEmpty, TestCalcComplements2) {
  S21Matrix test_matrix(0, 1);
  S21Matrix check_matrix = test_matrix;
  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == check_matrix);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на обратную матрицу для default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestInverse1) {
  S21Matrix test_matrix(1, 0);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestEmpty, TestInverse2) {
  S21Matrix test_matrix(0, 1);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}
