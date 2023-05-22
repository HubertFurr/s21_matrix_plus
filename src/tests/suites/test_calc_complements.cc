#include "./../classes/random_suites.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestCalcComplements, TestCalcComplementsException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException2) {
  S21Matrix test_matrix(3, 2);

  EXPECT_EQ(test_matrix.get_rows(), 3);
  EXPECT_EQ(test_matrix.get_cols(), 2);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException3) {
  S21Matrix test_matrix(1, 5);

  EXPECT_EQ(test_matrix.get_rows(), 1);
  EXPECT_EQ(test_matrix.get_cols(), 5);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException4) {
  S21Matrix test_matrix(5, 1);

  EXPECT_EQ(test_matrix.get_rows(), 5);
  EXPECT_EQ(test_matrix.get_cols(), 1);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException5) {
  S21Matrix test_matrix(29, 30);

  EXPECT_EQ(test_matrix.get_rows(), 29);
  EXPECT_EQ(test_matrix.get_cols(), 30);

  s21_matrix_test_helper::FillMatrix(test_matrix, 1.99);
  s21_matrix_test_helper::CheckMatrix(test_matrix, 1.99);

  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Рандомные цикличные тесты, где матрица дополнений заполнена нулями
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Используем для теста следующее свойство определителя:
// Если хотя бы один ряд (строка или столбец) состоит из нулей, то определитель
// равен нулю
TEST_P(RandomCofactorMatrixWithZeros, TestCalcComplementsZeroRandom1) {
  S21Matrix matrix_before = test_matrix_;
  S21Matrix result_check{test_matrix_.get_rows(), test_matrix_.get_cols()};

  EXPECT_EQ(result_check.get_cols(), test_matrix_.get_rows());
  EXPECT_EQ(result_check.get_rows(), test_matrix_.get_cols());

  s21_matrix_test_helper::CheckMatrix(result_check, 0.0);

  S21Matrix result = test_matrix_.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(test_matrix_ == matrix_before);

#if (__DEBUG == 1)
  if (::testing::Test::HasFailure()) {
    s21_matrix_test_helper::Print(test_matrix_);
    s21_matrix_test_helper::PrintTest(test_matrix_);
    s21_matrix_test_helper::PrintWolfram(test_matrix_);
  }
#endif
}

INSTANTIATE_TEST_SUITE_P(
    CalcComplementsSuite1, RandomCofactorMatrixWithZeros,
    ::testing::Range(0, s21_matrix_test_helper::kRandomTestNum));

// Используем для теста следующее свойство определителя:
// Если в определителе имеются два одинаковых параллельных ряда, то определитель
// равен нулю
TEST_P(RandomCofactorMatrixWithDuplicates, TestCalcComplementsZeroRandom2) {
  S21Matrix matrix_before = test_matrix_;
  S21Matrix result_check{test_matrix_.get_rows(), test_matrix_.get_cols()};

  EXPECT_EQ(result_check.get_cols(), test_matrix_.get_rows());
  EXPECT_EQ(result_check.get_rows(), test_matrix_.get_cols());

  s21_matrix_test_helper::CheckMatrix(result_check, 0.0);

  S21Matrix result = test_matrix_.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(test_matrix_ == matrix_before);

#if (__DEBUG == 1)
  if (::testing::Test::HasFailure()) {
    s21_matrix_test_helper::Print(test_matrix_);
    s21_matrix_test_helper::PrintTest(test_matrix_);
    s21_matrix_test_helper::PrintWolfram(test_matrix_);
  }
#endif
}

INSTANTIATE_TEST_SUITE_P(
    CalcComplementsSuite2, RandomCofactorMatrixWithDuplicates,
    ::testing::Range(0, s21_matrix_test_helper::kRandomTestNum));

// Используем для теста следующее свойство определителя:
// Если в определителе два параллельных ряда пропорциональны, то определитель
// равен нулю
TEST_P(RandomCofactorMatrixWithProportional, TestCalcComplementsZeroRandom3) {
  S21Matrix matrix_before = test_matrix_;
  S21Matrix result_check{test_matrix_.get_rows(), test_matrix_.get_cols()};

  EXPECT_EQ(result_check.get_cols(), test_matrix_.get_rows());
  EXPECT_EQ(result_check.get_rows(), test_matrix_.get_cols());

  s21_matrix_test_helper::CheckMatrix(result_check, 0.0);

  S21Matrix result = test_matrix_.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(test_matrix_ == matrix_before);

#if (__DEBUG == 1)
  if (::testing::Test::HasFailure()) {
    s21_matrix_test_helper::Print(test_matrix_);
    s21_matrix_test_helper::PrintTest(test_matrix_);
    s21_matrix_test_helper::PrintWolfram(test_matrix_);
  }
#endif
}

INSTANTIATE_TEST_SUITE_P(
    CalcComplementsSuite3, RandomCofactorMatrixWithProportional,
    ::testing::Range(0, s21_matrix_test_helper::kRandomTestNum));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты для матриц 1х1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestCalcComplements, TestCalcComplementsOne1) {
  S21Matrix test_matrix(1, 1);

  EXPECT_EQ(test_matrix.get_rows(), 1);
  EXPECT_EQ(test_matrix.get_cols(), 1);

  S21Matrix matrix_before = test_matrix;
  S21Matrix result;

  EXPECT_NO_THROW(result = test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);

  EXPECT_EQ(result.get_rows(), 1);
  EXPECT_EQ(result.get_cols(), 1);
  EXPECT_EQ(result(0, 0), 1.0);
}

