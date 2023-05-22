#include "./../classes/random_suites.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного умножения на число функцией
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMulNumber, TestMulNumber1) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  double number = 2.0;

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5 * number);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5 * number * number);
}

TEST(TestMulNumber, TestMulNumber2) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  double number = -2.5;

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5 * number);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5 * number * number);
}

TEST(TestMulNumber, TestMulNumber3) {
  S21Matrix matrix1{199, 1};
  EXPECT_EQ(matrix1.get_rows(), 199);
  EXPECT_EQ(matrix1.get_cols(), 1);

  double number = -2.999;

  s21_matrix_test_helper::FillMatrix(matrix1, -1.999);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, -1.999 * number);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, -1.999 * number * number);
}

TEST(TestMulNumber, TestMulNumber4) {
  S21Matrix matrix1{1, 199};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 199);

  double number = 2.5999;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.5999);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 1.5999 * number);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 1.5999 * number * number);
}

TEST(TestMulNumber, TestMulNumber5) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  S21Matrix check_matrix = matrix1;
  EXPECT_EQ(check_matrix.get_rows(), 4);
  EXPECT_EQ(check_matrix.get_cols(), 3);

  double number = 1.99;

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

  check_matrix(0, 0) = 2.985;
  check_matrix(0, 1) = 4.975;
  check_matrix(0, 2) = 6.965;
  check_matrix(1, 0) = -2.985;
  check_matrix(1, 1) = -4.975;
  check_matrix(1, 2) = -6.965;
  check_matrix(2, 0) = 0.0;
  check_matrix(2, 1) = 0.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 1.99;
  check_matrix(3, 1) = 1.99;
  check_matrix(3, 2) = 1.99;

  matrix1.MulNumber(number);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestMulNumber, TestMulNumber6) {
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

  matrix1.MulNumber(number);

  EXPECT_TRUE(matrix1 == check_matrix);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного умножения на число операторами
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMulNumber, TestMulNumberOperator1) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  double number = 2.0;

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result2 = number * matrix1;
  S21Matrix result3 = matrix1;
  result3 *= number;

  s21_matrix_test_helper::CheckMatrix(result1, 2.5 * number);
  s21_matrix_test_helper::CheckMatrix(result2, 2.5 * number);
  s21_matrix_test_helper::CheckMatrix(result3, 2.5 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator2) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  double number = -2.5;

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result2 = number * matrix1;
  S21Matrix result3 = matrix1;
  result3 *= number;

  s21_matrix_test_helper::CheckMatrix(result1, 2.5 * number);
  s21_matrix_test_helper::CheckMatrix(result2, 2.5 * number);
  s21_matrix_test_helper::CheckMatrix(result3, 2.5 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator3) {
  S21Matrix matrix1{199, 1};
  EXPECT_EQ(matrix1.get_rows(), 199);
  EXPECT_EQ(matrix1.get_cols(), 1);

  double number = -2.999;

  s21_matrix_test_helper::FillMatrix(matrix1, -1.999);
  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result2 = number * matrix1;
  S21Matrix result3 = matrix1;
  result3 *= number;

  s21_matrix_test_helper::CheckMatrix(result1, -1.999 * number);
  s21_matrix_test_helper::CheckMatrix(result2, -1.999 * number);
  s21_matrix_test_helper::CheckMatrix(result3, -1.999 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator4) {
  S21Matrix matrix1{1, 199};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 199);

  double number = 2.5999;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.5999);
  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result2 = number * matrix1;
  S21Matrix result3 = matrix1;
  result3 *= number;

  s21_matrix_test_helper::CheckMatrix(result1, 1.5999 * number);
  s21_matrix_test_helper::CheckMatrix(result2, 1.5999 * number);
  s21_matrix_test_helper::CheckMatrix(result3, 1.5999 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator5) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  S21Matrix check_matrix = matrix1;
  EXPECT_EQ(check_matrix.get_rows(), 4);
  EXPECT_EQ(check_matrix.get_cols(), 3);

  double number = 1.99;

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

  check_matrix(0, 0) = 2.985;
  check_matrix(0, 1) = 4.975;
  check_matrix(0, 2) = 6.965;
  check_matrix(1, 0) = -2.985;
  check_matrix(1, 1) = -4.975;
  check_matrix(1, 2) = -6.965;
  check_matrix(2, 0) = 0.0;
  check_matrix(2, 1) = 0.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 1.99;
  check_matrix(3, 1) = 1.99;
  check_matrix(3, 2) = 1.99;

  S21Matrix matrix1_before = matrix1;
  S21Matrix result1 = matrix1 * number;
  S21Matrix result2 = number * matrix1;
  S21Matrix result3 = matrix1;
  result3 *= number;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result2 == check_matrix);
  EXPECT_TRUE(result3 == check_matrix);
  EXPECT_TRUE(matrix1 == matrix1_before);
}

TEST(TestMulNumber, TestMulNumberOperator6) {
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
  S21Matrix result1 = matrix1 * number;
  S21Matrix result2 = number * matrix1;
  S21Matrix result3 = matrix1;
  result3 *= number;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result2 == check_matrix);
  EXPECT_TRUE(result3 == check_matrix);
  EXPECT_TRUE(matrix1 == matrix1_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Рандомные тесты
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST_P(RandomMulNumberMatrixRangeOne, TestMulNumberRandom1) {
  S21Matrix matrix_before = test_matrix_;
  double number = s21_matrix_test_helper::GetRandDouble(-1e8, 1e8);
  S21Matrix check_matrix = test_matrix_;

  for (int i = 0; i < check_matrix.get_rows(); i++) {
    for (int j = 0; j < check_matrix.get_cols(); j++) {
      check_matrix(i, j) = test_matrix_(i, j) * number;
    }
  }

  S21Matrix matrix1 = test_matrix_;
  S21Matrix matrix2 = test_matrix_;
  S21Matrix result1 = test_matrix_ * number;
  S21Matrix result2 = number * test_matrix_;
  matrix1.MulNumber(number);
  S21Matrix result3 = matrix2;
  result3 *= number;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result2 == check_matrix);
  EXPECT_TRUE(result3 == check_matrix);
  EXPECT_TRUE(matrix_before == test_matrix_);

#if (__DEBUG == 1)
  if (::testing::Test::HasFailure()) {
    s21_matrix_test_helper::Print(test_matrix_);
    s21_matrix_test_helper::PrintTest(test_matrix_);
    s21_matrix_test_helper::PrintWolfram(test_matrix_);
  }
#endif
}

INSTANTIATE_TEST_SUITE_P(
    MulNumberSuite1, RandomMulNumberMatrixRangeOne,
    ::testing::Range(0, s21_matrix_test_helper::kRandomTestNum));
