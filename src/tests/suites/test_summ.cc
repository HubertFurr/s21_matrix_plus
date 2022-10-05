#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений функции суммирования
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSumm, TestSummFunctionException1) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummFunctionException2) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummFunctionException3) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummFunctionException4) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummFunctionException5) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummFunctionException6) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummFunctionException7) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummFunctionException8) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений операций суммирования
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSumm, TestSummOperatorException1) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException2) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException3) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException4) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException5) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException6) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException7) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException8) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException9) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException10) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException11) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException12) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException13) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException14) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException15) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSumm, TestSummOperatorException16) {
  S21Matrix matrix1{2, 3};
  S21Matrix matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного суммирования функцией
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSumm, TestSumm1) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  S21Matrix matrix2{95, 99};
  EXPECT_EQ(matrix2.get_rows(), 95);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, 3.5);

  matrix1.SumMatrix(matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5 + 3.5);

  matrix2.SumMatrix(matrix1);

  s21_matrix_test_helper::CheckMatrix(matrix2, 3.5 + 2.5 + 3.5);
}

TEST(TestSumm, TestSumm2) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  S21Matrix matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, -2.5);

  matrix1.SumMatrix(matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);

  matrix2.SumMatrix(matrix1);

  s21_matrix_test_helper::CheckMatrix(matrix2, -2.5);
}

TEST(TestSumm, TestSumm3) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 3.5;
  check_matrix(0, 2) = 5.5;
  check_matrix(1, 0) = 1.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = 0.5;
  check_matrix(2, 0) = -1.0;
  check_matrix(2, 1) = -2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = -2.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = 5.0;

  matrix1.SumMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestSumm, TestSumm4) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 160245801.365;
  check_matrix(0, 1) = -9084;
  check_matrix(1, 0) = 673555.54545324;
  check_matrix(1, 1) = 145678000.588;

  matrix1.SumMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного суммирования операторами
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSumm, TestSummOperation1) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  S21Matrix matrix2{95, 99};
  EXPECT_EQ(matrix2.get_rows(), 95);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, 3.5);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 + matrix2;

  EXPECT_EQ(result.get_rows(), 95);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 2.5 + 3.5);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSumm, TestSummOperation2) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  S21Matrix matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, -2.5);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 + matrix2;

  EXPECT_EQ(result.get_rows(), 99);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 0.0);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSumm, TestSummOperation3) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 3.5;
  check_matrix(0, 2) = 5.5;
  check_matrix(1, 0) = 1.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = 0.5;
  check_matrix(2, 0) = -1.0;
  check_matrix(2, 1) = -2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = -2.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = 5.0;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 + matrix2;

  EXPECT_EQ(result.get_rows(), 4);
  EXPECT_EQ(result.get_cols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSumm, TestSummOperation4) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 160245801.365;
  check_matrix(0, 1) = -9084;
  check_matrix(1, 0) = 673555.54545324;
  check_matrix(1, 1) = 145678000.588;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 + matrix2;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSumm, TestSummOperation5) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  S21Matrix matrix2{95, 99};
  EXPECT_EQ(matrix2.get_rows(), 95);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, 3.5);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result{95, 99};

  result += matrix1;

  EXPECT_EQ(result.get_rows(), 95);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 2.5);

  result += matrix2;

  EXPECT_EQ(result.get_rows(), 95);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 2.5 + 3.5);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSumm, TestSummOperation6) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  S21Matrix matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, -2.5);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result{99, 99};

  result += matrix1;

  EXPECT_EQ(result.get_rows(), 99);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 2.5);

  result += matrix2;

  EXPECT_EQ(result.get_rows(), 99);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 0.0);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSumm, TestSummOperation7) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 3.5;
  check_matrix(0, 2) = 5.5;
  check_matrix(1, 0) = 1.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = 0.5;
  check_matrix(2, 0) = -1.0;
  check_matrix(2, 1) = -2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = -2.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = 5.0;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1;
  result += matrix2;

  EXPECT_EQ(result.get_rows(), 4);
  EXPECT_EQ(result.get_cols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSumm, TestSummOperation8) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 160245801.365;
  check_matrix(0, 1) = -9084;
  check_matrix(1, 0) = 673555.54545324;
  check_matrix(1, 1) = 145678000.588;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1;
  result += matrix2;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на const
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSumm, TestSummConst1) {
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

TEST(TestSumm, TestSummConst2) {
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

TEST(TestSumm, TestSummConst3) {
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