TEST(TestCalcComplements, TestCalcComplementsOne2) {
  S21Matrix test_matrix(1, 1);

  EXPECT_EQ(test_matrix.get_rows(), 1);
  EXPECT_EQ(test_matrix.get_cols(), 1);

  test_matrix(0, 0) = 5.0;
  S21Matrix matrix_before = test_matrix;
  S21Matrix result;

  EXPECT_NO_THROW(result = test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);

  EXPECT_EQ(result.get_rows(), 1);
  EXPECT_EQ(result.get_cols(), 1);
  EXPECT_EQ(result(0, 0), 1.0);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты, где матрица дополнений заполнена нулями
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestCalcComplements, TestCalcComplementsZero1) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  S21Matrix result_check{3, 3};
  EXPECT_EQ(result_check.get_cols(), 3);
  EXPECT_EQ(result_check.get_rows(), 3);

  s21_matrix_test_helper::CheckMatrix(result_check, 0.0);

  matrix1(0, 0) = -3.00;
  matrix1(0, 1) = 6.00;
  matrix1(0, 2) = -3.00;
  matrix1(1, 0) = 6.00;
  matrix1(1, 1) = -12.00;
  matrix1(1, 2) = 6.00;
  matrix1(2, 0) = -3.00;
  matrix1(2, 1) = 6.00;
  matrix1(2, 2) = -3.00;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsZero2) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  S21Matrix result_check{3, 3};
  EXPECT_EQ(result_check.get_cols(), 3);
  EXPECT_EQ(result_check.get_rows(), 3);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(result_check, 0.0);

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsZero3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  S21Matrix result_check{3, 3};
  EXPECT_EQ(result_check.get_cols(), 3);
  EXPECT_EQ(result_check.get_rows(), 3);

  s21_matrix_test_helper::CheckMatrix(result_check, 0.0);

  matrix1(0, 0) = 0.00;
  matrix1(0, 1) = 9.00;
  matrix1(0, 2) = 0.0;
  matrix1(1, 0) = 0.00;
  matrix1(1, 1) = -12.00;
  matrix1(1, 2) = 0.0;
  matrix1(2, 0) = 0.00;
  matrix1(2, 1) = 7.00;
  matrix1(2, 2) = 0.00;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsZero4) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  S21Matrix result_check{4, 4};
  EXPECT_EQ(result_check.get_cols(), 4);
  EXPECT_EQ(result_check.get_rows(), 4);

  s21_matrix_test_helper::CheckMatrix(result_check, 0.0);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 15;
  matrix1(0, 2) = 1;
  matrix1(0, 3) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 16;
  matrix1(1, 2) = 2;
  matrix1(1, 3) = 2;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 17;
  matrix1(2, 2) = 3;
  matrix1(2, 3) = 3;
  matrix1(3, 0) = 4;
  matrix1(3, 1) = 18;
  matrix1(3, 2) = 4;
  matrix1(3, 3) = 4;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsZero5) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  S21Matrix result_check{4, 4};
  EXPECT_EQ(result_check.get_cols(), 4);
  EXPECT_EQ(result_check.get_rows(), 4);

  s21_matrix_test_helper::CheckMatrix(result_check, 0.0);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 5;
  matrix1(0, 2) = 9;
  matrix1(0, 3) = 13;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 6;
  matrix1(1, 2) = 10;
  matrix1(1, 3) = 14;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 7;
  matrix1(2, 2) = 11;
  matrix1(2, 3) = 15;
  matrix1(3, 0) = 4;
  matrix1(3, 1) = 8;
  matrix1(3, 2) = 12;
  matrix1(3, 3) = 16;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на обычные матрицы
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestCalcComplements, TestCalcComplements1) {
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

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements2) {
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

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  S21Matrix result_check{3, 3};
  EXPECT_EQ(result_check.get_cols(), 3);
  EXPECT_EQ(result_check.get_rows(), 3);

  matrix1(0, 0) = 1;
  matrix1(1, 0) = 2;
  matrix1(2, 0) = 3;
  matrix1(0, 1) = 4;
  matrix1(1, 1) = 5;
  matrix1(2, 1) = 6;
  matrix1(0, 2) = 7;
  matrix1(1, 2) = 8;
  matrix1(2, 2) = 9;

  result_check(0, 0) = -3;
  result_check(1, 0) = 6;
  result_check(2, 0) = -3;
  result_check(0, 1) = 6;
  result_check(1, 1) = -12;
  result_check(2, 1) = 6;
  result_check(0, 2) = -3;
  result_check(1, 2) = 6;
  result_check(2, 2) = -3;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements4) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  S21Matrix result_check{4, 4};
  EXPECT_EQ(result_check.get_cols(), 4);
  EXPECT_EQ(result_check.get_rows(), 4);

  matrix1(0, 0) = -3.86;
  matrix1(1, 0) = -8.48;
  matrix1(2, 0) = -8.36;
  matrix1(3, 0) = 2.82;
  matrix1(0, 1) = 7.02;
  matrix1(1, 1) = 7.17;
  matrix1(2, 1) = -4.87;
  matrix1(3, 1) = -1.54;
  matrix1(0, 2) = 4.23;
  matrix1(1, 2) = 7.84;
  matrix1(2, 2) = 3.56;
  matrix1(3, 2) = -8.62;
  matrix1(0, 3) = 4.82;
  matrix1(1, 3) = -7.78;
  matrix1(2, 3) = 3.62;
  matrix1(3, 3) = 3.71;

  result_check(0, 0) = 11781393.0 / 250000.0;
  result_check(1, 0) = -593383083.0 / 1000000.0;
  result_check(2, 0) = -113629541.0 / 200000.0;
  result_check(3, 0) = -187801277.0 / 250000.0;
  result_check(0, 1) = 3349777.0 / 6250.0;
  result_check(1, 1) = 1886893.0 / 6250.0;
  result_check(2, 1) = -108158171.0 / 250000.0;
  result_check(3, 1) = 44864781.0 / 125000.0;
  result_check(0, 2) = 48626797.0 / 250000.0;
  result_check(1, 2) = -46586467.0 / 100000.0;
  result_check(2, 2) = -2410461.0 / 100000.0;
  result_check(3, 2) = -18845574.0 / 15625.0;
  result_check(0, 3) = 39911437.0 / 62500.0;
  result_check(1, 3) = -253030017.0 / 500000.0;
  result_check(2, 3) = 98132137.0 / 500000.0;
  result_check(3, 3) = -16461827.0 / 250000.0;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements5) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  S21Matrix result_check{5, 5};
  EXPECT_EQ(result_check.get_cols(), 5);
  EXPECT_EQ(result_check.get_rows(), 5);

  matrix1(0, 0) = 3.3402;
  matrix1(0, 1) = -7.8838;
  matrix1(0, 2) = 1.4603;
  matrix1(0, 3) = -1.3716;
  matrix1(0, 4) = 6.0723;
  matrix1(1, 0) = -7.8846;
  matrix1(1, 1) = 7.8416;
  matrix1(1, 2) = -4.2679;
  matrix1(1, 3) = 9.8356;
  matrix1(1, 4) = -2.3961;
  matrix1(2, 0) = 4.1176;
  matrix1(2, 1) = 2.0162;
  matrix1(2, 2) = 4.7337;
  matrix1(2, 3) = 6.3434;
  matrix1(2, 4) = -9.7277;
  matrix1(3, 0) = -7.4141;
  matrix1(3, 1) = -6.0886;
  matrix1(3, 2) = 3.0417;
  matrix1(3, 3) = 4.7122;
  matrix1(3, 4) = 3.8023;
  matrix1(4, 0) = -2.4891;
  matrix1(4, 1) = -5.7155;
  matrix1(4, 2) = -1.7409;
  matrix1(4, 3) = -5.2048;
  matrix1(4, 4) = -6.8199;

  result_check(0, 0) = -1465690149213583.0 / 152587890625;
  result_check(0, 1) = 1272307326797681.0 / 122070312500;
  result_check(0, 2) = 8908235542058123.0 / 610351562500;
  result_check(0, 3) = -3051493103944107.0 / 305175781250;
  result_check(0, 4) = -6463308694007859.0 / 4882812500000;
  result_check(1, 0) = -1311111307169479.0 / 610351562500;
  result_check(1, 1) = 4013698343237797.0 / 1220703125000;
  result_check(1, 2) = 1879307039061624.0 / 152587890625;
  result_check(1, 3) = -2346277736890227.0 / 305175781250;
  result_check(1, 4) = 918022536110711.0 / 1220703125000;
  result_check(2, 0) = -2046840259044663.0 / 610351562500;
  result_check(2, 1) = 4228464572521883.0 / 2441406250000;
  result_check(2, 2) = -6621800960129521.0 / 2441406250000;
  result_check(2, 3) = -2641705482122563.0 / 610351562500;
  result_check(2, 4) = 7359340653769.0 / 1953125000;
  result_check(3, 0) = 4563655460607809.0 / 610351562500;
  result_check(3, 1) = 431856638931077.0 / 1953125000000;
  result_check(3, 2) = -6291617971140427.0 / 610351562500;
  result_check(3, 3) = 1313171371096307.0 / 1220703125000;
  result_check(3, 4) = -5390167833396221.0 / 4882812500000;
  result_check(4, 0) = 2817957903551703.0 / 2441406250000;
  result_check(4, 1) = 3526500249653419.0 / 610351562500;
  result_check(4, 2) = 414413005838107.0 / 61035156250;
  result_check(4, 3) = 348820831855181.0 / 610351562500;
  result_check(4, 4) = 327320067348047.0 / 61035156250;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements6) {
  S21Matrix matrix1{9, 9};
  EXPECT_EQ(matrix1.get_cols(), 9);
  EXPECT_EQ(matrix1.get_rows(), 9);

  S21Matrix result_check{9, 9};
  EXPECT_EQ(result_check.get_cols(), 9);
  EXPECT_EQ(result_check.get_rows(), 9);

  matrix1(0, 0) = -3.00;
  matrix1(0, 1) = -4.00;
  matrix1(0, 2) = -9.00;
  matrix1(0, 3) = 1.00;
  matrix1(0, 4) = -8.00;
  matrix1(0, 5) = 4.00;
  matrix1(0, 6) = -5.00;
  matrix1(0, 7) = -4.00;
  matrix1(0, 8) = -6.00;
  matrix1(1, 0) = 3.00;
  matrix1(1, 1) = 8.00;
  matrix1(1, 2) = 1.00;
  matrix1(1, 3) = -5.00;
  matrix1(1, 4) = -4.00;
  matrix1(1, 5) = -9.00;
  matrix1(1, 6) = 1.00;
  matrix1(1, 7) = -4.00;
  matrix1(1, 8) = -1.00;
  matrix1(2, 0) = 5.00;
  matrix1(2, 1) = 6.00;
  matrix1(2, 2) = 9.00;
  matrix1(2, 3) = 3.00;
  matrix1(2, 4) = 3.00;
  matrix1(2, 5) = 3.00;
  matrix1(2, 6) = -1.00;
  matrix1(2, 7) = 1.00;
  matrix1(2, 8) = 3.00;
  matrix1(3, 0) = 5.00;
  matrix1(3, 1) = -8.00;
  matrix1(3, 2) = 7.00;
  matrix1(3, 3) = 1.00;
  matrix1(3, 4) = -9.00;
  matrix1(3, 5) = 6.00;
  matrix1(3, 6) = -3.00;
  matrix1(3, 7) = -9.00;
  matrix1(3, 8) = 0.00;
  matrix1(4, 0) = 6.00;
  matrix1(4, 1) = 6.00;
  matrix1(4, 2) = -5.00;
  matrix1(4, 3) = 0.00;
  matrix1(4, 4) = -5.00;
  matrix1(4, 5) = 9.00;
  matrix1(4, 6) = -2.00;
  matrix1(4, 7) = 7.00;
  matrix1(4, 8) = 0.00;
  matrix1(5, 0) = 6.00;
  matrix1(5, 1) = 5.00;
  matrix1(5, 2) = 0.00;
  matrix1(5, 3) = -1.00;
  matrix1(5, 4) = 0.00;
  matrix1(5, 5) = 3.00;
  matrix1(5, 6) = -6.00;
  matrix1(5, 7) = -5.00;
  matrix1(5, 8) = 1.00;
  matrix1(6, 0) = 2.00;
  matrix1(6, 1) = 0.00;
  matrix1(6, 2) = -1.00;
  matrix1(6, 3) = -5.00;
  matrix1(6, 4) = 5.00;
  matrix1(6, 5) = 8.00;
  matrix1(6, 6) = 6.00;
  matrix1(6, 7) = 4.00;
  matrix1(6, 8) = 7.00;
  matrix1(7, 0) = -8.00;
  matrix1(7, 1) = -5.00;
  matrix1(7, 2) = 4.00;
  matrix1(7, 3) = 5.00;
  matrix1(7, 4) = 8.00;
  matrix1(7, 5) = -3.00;
  matrix1(7, 6) = 5.00;
  matrix1(7, 7) = -2.00;
  matrix1(7, 8) = 0.00;
  matrix1(8, 0) = -4.00;
  matrix1(8, 1) = -8.00;
  matrix1(8, 2) = -1.00;
  matrix1(8, 3) = -6.00;
  matrix1(8, 4) = 3.00;
  matrix1(8, 5) = 9.00;
  matrix1(8, 6) = -5.00;
  matrix1(8, 7) = 9.00;
  matrix1(8, 8) = 2.00;

  result_check(0, 0) = 64929368;
  result_check(0, 1) = -24807174;
  result_check(0, 2) = 8377463;
  result_check(0, 3) = -26260983;
  result_check(0, 4) = 48249195;
  result_check(0, 5) = 4895273;
  result_check(0, 6) = 27415810;
  result_check(0, 7) = 7596327;
  result_check(0, 8) = -104010645;
  result_check(1, 0) = -20042180;
  result_check(1, 1) = 441474;
  result_check(1, 2) = -13241381;
  result_check(1, 3) = 28508523;
  result_check(1, 4) = -22388553;
  result_check(1, 5) = -12886241;
  result_check(1, 6) = -20643250;
  result_check(1, 7) = 2020605;
  result_check(1, 8) = 71456481;
  result_check(2, 0) = 78208172;
  result_check(2, 1) = -31032894;
  result_check(2, 2) = 4206257;
  result_check(2, 3) = -37734051;
  result_check(2, 4) = 61396875;
  result_check(2, 5) = 10903673;
  result_check(2, 6) = 38091514;
  result_check(2, 7) = 3287709;
  result_check(2, 8) = -139542003;
  result_check(3, 0) = -27960066;
  result_check(3, 1) = 11520882;
  result_check(3, 2) = -8199477;
  result_check(3, 3) = 15345105;
  result_check(3, 4) = -18994227;
  result_check(3, 5) = -8126343;
  result_check(3, 6) = -16303074;
  result_check(3, 7) = 456789;
  result_check(3, 8) = 54345621;
  result_check(4, 0) = -77614272;
  result_check(4, 1) = 21243606;
  result_check(4, 2) = -15804054;
  result_check(4, 3) = 42368916;
  result_check(4, 4) = -64653306;
  result_check(4, 5) = -24710580;
  result_check(4, 6) = -46419510;
  result_check(4, 7) = -5933874;
  result_check(4, 8) = 167781828;
  result_check(5, 0) = -48498594;
  result_check(5, 1) = 13815210;
  result_check(5, 2) = -4044546;
  result_check(5, 3) = 25243776;
  result_check(5, 4) = -45877464;
  result_check(5, 5) = -11919810;
  result_check(5, 6) = -17816604;
  result_check(5, 7) = 4305048;
  result_check(5, 8) = 90513822;
  result_check(6, 0) = 29519486;
  result_check(6, 1) = -11122350;
  result_check(6, 2) = 6357968;
  result_check(6, 3) = -10618146;
  result_check(6, 4) = 22712856;
  result_check(6, 5) = 1457480;
  result_check(6, 6) = 8381164;
  result_check(6, 7) = 5516616;
  result_check(6, 8) = -58625688;
  result_check(7, 0) = -68478154;
  result_check(7, 1) = 18602172;
  result_check(7, 2) = -19885636;
  result_check(7, 3) = 46293450;
  result_check(7, 4) = -69658230;
  result_check(7, 5) = -28413616;
  result_check(7, 6) = -47667548;
  result_check(7, 7) = 1703430;
  result_check(7, 8) = 171904224;
  result_check(8, 0) = -11614148;
  result_check(8, 1) = 4369176;
  result_check(8, 2) = -8028302;
  result_check(8, 3) = 16614012;
  result_check(8, 4) = -15098268;
  result_check(8, 5) = -7254086;
  result_check(8, 6) = -5637238;
  result_check(8, 7) = -2592960;
  result_check(8, 8) = 39427050;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements7) {
  S21Matrix matrix1{10, 10};
  EXPECT_EQ(matrix1.get_cols(), 10);
  EXPECT_EQ(matrix1.get_rows(), 10);

  S21Matrix result_check{10, 10};
  EXPECT_EQ(result_check.get_cols(), 10);
  EXPECT_EQ(result_check.get_rows(), 10);

  matrix1(0, 0) = -1;
  matrix1(0, 1) = -0;
  matrix1(0, 2) = 1;
  matrix1(0, 3) = 1;
  matrix1(0, 4) = 1;
  matrix1(0, 5) = 1;
  matrix1(0, 6) = -0;
  matrix1(0, 7) = 0;
  matrix1(0, 8) = -1;
  matrix1(0, 9) = 0;
  matrix1(1, 0) = 1;
  matrix1(1, 1) = -0;
  matrix1(1, 2) = -0;
  matrix1(1, 3) = -1;
  matrix1(1, 4) = -0;
  matrix1(1, 5) = -0;
  matrix1(1, 6) = -1;
  matrix1(1, 7) = 0;
  matrix1(1, 8) = -0;
  matrix1(1, 9) = -1;
  matrix1(2, 0) = 1;
  matrix1(2, 1) = -1;
  matrix1(2, 2) = -0;
  matrix1(2, 3) = -1;
  matrix1(2, 4) = -0;
  matrix1(2, 5) = 0;
  matrix1(2, 6) = -0;
  matrix1(2, 7) = 0;
  matrix1(2, 8) = 1;
  matrix1(2, 9) = -0;
  matrix1(3, 0) = -0;
  matrix1(3, 1) = -1;
  matrix1(3, 2) = -0;
  matrix1(3, 3) = 1;
  matrix1(3, 4) = 1;
  matrix1(3, 5) = -0;
  matrix1(3, 6) = 1;
  matrix1(3, 7) = -0;
  matrix1(3, 8) = -1;
  matrix1(3, 9) = 1;
  matrix1(4, 0) = 0;
  matrix1(4, 1) = 1;
  matrix1(4, 2) = 1;
  matrix1(4, 3) = 0;
  matrix1(4, 4) = -0;
  matrix1(4, 5) = 1;
  matrix1(4, 6) = -1;
  matrix1(4, 7) = -1;
  matrix1(4, 8) = 0;
  matrix1(4, 9) = -0;
  matrix1(5, 0) = 1;
  matrix1(5, 1) = 1;
  matrix1(5, 2) = 1;
  matrix1(5, 3) = 0;
  matrix1(5, 4) = -0;
  matrix1(5, 5) = 0;
  matrix1(5, 6) = 0;
  matrix1(5, 7) = 1;
  matrix1(5, 8) = -0;
  matrix1(5, 9) = 1;
  matrix1(6, 0) = -0;
  matrix1(6, 1) = 0;
  matrix1(6, 2) = -0;
  matrix1(6, 3) = -0;
  matrix1(6, 4) = 1;
  matrix1(6, 5) = 0;
  matrix1(6, 6) = -1;
  matrix1(6, 7) = -0;
  matrix1(6, 8) = -1;
  matrix1(6, 9) = 1;
  matrix1(7, 0) = -0;
  matrix1(7, 1) = 0;
  matrix1(7, 2) = -0;
  matrix1(7, 3) = -1;
  matrix1(7, 4) = -1;
  matrix1(7, 5) = 0;
  matrix1(7, 6) = -1;
  matrix1(7, 7) = 1;
  matrix1(7, 8) = 0;
  matrix1(7, 9) = -1;
  matrix1(8, 0) = 0;
  matrix1(8, 1) = 1;
  matrix1(8, 2) = 0;
  matrix1(8, 3) = 1;
  matrix1(8, 4) = -1;
  matrix1(8, 5) = 1;
  matrix1(8, 6) = -1;
  matrix1(8, 7) = -1;
  matrix1(8, 8) = -0;
  matrix1(8, 9) = 0;
  matrix1(9, 0) = -0;
  matrix1(9, 1) = 1;
  matrix1(9, 2) = 1;
  matrix1(9, 3) = -0;
  matrix1(9, 4) = -0;
  matrix1(9, 5) = 1;
  matrix1(9, 6) = 0;
  matrix1(9, 7) = -0;
  matrix1(9, 8) = -1;
  matrix1(9, 9) = -1;

  result_check(0, 0) = -2;
  result_check(0, 1) = -1;
  result_check(0, 2) = -2;
  result_check(0, 3) = 13;
  result_check(0, 4) = 15;
  result_check(0, 5) = 9;
  result_check(0, 6) = -7;
  result_check(0, 7) = 13;
  result_check(0, 8) = 14;
  result_check(0, 9) = -8;
  result_check(1, 0) = 13;
  result_check(1, 1) = -5;
  result_check(1, 2) = 13;
  result_check(1, 3) = 19;
  result_check(1, 4) = 6;
  result_check(1, 5) = -24;
  result_check(1, 6) = -12;
  result_check(1, 7) = -4;
  result_check(1, 8) = 1;
  result_check(1, 9) = -17;
  result_check(2, 0) = 2;
  result_check(2, 1) = 1;
  result_check(2, 2) = -21;
  result_check(2, 3) = -13;
  result_check(2, 4) = 8;
  result_check(2, 5) = 37;
  result_check(2, 6) = 7;
  result_check(2, 7) = 10;
  result_check(2, 8) = 9;
  result_check(2, 9) = 8;
  result_check(3, 0) = 6;
  result_check(3, 1) = -20;
  result_check(3, 2) = 29;
  result_check(3, 3) = 7;
  result_check(3, 4) = -22;
  result_check(3, 5) = -27;
  result_check(3, 6) = -2;
  result_check(3, 7) = -16;
  result_check(3, 8) = -19;
  result_check(3, 9) = 1;
  result_check(4, 0) = -5;
  result_check(4, 1) = -14;
  result_check(4, 2) = 41;
  result_check(4, 3) = -2;
  result_check(4, 4) = -20;
  result_check(4, 5) = -35;
  result_check(4, 6) = -6;
  result_check(4, 7) = -25;
  result_check(4, 8) = -11;
  result_check(4, 9) = 3;
  result_check(5, 0) = 6;
  result_check(5, 1) = 3;
  result_check(5, 2) = 6;
  result_check(5, 3) = 7;
  result_check(5, 4) = 1;
  result_check(5, 5) = -4;
  result_check(5, 6) = -2;
  result_check(5, 7) = 7;
  result_check(5, 8) = 4;
  result_check(5, 9) = 1;
  result_check(6, 0) = -3;
  result_check(6, 1) = 10;
  result_check(6, 2) = -26;
  result_check(6, 3) = -15;
  result_check(6, 4) = 11;
  result_check(6, 5) = 25;
  result_check(6, 6) = 1;
  result_check(6, 7) = 8;
  result_check(6, 8) = -2;
  result_check(6, 9) = 11;
  result_check(7, 0) = -5;
  result_check(7, 1) = -14;
  result_check(7, 2) = 18;
  result_check(7, 3) = -2;
  result_check(7, 4) = -20;
  result_check(7, 5) = -12;
  result_check(7, 6) = -6;
  result_check(7, 7) = -2;
  result_check(7, 8) = -11;
  result_check(7, 9) = 3;
  result_check(8, 0) = 6;
  result_check(8, 1) = 3;
  result_check(8, 2) = -17;
  result_check(8, 3) = 7;
  result_check(8, 4) = 1;
  result_check(8, 5) = 19;
  result_check(8, 6) = -2;
  result_check(8, 7) = 7;
  result_check(8, 8) = 4;
  result_check(8, 9) = 1;
  result_check(9, 0) = 1;
  result_check(9, 1) = 12;
  result_check(9, 2) = -22;
  result_check(9, 3) = -18;
  result_check(9, 4) = 4;
  result_check(9, 5) = 30;
  result_check(9, 6) = 15;
  result_check(9, 7) = 5;
  result_check(9, 8) = -7;
  result_check(9, 9) = 4;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements8) {
  TEST_TIMEOUT_BEGIN
  S21Matrix matrix1{16, 16};
  EXPECT_EQ(matrix1.get_cols(), 16);
  EXPECT_EQ(matrix1.get_rows(), 16);

  S21Matrix result_check{16, 16};
  EXPECT_EQ(result_check.get_cols(), 16);
  EXPECT_EQ(result_check.get_rows(), 16);

  matrix1(0, 0) = 1.00;
  matrix1(0, 1) = -1.00;
  matrix1(0, 2) = 0.00;
  matrix1(0, 3) = -1.00;
  matrix1(0, 4) = 0.00;
  matrix1(0, 5) = -1.00;
  matrix1(0, 6) = 1.00;
  matrix1(0, 7) = 1.00;
  matrix1(0, 8) = 0.00;
  matrix1(0, 9) = 0.00;
  matrix1(0, 10) = -1.00;
  matrix1(0, 11) = 0.00;
  matrix1(0, 12) = 1.00;
  matrix1(0, 13) = 1.00;
  matrix1(0, 14) = 1.00;
  matrix1(0, 15) = 0.00;
  matrix1(1, 0) = 1.00;
  matrix1(1, 1) = 0.00;
  matrix1(1, 2) = 1.00;
  matrix1(1, 3) = -1.00;
  matrix1(1, 4) = -1.00;
  matrix1(1, 5) = -1.00;
  matrix1(1, 6) = 0.00;
  matrix1(1, 7) = -1.00;
  matrix1(1, 8) = 1.00;
  matrix1(1, 9) = 0.00;
  matrix1(1, 10) = 0.00;
  matrix1(1, 11) = -1.00;
  matrix1(1, 12) = 1.00;
  matrix1(1, 13) = -1.00;
  matrix1(1, 14) = 1.00;
  matrix1(1, 15) = 1.00;
  matrix1(2, 0) = -1.00;
  matrix1(2, 1) = 1.00;
  matrix1(2, 2) = -1.00;
  matrix1(2, 3) = 1.00;
  matrix1(2, 4) = -1.00;
  matrix1(2, 5) = 1.00;
  matrix1(2, 6) = -1.00;
  matrix1(2, 7) = -1.00;
  matrix1(2, 8) = 0.00;
  matrix1(2, 9) = -1.00;
  matrix1(2, 10) = -1.00;
  matrix1(2, 11) = 0.00;
  matrix1(2, 12) = -1.00;
  matrix1(2, 13) = 1.00;
  matrix1(2, 14) = -1.00;
  matrix1(2, 15) = 1.00;
  matrix1(3, 0) = 1.00;
  matrix1(3, 1) = 0.00;
  matrix1(3, 2) = -1.00;
  matrix1(3, 3) = 0.00;
  matrix1(3, 4) = 1.00;
  matrix1(3, 5) = 1.00;
  matrix1(3, 6) = 0.00;
  matrix1(3, 7) = 1.00;
  matrix1(3, 8) = -1.00;
  matrix1(3, 9) = 1.00;
  matrix1(3, 10) = -1.00;
  matrix1(3, 11) = -1.00;
  matrix1(3, 12) = 0.00;
  matrix1(3, 13) = -1.00;
  matrix1(3, 14) = 0.00;
  matrix1(3, 15) = -1.00;
  matrix1(4, 0) = 0.00;
  matrix1(4, 1) = 0.00;
  matrix1(4, 2) = 1.00;
  matrix1(4, 3) = 1.00;
  matrix1(4, 4) = -1.00;
  matrix1(4, 5) = 1.00;
  matrix1(4, 6) = -1.00;
  matrix1(4, 7) = -1.00;
  matrix1(4, 8) = 1.00;
  matrix1(4, 9) = 1.00;
  matrix1(4, 10) = 1.00;
  matrix1(4, 11) = 0.00;
  matrix1(4, 12) = 0.00;
  matrix1(4, 13) = -1.00;
  matrix1(4, 14) = 1.00;
  matrix1(4, 15) = -1.00;
  matrix1(5, 0) = 1.00;
  matrix1(5, 1) = 1.00;
  matrix1(5, 2) = 0.00;
  matrix1(5, 3) = -1.00;
  matrix1(5, 4) = 1.00;
  matrix1(5, 5) = 1.00;
  matrix1(5, 6) = 1.00;
  matrix1(5, 7) = -1.00;
  matrix1(5, 8) = -1.00;
  matrix1(5, 9) = 1.00;
  matrix1(5, 10) = 0.00;
  matrix1(5, 11) = 1.00;
  matrix1(5, 12) = -1.00;
  matrix1(5, 13) = -1.00;
  matrix1(5, 14) = 0.00;
  matrix1(5, 15) = -1.00;
  matrix1(6, 0) = 1.00;
  matrix1(6, 1) = 1.00;
  matrix1(6, 2) = 1.00;
  matrix1(6, 3) = 0.00;
  matrix1(6, 4) = -1.00;
  matrix1(6, 5) = 1.00;
  matrix1(6, 6) = 1.00;
  matrix1(6, 7) = -1.00;
  matrix1(6, 8) = 1.00;
  matrix1(6, 9) = 0.00;
  matrix1(6, 10) = 1.00;
  matrix1(6, 11) = -1.00;
  matrix1(6, 12) = 1.00;
  matrix1(6, 13) = 1.00;
  matrix1(6, 14) = -1.00;
  matrix1(6, 15) = 0.00;
  matrix1(7, 0) = 1.00;
  matrix1(7, 1) = -1.00;
  matrix1(7, 2) = -1.00;
  matrix1(7, 3) = -1.00;
  matrix1(7, 4) = -1.00;
  matrix1(7, 5) = -1.00;
  matrix1(7, 6) = 1.00;
  matrix1(7, 7) = -1.00;
  matrix1(7, 8) = 0.00;
  matrix1(7, 9) = -1.00;
  matrix1(7, 10) = 0.00;
  matrix1(7, 11) = -1.00;
  matrix1(7, 12) = 1.00;
  matrix1(7, 13) = 1.00;
  matrix1(7, 14) = 1.00;
  matrix1(7, 15) = 0.00;
  matrix1(8, 0) = 0.00;
  matrix1(8, 1) = 0.00;
  matrix1(8, 2) = 1.00;
  matrix1(8, 3) = 0.00;
  matrix1(8, 4) = -1.00;
  matrix1(8, 5) = 0.00;
  matrix1(8, 6) = -1.00;
  matrix1(8, 7) = -1.00;
  matrix1(8, 8) = 1.00;
  matrix1(8, 9) = 1.00;
  matrix1(8, 10) = 1.00;
  matrix1(8, 11) = 0.00;
  matrix1(8, 12) = -1.00;
  matrix1(8, 13) = 1.00;
  matrix1(8, 14) = -1.00;
  matrix1(8, 15) = -1.00;
  matrix1(9, 0) = -1.00;
  matrix1(9, 1) = 0.00;
  matrix1(9, 2) = -1.00;
  matrix1(9, 3) = -1.00;
  matrix1(9, 4) = 0.00;
  matrix1(9, 5) = 0.00;
  matrix1(9, 6) = -1.00;
  matrix1(9, 7) = -1.00;
  matrix1(9, 8) = 0.00;
  matrix1(9, 9) = 1.00;
  matrix1(9, 10) = -1.00;
  matrix1(9, 11) = 0.00;
  matrix1(9, 12) = 1.00;
  matrix1(9, 13) = 0.00;
  matrix1(9, 14) = -1.00;
  matrix1(9, 15) = 0.00;
  matrix1(10, 0) = -1.00;
  matrix1(10, 1) = -1.00;
  matrix1(10, 2) = 0.00;
  matrix1(10, 3) = -1.00;
  matrix1(10, 4) = 0.00;
  matrix1(10, 5) = -1.00;
  matrix1(10, 6) = 1.00;
  matrix1(10, 7) = 1.00;
  matrix1(10, 8) = 1.00;
  matrix1(10, 9) = -1.00;
  matrix1(10, 10) = 1.00;
  matrix1(10, 11) = -1.00;
  matrix1(10, 12) = 0.00;
  matrix1(10, 13) = 1.00;
  matrix1(10, 14) = -1.00;
  matrix1(10, 15) = 1.00;
  matrix1(11, 0) = -1.00;
  matrix1(11, 1) = -1.00;
  matrix1(11, 2) = 0.00;
  matrix1(11, 3) = 1.00;
  matrix1(11, 4) = -1.00;
  matrix1(11, 5) = 0.00;
  matrix1(11, 6) = 1.00;
  matrix1(11, 7) = -1.00;
  matrix1(11, 8) = -1.00;
  matrix1(11, 9) = 0.00;
  matrix1(11, 10) = -1.00;
  matrix1(11, 11) = 0.00;
  matrix1(11, 12) = 0.00;
  matrix1(11, 13) = 1.00;
  matrix1(11, 14) = 0.00;
  matrix1(11, 15) = 0.00;
  matrix1(12, 0) = 0.00;
  matrix1(12, 1) = -1.00;
  matrix1(12, 2) = 0.00;
  matrix1(12, 3) = 0.00;
  matrix1(12, 4) = 0.00;
  matrix1(12, 5) = 0.00;
  matrix1(12, 6) = 0.00;
  matrix1(12, 7) = -1.00;
  matrix1(12, 8) = -1.00;
  matrix1(12, 9) = 0.00;
  matrix1(12, 10) = -1.00;
  matrix1(12, 11) = 0.00;
  matrix1(12, 12) = 1.00;
  matrix1(12, 13) = -1.00;
  matrix1(12, 14) = 0.00;
  matrix1(12, 15) = -1.00;
  matrix1(13, 0) = -1.00;
  matrix1(13, 1) = 1.00;
  matrix1(13, 2) = 1.00;
  matrix1(13, 3) = 1.00;
  matrix1(13, 4) = -1.00;
  matrix1(13, 5) = 0.00;
  matrix1(13, 6) = 0.00;
  matrix1(13, 7) = -1.00;
  matrix1(13, 8) = 0.00;
  matrix1(13, 9) = 0.00;
  matrix1(13, 10) = 1.00;
  matrix1(13, 11) = 0.00;
  matrix1(13, 12) = -1.00;
  matrix1(13, 13) = -1.00;
  matrix1(13, 14) = 0.00;
  matrix1(13, 15) = 0.00;
  matrix1(14, 0) = -1.00;
  matrix1(14, 1) = 0.00;
  matrix1(14, 2) = 0.00;
  matrix1(14, 3) = 0.00;
  matrix1(14, 4) = 0.00;
  matrix1(14, 5) = -1.00;
  matrix1(14, 6) = 1.00;
  matrix1(14, 7) = 0.00;
  matrix1(14, 8) = 1.00;
  matrix1(14, 9) = 1.00;
  matrix1(14, 10) = 0.00;
  matrix1(14, 11) = 0.00;
  matrix1(14, 12) = -1.00;
  matrix1(14, 13) = 0.00;
  matrix1(14, 14) = -1.00;
  matrix1(14, 15) = 0.00;
  matrix1(15, 0) = -1.00;
  matrix1(15, 1) = 1.00;
  matrix1(15, 2) = 1.00;
  matrix1(15, 3) = -1.00;
  matrix1(15, 4) = -1.00;
  matrix1(15, 5) = 0.00;
  matrix1(15, 6) = -1.00;
  matrix1(15, 7) = -1.00;
  matrix1(15, 8) = 1.00;
  matrix1(15, 9) = -1.00;
  matrix1(15, 10) = -1.00;
  matrix1(15, 11) = 1.00;
  matrix1(15, 12) = -1.00;
  matrix1(15, 13) = 0.00;
  matrix1(15, 14) = 1.00;
  matrix1(15, 15) = 1.00;

  result_check(0, 0) = 65592;
  result_check(0, 1) = -38688;
  result_check(0, 2) = -70512;
  result_check(0, 3) = -71952;
  result_check(0, 4) = -314832;
  result_check(0, 5) = 43296;
  result_check(0, 6) = 37320;
  result_check(0, 7) = 169728;
  result_check(0, 8) = -36024;
  result_check(0, 9) = 24624;
  result_check(0, 10) = 13320;
  result_check(0, 11) = 172008;
  result_check(0, 12) = 17952;
  result_check(0, 13) = -106272;
  result_check(0, 14) = -100920;
  result_check(0, 15) = 15888;
  result_check(1, 0) = 42894;
  result_check(1, 1) = -38424;
  result_check(1, 2) = 10872;
  result_check(1, 3) = -1044;
  result_check(1, 4) = -18228;
  result_check(1, 5) = 972;
  result_check(1, 6) = -8970;
  result_check(1, 7) = -10968;
  result_check(1, 8) = -11226;
  result_check(1, 9) = 28548;
  result_check(1, 10) = -1434;
  result_check(1, 11) = -690;
  result_check(1, 12) = -16356;
  result_check(1, 13) = -27372;
  result_check(1, 14) = -19158;
  result_check(1, 15) = 73068;
  result_check(2, 0) = 75819;
  result_check(2, 1) = -59604;
  result_check(2, 2) = -78156;
  result_check(2, 3) = -27306;
  result_check(2, 4) = -211386;
  result_check(2, 5) = 51486;
  result_check(2, 6) = 17727;
  result_check(2, 7) = 87492;
  result_check(2, 8) = -3369;
  result_check(2, 9) = -2046;
  result_check(2, 10) = 6327;
  result_check(2, 11) = 122931;
  result_check(2, 12) = -15522;
  result_check(2, 13) = -95142;
  result_check(2, 14) = -99471;
  result_check(2, 15) = 48774;
  result_check(3, 0) = -26367;
  result_check(3, 1) = 26916;
  result_check(3, 2) = 20796;
  result_check(3, 3) = -7230;
  result_check(3, 4) = 41202;
  result_check(3, 5) = 4362;
  result_check(3, 6) = -8019;
  result_check(3, 7) = -1716;
  result_check(3, 8) = -6267;
  result_check(3, 9) = 3414;
  result_check(3, 10) = -28491;
  result_check(3, 11) = -90471;
  result_check(3, 12) = -21654;
  result_check(3, 13) = 20526;
  result_check(3, 14) = 32787;
  result_check(3, 15) = -32622;
  result_check(4, 0) = 12927;
  result_check(4, 1) = -56148;
  result_check(4, 2) = -49692;
  result_check(4, 3) = -17298;
  result_check(4, 4) = -107730;
  result_check(4, 5) = 65862;
  result_check(4, 6) = 20787;
  result_check(4, 7) = 45732;
  result_check(4, 8) = 30795;
  result_check(4, 9) = 18090;
  result_check(4, 10) = 22443;
  result_check(4, 11) = 70311;
  result_check(4, 12) = 3846;
  result_check(4, 13) = -55470;
  result_check(4, 14) = -12963;
  result_check(4, 15) = 16494;
  result_check(5, 0) = 38405;
  result_check(5, 1) = -44844;
  result_check(5, 2) = -33892;
  result_check(5, 3) = -46118;
  result_check(5, 4) = -96502;
  result_check(5, 5) = 48466;
  result_check(5, 6) = 27217;
  result_check(5, 7) = 29388;
  result_check(5, 8) = -21367;
  result_check(5, 9) = 19534;
  result_check(5, 10) = 25769;
  result_check(5, 11) = 77853;
  result_check(5, 12) = -20126;
  result_check(5, 13) = -50250;
  result_check(5, 14) = -41361;
  result_check(5, 15) = 41178;
  result_check(6, 0) = -17690;
  result_check(6, 1) = 44040;
  result_check(6, 2) = 29656;
  result_check(6, 3) = 14444;
  result_check(6, 4) = 52108;
  result_check(6, 5) = 2348;
  result_check(6, 6) = 15374;
  result_check(6, 7) = -22536;
  result_check(6, 8) = 22366;
  result_check(6, 9) = -15868;
  result_check(6, 10) = -16754;
  result_check(6, 11) = -37578;
  result_check(6, 12) = 27788;
  result_check(6, 13) = 31716;
  result_check(6, 14) = 9426;
  result_check(6, 15) = -31044;
  result_check(7, 0) = -22127;
  result_check(7, 1) = 33684;
  result_check(7, 2) = -20804;
  result_check(7, 3) = 9506;
  result_check(7, 4) = 63826;
  result_check(7, 5) = -33334;
  result_check(7, 6) = -595;
  result_check(7, 7) = -49140;
  result_check(7, 8) = 16261;
  result_check(7, 9) = -23002;
  result_check(7, 10) = 4501;
  result_check(7, 11) = -54663;
  result_check(7, 12) = -3766;
  result_check(7, 13) = 38094;
  result_check(7, 14) = 51891;
  result_check(7, 15) = -47166;
  result_check(8, 0) = 19214;
  result_check(8, 1) = -11400;
  result_check(8, 2) = 25400;
  result_check(8, 3) = -11540;
  result_check(8, 4) = -4564;
  result_check(8, 5) = -19268;
  result_check(8, 6) = -32282;
  result_check(8, 7) = -5400;
  result_check(8, 8) = -20362;
  result_check(8, 9) = 7540;
  result_check(8, 10) = 998;
  result_check(8, 11) = -16578;
  result_check(8, 12) = -28100;
  result_check(8, 13) = 22308;
  result_check(8, 14) = -16950;
  result_check(8, 15) = -14244;
  result_check(9, 0) = -30272;
  result_check(9, 1) = 18576;
  result_check(9, 2) = -24512;
  result_check(9, 3) = -34960;
  result_check(9, 4) = -41216;
  result_check(9, 5) = 5696;
  result_check(9, 6) = -7888;
  result_check(9, 7) = 16032;
  result_check(9, 8) = -23936;
  result_check(9, 9) = 36656;
  result_check(9, 10) = 16480;
  result_check(9, 11) = 13488;
  result_check(9, 12) = 32528;
  result_check(9, 13) = -1488;
  result_check(9, 14) = -3120;
  result_check(9, 15) = 6864;
  result_check(10, 0) = 6215;
  result_check(10, 1) = -66084;
  result_check(10, 2) = -22732;
  result_check(10, 3) = -60386;
  result_check(10, 4) = -116578;
  result_check(10, 5) = 61750;
  result_check(10, 6) = 19147;
  result_check(10, 7) = 62724;
  result_check(10, 8) = -14461;
  result_check(10, 9) = -2582;
  result_check(10, 10) = 29075;
  result_check(10, 11) = 45519;
  result_check(10, 12) = -14618;
  result_check(10, 13) = -57870;
  result_check(10, 14) = -51243;
  result_check(10, 15) = 31998;
  result_check(11, 0) = -38707;
  result_check(11, 1) = -11580;
  result_check(11, 2) = 51116;
  result_check(11, 3) = 24442;
  result_check(11, 4) = 102410;
  result_check(11, 5) = 6466;
  result_check(11, 6) = 841;
  result_check(11, 7) = -63348;
  result_check(11, 8) = -23215;
  result_check(11, 9) = 32974;
  result_check(11, 10) = -12367;
  result_check(11, 11) = -72171;
  result_check(11, 12) = -14078;
  result_check(11, 13) = 65334;
  result_check(11, 14) = 56919;
  result_check(11, 15) = 31098;
  result_check(12, 0) = 25269;
  result_check(12, 1) = -33660;
  result_check(12, 2) = -948;
  result_check(12, 3) = -5142;
  result_check(12, 4) = -59766;
  result_check(12, 5) = 2418;
  result_check(12, 6) = 9921;
  result_check(12, 7) = 20220;
  result_check(12, 8) = 16185;
  result_check(12, 9) = -53682;
  result_check(12, 10) = -25623;
  result_check(12, 11) = 48333;
  result_check(12, 12) = 11058;
  result_check(12, 13) = -62154;
  result_check(12, 14) = -66321;
  result_check(12, 15) = -41334;
  result_check(13, 0) = -4812;
  result_check(13, 1) = 36528;
  result_check(13, 2) = -33168;
  result_check(13, 3) = -45960;
  result_check(13, 4) = -187992;
  result_check(13, 5) = -9336;
  result_check(13, 6) = 16596;
  result_check(13, 7) = 96864;
  result_check(13, 8) = -66924;
  result_check(13, 9) = 5736;
  result_check(13, 10) = 32436;
  result_check(13, 11) = 54132;
  result_check(13, 12) = 12888;
  result_check(13, 13) = -64536;
  result_check(13, 14) = -43332;
  result_check(13, 15) = -21480;
  result_check(14, 0) = -9480;
  result_check(14, 1) = 19872;
  result_check(14, 2) = -8112;
  result_check(14, 3) = 40368;
  result_check(14, 4) = 63504;
  result_check(14, 5) = -37584;
  result_check(14, 6) = 26184;
  result_check(14, 7) = -33984;
  result_check(14, 8) = 67608;
  result_check(14, 9) = -4464;
  result_check(14, 10) = -36168;
  result_check(14, 11) = -19128;
  result_check(14, 12) = -8880;
  result_check(14, 13) = 4800;
  result_check(14, 14) = 7848;
  result_check(14, 15) = -31008;
  result_check(15, 0) = -55480;
  result_check(15, 1) = 44976;
  result_check(15, 2) = 51680;
  result_check(15, 3) = 1408;
  result_check(15, 4) = 118832;
  result_check(15, 5) = -12368;
  result_check(15, 6) = -10280;
  result_check(15, 7) = -51024;
  result_check(15, 8) = 28040;
  result_check(15, 9) = -29024;
  result_check(15, 10) = -38872;
  result_check(15, 11) = -78312;
  result_check(15, 12) = -8480;
  result_check(15, 13) = 55344;
  result_check(15, 14) = 65064;
  result_check(15, 15) = -46944;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
  TEST_TIMEOUT_END
}

TEST(TestCalcComplements, TestCalcComplements9) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  S21Matrix result_check{4, 4};
  EXPECT_EQ(result_check.get_cols(), 4);
  EXPECT_EQ(result_check.get_rows(), 4);

  matrix1(0, 0) = 1.01;
  matrix1(0, 1) = 15;
  matrix1(0, 2) = 1;
  matrix1(0, 3) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 16;
  matrix1(1, 2) = 2;
  matrix1(1, 3) = 2;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 17;
  matrix1(2, 2) = 3;
  matrix1(2, 3) = 3;
  matrix1(3, 0) = 4;
  matrix1(3, 1) = 18;
  matrix1(3, 2) = 4;
  matrix1(3, 3) = 4;

  result_check(0, 0) = 0;
  result_check(0, 1) = 0;
  result_check(0, 2) = 0;
  result_check(0, 3) = 0;
  result_check(1, 0) = 0;
  result_check(1, 1) = 0;
  result_check(1, 2) = -0.14;
  result_check(1, 3) = 0.14;
  result_check(2, 0) = 0;
  result_check(2, 1) = 0;
  result_check(2, 2) = 0.28;
  result_check(2, 3) = -0.28;
  result_check(3, 0) = 0;
  result_check(3, 1) = 0;
  result_check(3, 2) = -0.14;
  result_check(3, 3) = 0.14;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements10) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  S21Matrix result_check{4, 4};
  EXPECT_EQ(result_check.get_cols(), 4);
  EXPECT_EQ(result_check.get_rows(), 4);

  matrix1(0, 0) = 1.000001;
  matrix1(0, 1) = 15;
  matrix1(0, 2) = 1;
  matrix1(0, 3) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 16;
  matrix1(1, 2) = 2;
  matrix1(1, 3) = 2;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 17;
  matrix1(2, 2) = 3;
  matrix1(2, 3) = 3;
  matrix1(3, 0) = 4;
  matrix1(3, 1) = 18;
  matrix1(3, 2) = 4;
  matrix1(3, 3) = 4;

  result_check(0, 0) = 0;
  result_check(0, 1) = 0;
  result_check(0, 2) = 0;
  result_check(0, 3) = 0;
  result_check(1, 0) = 0;
  result_check(1, 1) = 0;
  result_check(1, 2) = -1.4e-5;
  result_check(1, 3) = 1.4e-5;
  result_check(2, 0) = 0;
  result_check(2, 1) = 0;
  result_check(2, 2) = 2.8e-5;
  result_check(2, 3) = -2.8e-5;
  result_check(3, 0) = 0;
  result_check(3, 1) = 0;
  result_check(3, 2) = -1.4e-5;
  result_check(3, 3) = 1.4e-5;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}
