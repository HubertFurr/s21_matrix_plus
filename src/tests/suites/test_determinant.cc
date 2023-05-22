#include "./../classes/random_suites.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDeterminant, TestDeterminantException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException2) {
  S21Matrix test_matrix(3, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException3) {
  S21Matrix test_matrix(55, 2);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException4) {
  S21Matrix test_matrix(3, 55);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Рандомные цикличные тесты на определитель, равный 0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Используем для теста следующее свойство определителя:
// Если хотя бы один ряд (строка или столбец) состоит из нулей, то определитель
// равен нулю
TEST_P(RandomDeterminantMatrixWithZeros, TestDeterminantZeroRandom1) {
  double check = 0.0;
  S21Matrix matrix_before = test_matrix_;
  double result = test_matrix_.Determinant();
  EXPECT_NEAR(result, check, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(test_matrix_ == matrix_before);

#if (__DEBUG == 1)
  if (::testing::Test::HasFailure()) {
    std::cout << "det: " << result << "\n";
    s21_matrix_test_helper::Print(test_matrix_);
    s21_matrix_test_helper::PrintTest(test_matrix_);
    s21_matrix_test_helper::PrintWolfram(test_matrix_);
  }
#endif
}

INSTANTIATE_TEST_SUITE_P(
    DeterminantSuite1, RandomDeterminantMatrixWithZeros,
    ::testing::Range(0, s21_matrix_test_helper::kRandomTestNum));

// Используем для теста следующее свойство определителя:
// Если в определителе имеются два одинаковых параллельных ряда, то определитель
// равен нулю
TEST_P(RandomDeterminantMatrixWithDuplicates, TestDeterminantZeroRandom2) {
  double check = 0.0;
  S21Matrix matrix_before = test_matrix_;
  double result = test_matrix_.Determinant();
  EXPECT_NEAR(result, check, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(test_matrix_ == matrix_before);

#if (__DEBUG == 1)
  if (::testing::Test::HasFailure()) {
    std::cout << "det: " << result << "\n";
    s21_matrix_test_helper::Print(test_matrix_);
    s21_matrix_test_helper::PrintTest(test_matrix_);
    s21_matrix_test_helper::PrintWolfram(test_matrix_);
  }
#endif
}

INSTANTIATE_TEST_SUITE_P(
    DeterminantSuite2, RandomDeterminantMatrixWithDuplicates,
    ::testing::Range(0, s21_matrix_test_helper::kRandomTestNum));

// Используем для теста следующее свойство определителя:
// Если в определителе два параллельных ряда пропорциональны, то определитель
// равен нулю
TEST_P(RandomDeterminantMatrixWithProportional, TestDeterminantZeroRandom3) {
  double check = 0.0;
  S21Matrix matrix_before = test_matrix_;
  double result = test_matrix_.Determinant();
  EXPECT_NEAR(result, check, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(test_matrix_ == matrix_before);

#if (__DEBUG == 1)
  if (::testing::Test::HasFailure()) {
    std::cout << "det: " << result << "\n";
    s21_matrix_test_helper::Print(test_matrix_);
    s21_matrix_test_helper::PrintTest(test_matrix_);
    s21_matrix_test_helper::PrintWolfram(test_matrix_);
  }
#endif
}

INSTANTIATE_TEST_SUITE_P(
    DeterminantSuite3, RandomDeterminantMatrixWithProportional,
    ::testing::Range(0, s21_matrix_test_helper::kRandomTestNum));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на определитель, равный 0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDeterminant, TestDeterminantZero1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  matrix1(0, 0) = 0.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero2) {
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
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = -66;
  matrix1(0, 1) = -66;
  matrix1(0, 2) = -66;
  matrix1(1, 0) = -66;
  matrix1(1, 1) = -66;
  matrix1(1, 2) = -66;
  matrix1(2, 0) = -66;
  matrix1(2, 1) = -66;
  matrix1(2, 2) = -66;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero4) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 9.05718e+07;
  matrix1(0, 1) = 9.05718e+07;
  matrix1(0, 2) = 9.05718e+07;

  matrix1(1, 0) = 9.05718e+07;
  matrix1(1, 1) = 9.05718e+07;
  matrix1(1, 2) = 9.05718e+07;

  matrix1(2, 0) = -9.0963e+07;
  matrix1(2, 1) = -9.72731e+07;
  matrix1(2, 2) = 1.16551e+07;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero5) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 9.89841e+07;
  matrix1(0, 1) = 7.57375e+07;
  matrix1(0, 2) = 7.57375e+07;

  matrix1(1, 0) = 1.90939e+07;
  matrix1(1, 1) = 7.57375e+07;
  matrix1(1, 2) = 7.57375e+07;

  matrix1(2, 0) = -4.32978e+07;
  matrix1(2, 1) = 7.57375e+07;
  matrix1(2, 2) = 7.57375e+07;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero6) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  matrix1(0, 0) = -7.30939e+07;
  matrix1(0, 1) = -7.30939e+07;
  matrix1(0, 2) = -7.30939e+07;
  matrix1(0, 3) = -7.30939e+07;

  matrix1(1, 0) = -7.30939e+07;
  matrix1(1, 1) = -7.30939e+07;
  matrix1(1, 2) = -7.30939e+07;
  matrix1(1, 3) = -7.30939e+07;

  matrix1(2, 0) = 9.84035e+07;
  matrix1(2, 1) = 2.93853e+07;
  matrix1(2, 2) = 1.76365e+07;
  matrix1(2, 3) = 6.38153e+07;

  matrix1(3, 0) = -8.51029e+07;
  matrix1(3, 1) = -6.68206e+07;
  matrix1(3, 2) = -5.57998e+07;
  matrix1(3, 3) = -9.0224e+07;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero7) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 5.61395e+07;
  matrix1(0, 1) = 3.56219e+07;
  matrix1(0, 2) = 3.56219e+07;
  matrix1(0, 3) = -9.52484e+07;
  matrix1(0, 4) = -5.06042e+07;

  matrix1(1, 0) = 3.70469e+07;
  matrix1(1, 1) = 3.56219e+07;
  matrix1(1, 2) = 3.56219e+07;
  matrix1(1, 3) = 4.41733e+07;
  matrix1(1, 4) = 9.19346e+07;

  matrix1(2, 0) = 1.1319e+07;
  matrix1(2, 1) = 3.56219e+07;
  matrix1(2, 2) = 3.56219e+07;
  matrix1(2, 3) = 5.77491e+07;
  matrix1(2, 4) = -7.70006e+07;

  matrix1(3, 0) = -6.29533e+07;
  matrix1(3, 1) = 3.56219e+07;
  matrix1(3, 2) = 3.56219e+07;
  matrix1(3, 3) = 3.70425e+07;
  matrix1(3, 4) = -2.26376e+07;

  matrix1(4, 0) = 9.64659e+07;
  matrix1(4, 1) = 3.56219e+07;
  matrix1(4, 2) = 3.56219e+07;
  matrix1(4, 3) = 9.07791e+07;
  matrix1(4, 4) = 6.79804e+07;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero8) {
  S21Matrix matrix1{5, 5};

  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 490126999929252.0;
  matrix1(0, 1) = 342540400593534.0;
  matrix1(0, 2) = 342540400593534.0;
  matrix1(0, 3) = 957907041856159.0;
  matrix1(0, 4) = 161144864560551.0;

  matrix1(1, 0) = 904879303508081.0;
  matrix1(1, 1) = 342540400593534.0;
  matrix1(1, 2) = 342540400593534.0;
  matrix1(1, 3) = 872222433389614.0;
  matrix1(1, 4) = 517528813858064.0;

  matrix1(2, 0) = 164529895900761.0;
  matrix1(2, 1) = 342540400593534.0;
  matrix1(2, 2) = 342540400593534.0;
  matrix1(2, 3) = 115755924305184.0;
  matrix1(2, 4) = 744137398335045.0;

  matrix1(3, 0) = 295628643374509.0;
  matrix1(3, 1) = 342540400593534.0;
  matrix1(3, 2) = 342540400593534.0;
  matrix1(3, 3) = 172783313833962.0;
  matrix1(3, 4) = 245717847641320.0;

  matrix1(4, 0) = 549097439356132.0;
  matrix1(4, 1) = 342540400593534.0;
  matrix1(4, 2) = 342540400593534.0;
  matrix1(4, 3) = 718487106520757.0;
  matrix1(4, 4) = 429858960118645.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero9) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 342540400593534.0;
  matrix1(0, 1) = 490126999929252.0;
  matrix1(0, 2) = 957907041856159.0;
  matrix1(0, 3) = 161144864560551.0;
  matrix1(0, 4) = 342540400593534.0;

  matrix1(1, 0) = 342540400593534.0;
  matrix1(1, 1) = 904879303508081.0;
  matrix1(1, 2) = 872222433389614.0;
  matrix1(1, 3) = 517528813858064.0;
  matrix1(1, 4) = 342540400593534.0;

  matrix1(2, 0) = 342540400593534.0;
  matrix1(2, 1) = 164529895900761.0;
  matrix1(2, 2) = 115755924305184.0;
  matrix1(2, 3) = 744137398335045.0;
  matrix1(2, 4) = 342540400593534.0;

  matrix1(3, 0) = 342540400593534.0;
  matrix1(3, 1) = 295628643374509.0;
  matrix1(3, 2) = 172783313833962.0;
  matrix1(3, 3) = 245717847641320.0;
  matrix1(3, 4) = 342540400593534.0;

  matrix1(4, 0) = 342540400593534.0;
  matrix1(4, 1) = 549097439356132.0;
  matrix1(4, 2) = 718487106520757.0;
  matrix1(4, 3) = 429858960118645.0;
  matrix1(4, 4) = 342540400593534.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero10) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 342540400593534.0;
  matrix1(0, 1) = 342540400593534.0;
  matrix1(0, 2) = 342540400593534.0;
  matrix1(0, 3) = 342540400593534.0;
  matrix1(0, 4) = 342540400593534.0;

  matrix1(1, 0) = 490126999929252.0;
  matrix1(1, 1) = 904879303508081.0;
  matrix1(1, 2) = 872222433389614.0;
  matrix1(1, 3) = 517528813858064.0;
  matrix1(1, 4) = 957907041856159.0;

  matrix1(2, 0) = 161144864560551.0;
  matrix1(2, 1) = 164529895900761.0;
  matrix1(2, 2) = 115755924305184.0;
  matrix1(2, 3) = 744137398335045.0;
  matrix1(2, 4) = 549097439356132.0;

  matrix1(3, 0) = 718487106520757.0;
  matrix1(3, 1) = 295628643374509.0;
  matrix1(3, 2) = 172783313833962.0;
  matrix1(3, 3) = 245717847641320.0;
  matrix1(3, 4) = 429858960118645.0;

  matrix1(4, 0) = 342540400593534.0;
  matrix1(4, 1) = 342540400593534.0;
  matrix1(4, 2) = 342540400593534.0;
  matrix1(4, 3) = 342540400593534.0;
  matrix1(4, 4) = 342540400593534.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero11) {
  S21Matrix matrix1{5, 5};

  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 490126999929252.0;
  matrix1(0, 1) = 0.342540400593534;
  matrix1(0, 2) = 0.342540400593534;
  matrix1(0, 3) = 957907041856159.0;
  matrix1(0, 4) = 161144864560551.0;
  matrix1(1, 0) = 904879303508081.0;
  matrix1(1, 1) = 0.342540400593534;
  matrix1(1, 2) = 0.342540400593534;
  matrix1(1, 3) = 872222433389614.0;
  matrix1(1, 4) = 517528813858064.0;
  matrix1(2, 0) = 164529895900761.0;
  matrix1(2, 1) = 0.342540400593534;
  matrix1(2, 2) = 0.342540400593534;
  matrix1(2, 3) = 115755924305184.0;
  matrix1(2, 4) = 744137398335045.0;
  matrix1(3, 0) = 295628643374509.0;
  matrix1(3, 1) = 0.342540400593534;
  matrix1(3, 2) = 0.342540400593534;
  matrix1(3, 3) = 172783313833962.0;
  matrix1(3, 4) = 245717847641320.0;
  matrix1(4, 0) = 549097439356132.0;
  matrix1(4, 1) = 0.342540400593534;
  matrix1(4, 2) = 0.342540400593534;
  matrix1(4, 3) = 718487106520757.0;
  matrix1(4, 4) = 429858960118645.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero12) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 0.342540400593534;
  matrix1(0, 1) = 490126999929252.0;
  matrix1(0, 2) = 957907041856159.0;
  matrix1(0, 3) = 161144864560551.0;
  matrix1(0, 4) = 0.342540400593534;
  matrix1(1, 0) = 0.342540400593534;
  matrix1(1, 1) = 904879303508081.0;
  matrix1(1, 2) = 872222433389614.0;
  matrix1(1, 3) = 517528813858064.0;
  matrix1(1, 4) = 0.342540400593534;
  matrix1(2, 0) = 0.342540400593534;
  matrix1(2, 1) = 164529895900761.0;
  matrix1(2, 2) = 115755924305184.0;
  matrix1(2, 3) = 744137398335045.0;
  matrix1(2, 4) = 0.342540400593534;
  matrix1(3, 0) = 0.342540400593534;
  matrix1(3, 1) = 295628643374509.0;
  matrix1(3, 2) = 172783313833962.0;
  matrix1(3, 3) = 245717847641320.0;
  matrix1(3, 4) = 0.342540400593534;
  matrix1(4, 0) = 0.342540400593534;
  matrix1(4, 1) = 549097439356132.0;
  matrix1(4, 2) = 718487106520757.0;
  matrix1(4, 3) = 429858960118645.0;
  matrix1(4, 4) = 0.342540400593534;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero13) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 0.342540400593534;
  matrix1(0, 1) = 0.342540400593534;
  matrix1(0, 2) = 0.342540400593534;
  matrix1(0, 3) = 0.342540400593534;
  matrix1(0, 4) = 0.342540400593534;
  matrix1(1, 0) = 490126999929252.0;
  matrix1(1, 1) = 904879303508081.0;
  matrix1(1, 2) = 872222433389614.0;
  matrix1(1, 3) = 517528813858064.0;
  matrix1(1, 4) = 957907041856159.0;
  matrix1(2, 0) = 161144864560551.0;
  matrix1(2, 1) = 164529895900761.0;
  matrix1(2, 2) = 115755924305184.0;
  matrix1(2, 3) = 744137398335045.0;
  matrix1(2, 4) = 549097439356132.0;
  matrix1(3, 0) = 718487106520757.0;
  matrix1(3, 1) = 295628643374509.0;
  matrix1(3, 2) = 172783313833962.0;
  matrix1(3, 3) = 245717847641320.0;
  matrix1(3, 4) = 429858960118645.0;
  matrix1(4, 0) = 0.342540400593534;
  matrix1(4, 1) = 0.342540400593534;
  matrix1(4, 2) = 0.342540400593534;
  matrix1(4, 3) = 0.342540400593534;
  matrix1(4, 4) = 0.342540400593534;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero14) {
  S21Matrix matrix1{5, 5};

  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 0.490126999929252;
  matrix1(0, 1) = 342540400593534.0;
  matrix1(0, 2) = 342540400593534.0;
  matrix1(0, 3) = 0.957907041856159;
  matrix1(0, 4) = 0.161144864560551;
  matrix1(1, 0) = 0.904879303508081;
  matrix1(1, 1) = 342540400593534.0;
  matrix1(1, 2) = 342540400593534.0;
  matrix1(1, 3) = 0.872222433389614;
  matrix1(1, 4) = 0.517528813858064;
  matrix1(2, 0) = 0.164529895900761;
  matrix1(2, 1) = 342540400593534.0;
  matrix1(2, 2) = 342540400593534.0;
  matrix1(2, 3) = 0.115755924305184;
  matrix1(2, 4) = 0.744137398335045;
  matrix1(3, 0) = 0.295628643374509;
  matrix1(3, 1) = 342540400593534.0;
  matrix1(3, 2) = 342540400593534.0;
  matrix1(3, 3) = 0.172783313833962;
  matrix1(3, 4) = 0.245717847641320;
  matrix1(4, 0) = 0.549097439356132;
  matrix1(4, 1) = 342540400593534.0;
  matrix1(4, 2) = 342540400593534.0;
  matrix1(4, 3) = 0.718487106520757;
  matrix1(4, 4) = 0.429858960118645;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero15) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 342540400593534.0;
  matrix1(0, 1) = 0.490126999929252;
  matrix1(0, 2) = 0.957907041856159;
  matrix1(0, 3) = 0.161144864560551;
  matrix1(0, 4) = 342540400593534.0;
  matrix1(1, 0) = 342540400593534.0;
  matrix1(1, 1) = 0.904879303508081;
  matrix1(1, 2) = 0.872222433389614;
  matrix1(1, 3) = 0.517528813858064;
  matrix1(1, 4) = 342540400593534.0;
  matrix1(2, 0) = 342540400593534.0;
  matrix1(2, 1) = 0.164529895900761;
  matrix1(2, 2) = 0.115755924305184;
  matrix1(2, 3) = 0.744137398335045;
  matrix1(2, 4) = 342540400593534.0;
  matrix1(3, 0) = 342540400593534.0;
  matrix1(3, 1) = 0.295628643374509;
  matrix1(3, 2) = 0.172783313833962;
  matrix1(3, 3) = 0.245717847641320;
  matrix1(3, 4) = 342540400593534.0;
  matrix1(4, 0) = 342540400593534.0;
  matrix1(4, 1) = 0.549097439356132;
  matrix1(4, 2) = 0.718487106520757;
  matrix1(4, 3) = 0.429858960118645;
  matrix1(4, 4) = 342540400593534.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero16) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 342540400593534.0;
  matrix1(0, 1) = 342540400593534.0;
  matrix1(0, 2) = 342540400593534.0;
  matrix1(0, 3) = 342540400593534.0;
  matrix1(0, 4) = 342540400593534.0;
  matrix1(1, 0) = 0.490126999929252;
  matrix1(1, 1) = 0.904879303508081;
  matrix1(1, 2) = 0.872222433389614;
  matrix1(1, 3) = 0.517528813858064;
  matrix1(1, 4) = 0.957907041856159;
  matrix1(2, 0) = 0.161144864560551;
  matrix1(2, 1) = 0.164529895900761;
  matrix1(2, 2) = 0.115755924305184;
  matrix1(2, 3) = 0.744137398335045;
  matrix1(2, 4) = 0.549097439356132;
  matrix1(3, 0) = 0.718487106520757;
  matrix1(3, 1) = 0.295628643374509;
  matrix1(3, 2) = 0.172783313833962;
  matrix1(3, 3) = 0.245717847641320;
  matrix1(3, 4) = 0.429858960118645;
  matrix1(4, 0) = 342540400593534.0;
  matrix1(4, 1) = 342540400593534.0;
  matrix1(4, 2) = 342540400593534.0;
  matrix1(4, 3) = 342540400593534.0;
  matrix1(4, 4) = 342540400593534.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero17) {
  S21Matrix matrix1{5, 5};

  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 4901269.0;
  matrix1(0, 1) = 342540400593534.0;
  matrix1(0, 2) = 342540400593534.0;
  matrix1(0, 3) = 9.0;
  matrix1(0, 4) = 161144851.0;
  matrix1(1, 0) = 9048793031.0;
  matrix1(1, 1) = 342540400593534.0;
  matrix1(1, 2) = 342540400593534.0;
  matrix1(1, 3) = 87223389614.0;
  matrix1(1, 4) = 517528813858064.0;
  matrix1(2, 0) = 1645298951.0;
  matrix1(2, 1) = 342540400593534.0;
  matrix1(2, 2) = 342540400593534.0;
  matrix1(2, 3) = 115755924305184.0;
  matrix1(2, 4) = 744137398.0;
  matrix1(3, 0) = 295628643374509.0;
  matrix1(3, 1) = 342540400593534.0;
  matrix1(3, 2) = 342540400593534.0;
  matrix1(3, 3) = 17278333962.0;
  matrix1(3, 4) = 245717847641320.0;
  matrix1(4, 0) = 5490974393.0;
  matrix1(4, 1) = 342540400593534.0;
  matrix1(4, 2) = 342540400593534.0;
  matrix1(4, 3) = 71848710.0;
  matrix1(4, 4) = 429.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero18) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 342540400593534.0;
  matrix1(0, 1) = 0.0;
  matrix1(0, 2) = 95790704185619.0;
  matrix1(0, 3) = 16114486456051.0;
  matrix1(0, 4) = 342540400593534.0;
  matrix1(1, 0) = 342540400593534.0;
  matrix1(1, 1) = 90487930350881.0;
  matrix1(1, 2) = 0.0;
  matrix1(1, 3) = 51752881385804.0;
  matrix1(1, 4) = 342540400593534.0;
  matrix1(2, 0) = 342540400593534.0;
  matrix1(2, 1) = 16452989590071.0;
  matrix1(2, 2) = 0.0;
  matrix1(2, 3) = 744137398335045.0;
  matrix1(2, 4) = 342540400593534.0;
  matrix1(3, 0) = 342540400593534.0;
  matrix1(3, 1) = 29562864337459.0;
  matrix1(3, 2) = 17278331383392.0;
  matrix1(3, 3) = 0.0;
  matrix1(3, 4) = 342540400593534.0;
  matrix1(4, 0) = 342540400593534.0;
  matrix1(4, 1) = 54909749356132.0;
  matrix1(4, 2) = 71848710652757.0;
  matrix1(4, 3) = 42985860118645.0;
  matrix1(4, 4) = 342540400593534.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero19) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 342540400593534.0;
  matrix1(0, 1) = 342540400593534.0;
  matrix1(0, 2) = 342540400593534.0;
  matrix1(0, 3) = 342540400593534.0;
  matrix1(0, 4) = 342540400593534.0;
  matrix1(1, 0) = 49012699992.0;
  matrix1(1, 1) = 90487930350.0;
  matrix1(1, 2) = 87222243338.0;
  matrix1(1, 3) = 51752881385.0;
  matrix1(1, 4) = 95790704185.0;
  matrix1(2, 0) = 16114486456.0;
  matrix1(2, 1) = 16452989590.0;
  matrix1(2, 2) = 11575592430.0;
  matrix1(2, 3) = 74413739833.0;
  matrix1(2, 4) = 54909743935.0;
  matrix1(3, 0) = 71848710652.0;
  matrix1(3, 1) = 29562864337.0;
  matrix1(3, 2) = 17278331383.0;
  matrix1(3, 3) = 24571784764.0;
  matrix1(3, 4) = 42985896011.0;
  matrix1(4, 0) = 342540400593534.0;
  matrix1(4, 1) = 342540400593534.0;
  matrix1(4, 2) = 342540400593534.0;
  matrix1(4, 3) = 342540400593534.0;
  matrix1(4, 4) = 342540400593534.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero20) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 3;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 6;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero21) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 6;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero22) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 0;
  matrix1(0, 1) = 0;
  matrix1(1, 0) = 0;
  matrix1(1, 1) = 0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero23) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 62003758.14000639319420;
  matrix1(0, 1) = 124007516.28001278638840;
  matrix1(1, 0) = 7533129.83762268722057;
  matrix1(1, 1) = 15066259.67524537444115;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero24) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = -63581647.38773362338543;
  matrix1(0, 1) = 9756267.74286703765392;
  matrix1(0, 2) = -127163294.77546724677086;
  matrix1(1, 0) = 68655950.09263044595718;
  matrix1(1, 1) = 35162340.60234943032265;
  matrix1(1, 2) = 137311900.18526089191437;
  matrix1(2, 0) = -49642926.54292698949575;
  matrix1(2, 1) = -50026132.37590176612139;
  matrix1(2, 2) = -99285853.08585397899151;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero25) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  matrix1(0, 0) = 37521102.68191075325012;
  matrix1(0, 1) = -7366955.30483770370483;
  matrix1(0, 2) = -89234691.49498392641544;
  matrix1(0, 3) = 59685924.85609406232834;
  matrix1(1, 0) = -93989600.59850479662418;
  matrix1(1, 1) = -32273535.81015090644360;
  matrix1(1, 2) = 59293048.74089393019676;
  matrix1(1, 3) = 78694654.87947669625282;
  matrix1(2, 0) = 75042205.36382150650024;
  matrix1(2, 1) = -14733910.60967540740967;
  matrix1(2, 2) = -178469382.98996785283089;
  matrix1(2, 3) = 119371849.71218812465668;
  matrix1(3, 0) = 97988947.16184711456299;
  matrix1(3, 1) = 97257934.17296910285950;
  matrix1(3, 2) = 98991136.73402935266495;
  matrix1(3, 3) = 71803366.44616046547890;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero26) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  matrix1(0, 0) = -0.0;

  double result_check = -0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero27) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 561.395;
  matrix1(0, 1) = 356.219;
  matrix1(0, 2) = 356.219;
  matrix1(0, 3) = -952.484;
  matrix1(0, 4) = -506.042;

  matrix1(1, 0) = 370.469;
  matrix1(1, 1) = 356.219;
  matrix1(1, 2) = 356.219;
  matrix1(1, 3) = 441.733;
  matrix1(1, 4) = 919.346;

  matrix1(2, 0) = 113.190;
  matrix1(2, 1) = 356.219;
  matrix1(2, 2) = 356.219;
  matrix1(2, 3) = 577.491;
  matrix1(2, 4) = -770.006;

  matrix1(3, 0) = -629.533;
  matrix1(3, 1) = 356.219;
  matrix1(3, 2) = 356.219;
  matrix1(3, 3) = 370.425;
  matrix1(3, 4) = -226.376;

  matrix1(4, 0) = 964.659;
  matrix1(4, 1) = 356.219;
  matrix1(4, 2) = 356.219;
  matrix1(4, 3) = 907.791;
  matrix1(4, 4) = 679.804;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero28) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 561.395;
  matrix1(0, 1) = 370.469;
  matrix1(0, 2) = 441.733;
  matrix1(0, 3) = -952.484;
  matrix1(0, 4) = -506.042;

  matrix1(1, 0) = 356.219;
  matrix1(1, 1) = 356.219;
  matrix1(1, 2) = 356.219;
  matrix1(1, 3) = 356.219;
  matrix1(1, 4) = 356.219;

  matrix1(2, 0) = 113.190;
  matrix1(2, 1) = 919.346;
  matrix1(2, 2) = -629.533;
  matrix1(2, 3) = 577.491;
  matrix1(2, 4) = -770.006;

  matrix1(3, 0) = 356.219;
  matrix1(3, 1) = 356.219;
  matrix1(3, 2) = 356.219;
  matrix1(3, 3) = 356.219;
  matrix1(3, 4) = 356.219;

  matrix1(4, 0) = 964.659;
  matrix1(4, 1) = 370.425;
  matrix1(4, 2) = -226.376;
  matrix1(4, 3) = 907.791;
  matrix1(4, 4) = 679.804;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero29) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 356.219;
  matrix1(0, 1) = 356.219;
  matrix1(0, 2) = 356.219;
  matrix1(0, 3) = 356.219;
  matrix1(0, 4) = 356.219;

  matrix1(1, 0) = 356.219;
  matrix1(1, 1) = 356.219;
  matrix1(1, 2) = 356.219;
  matrix1(1, 3) = 356.219;
  matrix1(1, 4) = 356.219;

  matrix1(2, 0) = 113.190;
  matrix1(2, 1) = 919.346;
  matrix1(2, 2) = -629.533;
  matrix1(2, 3) = 577.491;
  matrix1(2, 4) = -770.006;

  matrix1(3, 0) = 561.395;
  matrix1(3, 1) = 370.469;
  matrix1(3, 2) = 441.733;
  matrix1(3, 3) = -952.484;
  matrix1(3, 4) = -506.042;

  matrix1(4, 0) = 964.659;
  matrix1(4, 1) = 370.425;
  matrix1(4, 2) = -226.376;
  matrix1(4, 3) = 907.791;
  matrix1(4, 4) = 679.804;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero30) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 561;
  matrix1(0, 1) = 356;
  matrix1(0, 2) = 356;
  matrix1(0, 3) = -952;
  matrix1(0, 4) = -506;

  matrix1(1, 0) = 370;
  matrix1(1, 1) = 356;
  matrix1(1, 2) = 356;
  matrix1(1, 3) = 441;
  matrix1(1, 4) = 919;

  matrix1(2, 0) = 113;
  matrix1(2, 1) = 356;
  matrix1(2, 2) = 356;
  matrix1(2, 3) = 577;
  matrix1(2, 4) = -770;

  matrix1(3, 0) = -629;
  matrix1(3, 1) = 356;
  matrix1(3, 2) = 356;
  matrix1(3, 3) = 370;
  matrix1(3, 4) = -226;

  matrix1(4, 0) = 964;
  matrix1(4, 1) = 356;
  matrix1(4, 2) = 356;
  matrix1(4, 3) = 907;
  matrix1(4, 4) = 679;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на определитель, не равный 0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDeterminant, TestDeterminant1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  matrix1(0, 0) = 1.5;

  double result_check = 1.5;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;

  double result_check = -0.02;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 7.72122069261968;
  matrix1(1, 0) = -7.3629210004583;
  matrix1(0, 1) = 8.93235725676641;
  matrix1(1, 1) = 2.69165195827372;

  double result_check = 86.5510796270;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant4) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 0;
  matrix1(0, 1) = 1;
  matrix1(0, 2) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;
  matrix1(1, 2) = 5;
  matrix1(2, 0) = 6;
  matrix1(2, 1) = 0;
  matrix1(2, 2) = 7;

  double result_check = -39;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant5) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 5.34922476788051;
  matrix1(1, 0) = 1.65522041497752;
  matrix1(2, 0) = -8.68382598599419;
  matrix1(0, 1) = -3.25669884728268;
  matrix1(1, 1) = 10.8967615629081;
  matrix1(2, 1) = 4.55130848893896;
  matrix1(0, 2) = -2.14478276530281;
  matrix1(1, 2) = -2.7382052554749;
  matrix1(2, 2) = 5.7808097708039;

  double result_check = 138.2380038449;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant6) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(0, 3) = 1.4;
  matrix1(1, 0) = 1.5;
  matrix1(1, 1) = 1.6;
  matrix1(1, 2) = 1.7;
  matrix1(1, 3) = 1.8;
  matrix1(2, 0) = 1.9;
  matrix1(2, 1) = 2.0;
  matrix1(2, 2) = 2.1;
  matrix1(2, 3) = 2.2;
  matrix1(3, 0) = 2.3;
  matrix1(3, 1) = 2.4;
  matrix1(3, 2) = 2.5;
  matrix1(3, 3) = 2.6;

  double result_check = -5.1347814888913e-17;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant7) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  matrix1(0, 0) = -7.00037610391155;
  matrix1(1, 0) = -6.32839397341013;
  matrix1(2, 0) = 10.222164043691;
  matrix1(3, 0) = 7.95983747509308;
  matrix1(0, 1) = -9.82599597726949;
  matrix1(1, 1) = 3.03237457247451;
  matrix1(2, 1) = 0.587724786484614;
  matrix1(3, 1) = -3.41600720770657;
  matrix1(0, 2) = 8.27683520526625;
  matrix1(1, 2) = -4.28063526446931;
  matrix1(2, 2) = -6.93227237439714;
  matrix1(3, 2) = -10.6065054496285;
  matrix1(0, 3) = 0.586602877592668;
  matrix1(1, 3) = 10.6546861075331;
  matrix1(2, 3) = 4.33103069034405;
  matrix1(3, 3) = 8.75408579711802;

  double result_check = -6618.5495718153;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant8) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  matrix1(0, 0) = 5.543;
  matrix1(0, 1) = 25.425;
  matrix1(0, 2) = 24.4325;
  matrix1(0, 3) = 23.52;
  matrix1(0, 4) = 0.0;
  matrix1(1, 0) = 52.3;
  matrix1(1, 1) = 53.2;
  matrix1(1, 2) = 34.434;
  matrix1(1, 3) = 0.0;
  matrix1(1, 4) = 53.352;
  matrix1(2, 0) = 54.23512;
  matrix1(2, 1) = 34.325;
  matrix1(2, 2) = 0.0;
  matrix1(2, 3) = 24.343;
  matrix1(2, 4) = 34.422;
  matrix1(3, 0) = 36.22;
  matrix1(3, 1) = 0.0;
  matrix1(3, 2) = 32.0;
  matrix1(3, 3) = 24.432;
  matrix1(3, 4) = 43.21;
  matrix1(4, 0) = 0.0;
  matrix1(4, 1) = 23.21;
  matrix1(4, 2) = 23.234;
  matrix1(4, 3) = 12.1231;
  matrix1(4, 4) = 21.2232;

  double result_check = 74346939.8940858;

  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant9) {
  S21Matrix matrix1{6, 6};
  EXPECT_EQ(matrix1.get_cols(), 6);
  EXPECT_EQ(matrix1.get_rows(), 6);

  matrix1(0, 0) = -8.25324401422404;
  matrix1(1, 0) = 7.73323425720446;
  matrix1(2, 0) = 1.84863350028172;
  matrix1(3, 0) = -10.0115760930348;
  matrix1(4, 0) = -5.15668712323532;
  matrix1(5, 0) = 0.833224474685267;
  matrix1(0, 1) = 6.72777522937395;
  matrix1(1, 1) = -5.02706401585601;
  matrix1(2, 1) = -0.966418515890837;
  matrix1(3, 1) = 7.74789611180313;
  matrix1(4, 1) = 0.869955397676677;
  matrix1(5, 1) = -2.01394975557923;
  matrix1(0, 2) = -4.55829650838859;
  matrix1(1, 2) = 3.51532235136256;
  matrix1(2, 2) = -7.3990064188838;
  matrix1(3, 2) = 0.485122002195567;
  matrix1(4, 2) = 9.88733662408777;
  matrix1(5, 2) = -3.07178143155761;
  matrix1(0, 3) = -6.01939426595345;
  matrix1(1, 3) = -7.33630517800339;
  matrix1(2, 3) = -3.09628330147825;
  matrix1(3, 3) = 8.41876223543659;
  matrix1(4, 3) = -3.80699184164405;
  matrix1(5, 3) = 1.82289709686302;
  matrix1(0, 4) = 9.28037635562941;
  matrix1(1, 4) = 8.25562612293288;
  matrix1(2, 4) = 3.07955321925692;
  matrix1(3, 4) = 1.94713557977229;
  matrix1(4, 4) = 7.41955809853971;
  matrix1(5, 4) = -9.39580690651201;
  matrix1(0, 5) = 2.73021495575085;
  matrix1(1, 5) = -5.90446221316233;
  matrix1(2, 5) = 5.84046185878105;
  matrix1(3, 5) = -2.47668161639012;
  matrix1(4, 5) = 1.28693996206857;
  matrix1(5, 5) = 4.85558348917402;

  double result_check = -109019.85742181906954580110;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant10) {
  S21Matrix matrix1{9, 9};
  EXPECT_EQ(matrix1.get_cols(), 9);
  EXPECT_EQ(matrix1.get_rows(), 9);

  matrix1(0, 0) = -0.93;
  matrix1(0, 1) = 0.96;
  matrix1(0, 2) = 0.56;
  matrix1(0, 3) = 0.05;
  matrix1(0, 4) = -0.94;
  matrix1(0, 5) = 0.01;
  matrix1(0, 6) = 0.69;
  matrix1(0, 7) = -1.70;
  matrix1(0, 8) = 0.21;
  matrix1(1, 0) = -1.68;
  matrix1(1, 1) = 0.11;
  matrix1(1, 2) = -0.34;
  matrix1(1, 3) = -1.74;
  matrix1(1, 4) = -0.13;
  matrix1(1, 5) = -0.79;
  matrix1(1, 6) = -0.56;
  matrix1(1, 7) = -1.84;
  matrix1(1, 8) = 1.86;
  matrix1(2, 0) = -1.37;
  matrix1(2, 1) = 0.23;
  matrix1(2, 2) = -0.60;
  matrix1(2, 3) = -1.65;
  matrix1(2, 4) = -1.91;
  matrix1(2, 5) = -0.90;
  matrix1(2, 6) = -0.38;
  matrix1(2, 7) = 0.82;
  matrix1(2, 8) = 1.05;
  matrix1(3, 0) = -1.77;
  matrix1(3, 1) = 1.66;
  matrix1(3, 2) = 0.17;
  matrix1(3, 3) = 0.55;
  matrix1(3, 4) = 1.93;
  matrix1(3, 5) = -0.89;
  matrix1(3, 6) = -0.08;
  matrix1(3, 7) = 1.34;
  matrix1(3, 8) = 1.74;
  matrix1(4, 0) = 0.23;
  matrix1(4, 1) = 1.96;
  matrix1(4, 2) = -0.33;
  matrix1(4, 3) = -1.73;
  matrix1(4, 4) = 0.25;
  matrix1(4, 5) = 1.22;
  matrix1(4, 6) = -0.36;
  matrix1(4, 7) = 1.16;
  matrix1(4, 8) = 1.07;
  matrix1(5, 0) = 0.25;
  matrix1(5, 1) = -0.83;
  matrix1(5, 2) = -1.90;
  matrix1(5, 3) = 0.10;
  matrix1(5, 4) = 0.26;
  matrix1(5, 5) = -1.38;
  matrix1(5, 6) = -0.52;
  matrix1(5, 7) = -0.97;
  matrix1(5, 8) = -0.01;
  matrix1(6, 0) = 1.28;
  matrix1(6, 1) = -1.70;
  matrix1(6, 2) = 1.32;
  matrix1(6, 3) = -1.35;
  matrix1(6, 4) = 0.18;
  matrix1(6, 5) = -0.66;
  matrix1(6, 6) = 1.16;
  matrix1(6, 7) = -0.81;
  matrix1(6, 8) = -1.06;
  matrix1(7, 0) = 0.87;
  matrix1(7, 1) = 1.66;
  matrix1(7, 2) = 0.12;
  matrix1(7, 3) = -1.83;
  matrix1(7, 4) = -1.25;
  matrix1(7, 5) = 0.41;
  matrix1(7, 6) = 1.21;
  matrix1(7, 7) = -1.95;
  matrix1(7, 8) = 0.08;
  matrix1(8, 0) = 1.92;
  matrix1(8, 1) = 1.96;
  matrix1(8, 2) = -1.64;
  matrix1(8, 3) = -0.44;
  matrix1(8, 4) = 1.36;
  matrix1(8, 5) = 0.74;
  matrix1(8, 6) = -0.67;
  matrix1(8, 7) = -1.03;
  matrix1(8, 8) = 1.60;

  double result_check = -63.322314761722227635;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant11) {
  S21Matrix matrix1{11, 11};
  EXPECT_EQ(matrix1.get_cols(), 11);
  EXPECT_EQ(matrix1.get_rows(), 11);

  matrix1(0, 0) = 1.09;
  matrix1(0, 1) = 1.64;
  matrix1(0, 2) = 1.16;
  matrix1(0, 3) = 1.47;
  matrix1(0, 4) = 1.92;
  matrix1(0, 5) = 1.48;
  matrix1(0, 6) = 1.36;
  matrix1(0, 7) = 1.40;
  matrix1(0, 8) = 1.43;
  matrix1(0, 9) = 1.20;
  matrix1(0, 10) = 1.95;
  matrix1(1, 0) = 1.97;
  matrix1(1, 1) = 1.96;
  matrix1(1, 2) = 1.67;
  matrix1(1, 3) = 1.29;
  matrix1(1, 4) = 1.64;
  matrix1(1, 5) = 1.18;
  matrix1(1, 6) = 1.46;
  matrix1(1, 7) = 1.08;
  matrix1(1, 8) = 1.96;
  matrix1(1, 9) = 1.26;
  matrix1(1, 10) = 1.46;
  matrix1(2, 0) = 1.02;
  matrix1(2, 1) = 1.09;
  matrix1(2, 2) = 1.79;
  matrix1(2, 3) = 1.41;
  matrix1(2, 4) = 2.00;
  matrix1(2, 5) = 1.27;
  matrix1(2, 6) = 1.18;
  matrix1(2, 7) = 1.69;
  matrix1(2, 8) = 1.58;
  matrix1(2, 9) = 1.22;
  matrix1(2, 10) = 1.56;
  matrix1(3, 0) = 1.99;
  matrix1(3, 1) = 1.87;
  matrix1(3, 2) = 1.40;
  matrix1(3, 3) = 1.29;
  matrix1(3, 4) = 1.38;
  matrix1(3, 5) = 1.95;
  matrix1(3, 6) = 1.37;
  matrix1(3, 7) = 1.72;
  matrix1(3, 8) = 1.12;
  matrix1(3, 9) = 1.02;
  matrix1(3, 10) = 1.69;
  matrix1(4, 0) = 1.27;
  matrix1(4, 1) = 1.93;
  matrix1(4, 2) = 1.62;
  matrix1(4, 3) = 1.79;
  matrix1(4, 4) = 1.85;
  matrix1(4, 5) = 1.43;
  matrix1(4, 6) = 1.46;
  matrix1(4, 7) = 1.89;
  matrix1(4, 8) = 1.83;
  matrix1(4, 9) = 1.45;
  matrix1(4, 10) = 1.31;
  matrix1(5, 0) = 1.60;
  matrix1(5, 1) = 1.65;
  matrix1(5, 2) = 1.86;
  matrix1(5, 3) = 1.42;
  matrix1(5, 4) = 1.89;
  matrix1(5, 5) = 1.62;
  matrix1(5, 6) = 1.24;
  matrix1(5, 7) = 1.40;
  matrix1(5, 8) = 1.09;
  matrix1(5, 9) = 1.82;
  matrix1(5, 10) = 1.11;
  matrix1(6, 0) = 1.76;
  matrix1(6, 1) = 1.96;
  matrix1(6, 2) = 1.66;
  matrix1(6, 3) = 1.41;
  matrix1(6, 4) = 1.32;
  matrix1(6, 5) = 1.77;
  matrix1(6, 6) = 1.77;
  matrix1(6, 7) = 1.03;
  matrix1(6, 8) = 1.01;
  matrix1(6, 9) = 1.51;
  matrix1(6, 10) = 1.98;
  matrix1(7, 0) = 1.03;
  matrix1(7, 1) = 1.16;
  matrix1(7, 2) = 1.41;
  matrix1(7, 3) = 1.04;
  matrix1(7, 4) = 1.22;
  matrix1(7, 5) = 1.46;
  matrix1(7, 6) = 1.31;
  matrix1(7, 7) = 1.37;
  matrix1(7, 8) = 1.88;
  matrix1(7, 9) = 1.79;
  matrix1(7, 10) = 1.15;
  matrix1(8, 0) = 1.29;
  matrix1(8, 1) = 1.65;
  matrix1(8, 2) = 1.08;
  matrix1(8, 3) = 1.67;
  matrix1(8, 4) = 1.01;
  matrix1(8, 5) = 1.91;
  matrix1(8, 6) = 1.93;
  matrix1(8, 7) = 1.30;
  matrix1(8, 8) = 1.44;
  matrix1(8, 9) = 1.11;
  matrix1(8, 10) = 1.27;
  matrix1(9, 0) = 1.38;
  matrix1(9, 1) = 1.56;
  matrix1(9, 2) = 1.22;
  matrix1(9, 3) = 1.61;
  matrix1(9, 4) = 1.91;
  matrix1(9, 5) = 1.75;
  matrix1(9, 6) = 1.31;
  matrix1(9, 7) = 1.97;
  matrix1(9, 8) = 1.76;
  matrix1(9, 9) = 1.66;
  matrix1(9, 10) = 1.44;
  matrix1(10, 0) = 1.72;
  matrix1(10, 1) = 1.01;
  matrix1(10, 2) = 1.21;
  matrix1(10, 3) = 1.29;
  matrix1(10, 4) = 1.50;
  matrix1(10, 5) = 1.11;
  matrix1(10, 6) = 1.66;
  matrix1(10, 7) = 1.03;
  matrix1(10, 8) = 1.37;
  matrix1(10, 9) = 1.06;
  matrix1(10, 10) = 1.82;

  double result_check = -0.1224542341292035685434;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant12) {
  TEST_TIMEOUT_BEGIN
  S21Matrix matrix1{20, 20};
  EXPECT_EQ(matrix1.get_cols(), 20);
  EXPECT_EQ(matrix1.get_rows(), 20);

  matrix1(0, 0) = 1.07;
  matrix1(0, 1) = 1.63;
  matrix1(0, 2) = 1.91;
  matrix1(0, 3) = 1.95;
  matrix1(0, 4) = 1.78;
  matrix1(0, 5) = 1.24;
  matrix1(0, 6) = 1.74;
  matrix1(0, 7) = 1.54;
  matrix1(0, 8) = 1.82;
  matrix1(0, 9) = 1.86;
  matrix1(0, 10) = 1.26;
  matrix1(0, 11) = 1.50;
  matrix1(0, 12) = 1.74;
  matrix1(0, 13) = 1.26;
  matrix1(0, 14) = 1.99;
  matrix1(0, 15) = 1.76;
  matrix1(0, 16) = 1.66;
  matrix1(0, 17) = 1.26;
  matrix1(0, 18) = 1.85;
  matrix1(0, 19) = 1.06;

  matrix1(1, 0) = 1.55;
  matrix1(1, 1) = 1.36;
  matrix1(1, 2) = 1.65;
  matrix1(1, 3) = 1.99;
  matrix1(1, 4) = 1.18;
  matrix1(1, 5) = 1.24;
  matrix1(1, 6) = 1.53;
  matrix1(1, 7) = 1.03;
  matrix1(1, 8) = 1.40;
  matrix1(1, 9) = 1.54;
  matrix1(1, 10) = 1.66;
  matrix1(1, 11) = 1.64;
  matrix1(1, 12) = 1.29;
  matrix1(1, 13) = 1.98;
  matrix1(1, 14) = 1.85;
  matrix1(1, 15) = 1.40;
  matrix1(1, 16) = 1.38;
  matrix1(1, 17) = 1.64;
  matrix1(1, 18) = 1.65;
  matrix1(1, 19) = 1.33;

  matrix1(2, 0) = 1.51;
  matrix1(2, 1) = 1.09;
  matrix1(2, 2) = 1.58;
  matrix1(2, 3) = 1.15;
  matrix1(2, 4) = 1.25;
  matrix1(2, 5) = 1.49;
  matrix1(2, 6) = 1.73;
  matrix1(2, 7) = 1.03;
  matrix1(2, 8) = 1.54;
  matrix1(2, 9) = 1.90;
  matrix1(2, 10) = 1.32;
  matrix1(2, 11) = 1.13;
  matrix1(2, 12) = 1.22;
  matrix1(2, 13) = 1.25;
  matrix1(2, 14) = 1.82;
  matrix1(2, 15) = 1.35;
  matrix1(2, 16) = 1.09;
  matrix1(2, 17) = 1.03;
  matrix1(2, 18) = 1.14;
  matrix1(2, 19) = 1.70;

  matrix1(3, 0) = 1.34;
  matrix1(3, 1) = 1.15;
  matrix1(3, 2) = 1.75;
  matrix1(3, 3) = 1.59;
  matrix1(3, 4) = 1.94;
  matrix1(3, 5) = 1.60;
  matrix1(3, 6) = 1.56;
  matrix1(3, 7) = 1.63;
  matrix1(3, 8) = 1.83;
  matrix1(3, 9) = 1.41;
  matrix1(3, 10) = 1.57;
  matrix1(3, 11) = 1.38;
  matrix1(3, 12) = 1.56;
  matrix1(3, 13) = 1.46;
  matrix1(3, 14) = 1.59;
  matrix1(3, 15) = 1.19;
  matrix1(3, 16) = 1.17;
  matrix1(3, 17) = 1.71;
  matrix1(3, 18) = 1.52;
  matrix1(3, 19) = 1.07;

  matrix1(4, 0) = 1.89;
  matrix1(4, 1) = 1.10;
  matrix1(4, 2) = 1.45;
  matrix1(4, 3) = 1.47;
  matrix1(4, 4) = 1.58;
  matrix1(4, 5) = 1.91;
  matrix1(4, 6) = 1.84;
  matrix1(4, 7) = 1.12;
  matrix1(4, 8) = 1.76;
  matrix1(4, 9) = 1.25;
  matrix1(4, 10) = 1.60;
  matrix1(4, 11) = 1.48;
  matrix1(4, 12) = 1.17;
  matrix1(4, 13) = 1.87;
  matrix1(4, 14) = 1.31;
  matrix1(4, 15) = 1.57;
  matrix1(4, 16) = 1.96;
  matrix1(4, 17) = 1.25;
  matrix1(4, 18) = 1.31;
  matrix1(4, 19) = 1.83;

  matrix1(5, 0) = 1.67;
  matrix1(5, 1) = 1.24;
  matrix1(5, 2) = 1.31;
  matrix1(5, 3) = 1.24;
  matrix1(5, 4) = 1.70;
  matrix1(5, 5) = 1.23;
  matrix1(5, 6) = 1.97;
  matrix1(5, 7) = 1.28;
  matrix1(5, 8) = 1.07;
  matrix1(5, 9) = 1.05;
  matrix1(5, 10) = 1.46;
  matrix1(5, 11) = 1.38;
  matrix1(5, 12) = 1.19;
  matrix1(5, 13) = 1.50;
  matrix1(5, 14) = 1.66;
  matrix1(5, 15) = 1.82;
  matrix1(5, 16) = 1.82;
  matrix1(5, 17) = 1.45;
  matrix1(5, 18) = 1.39;
  matrix1(5, 19) = 1.88;

  matrix1(6, 0) = 1.70;
  matrix1(6, 1) = 1.10;
  matrix1(6, 2) = 1.33;
  matrix1(6, 3) = 1.57;
  matrix1(6, 4) = 1.42;
  matrix1(6, 5) = 1.79;
  matrix1(6, 6) = 1.31;
  matrix1(6, 7) = 1.73;
  matrix1(6, 8) = 1.34;
  matrix1(6, 9) = 1.40;
  matrix1(6, 10) = 1.25;
  matrix1(6, 11) = 1.81;
  matrix1(6, 12) = 1.35;
  matrix1(6, 13) = 1.07;
  matrix1(6, 14) = 1.85;
  matrix1(6, 15) = 1.49;
  matrix1(6, 16) = 1.17;
  matrix1(6, 17) = 1.12;
  matrix1(6, 18) = 1.08;
  matrix1(6, 19) = 1.94;

  matrix1(7, 0) = 1.23;
  matrix1(7, 1) = 1.86;
  matrix1(7, 2) = 1.83;
  matrix1(7, 3) = 1.70;
  matrix1(7, 4) = 1.89;
  matrix1(7, 5) = 1.10;
  matrix1(7, 6) = 1.14;
  matrix1(7, 7) = 1.76;
  matrix1(7, 8) = 1.83;
  matrix1(7, 9) = 1.69;
  matrix1(7, 10) = 1.75;
  matrix1(7, 11) = 1.57;
  matrix1(7, 12) = 1.01;
  matrix1(7, 13) = 1.58;
  matrix1(7, 14) = 1.82;
  matrix1(7, 15) = 1.67;
  matrix1(7, 16) = 1.99;
  matrix1(7, 17) = 1.38;
  matrix1(7, 18) = 1.54;
  matrix1(7, 19) = 1.13;

  matrix1(8, 0) = 1.13;
  matrix1(8, 1) = 1.83;
  matrix1(8, 2) = 1.56;
  matrix1(8, 3) = 1.46;
  matrix1(8, 4) = 1.31;
  matrix1(8, 5) = 1.01;
  matrix1(8, 6) = 1.36;
  matrix1(8, 7) = 1.86;
  matrix1(8, 8) = 1.37;
  matrix1(8, 9) = 1.23;
  matrix1(8, 10) = 1.56;
  matrix1(8, 11) = 1.27;
  matrix1(8, 12) = 1.00;
  matrix1(8, 13) = 1.54;
  matrix1(8, 14) = 1.83;
  matrix1(8, 15) = 1.15;
  matrix1(8, 16) = 1.83;
  matrix1(8, 17) = 1.69;
  matrix1(8, 18) = 1.35;
  matrix1(8, 19) = 1.71;

  matrix1(9, 0) = 1.69;
  matrix1(9, 1) = 1.62;
  matrix1(9, 2) = 1.78;
  matrix1(9, 3) = 1.07;
  matrix1(9, 4) = 1.95;
  matrix1(9, 5) = 1.90;
  matrix1(9, 6) = 1.02;
  matrix1(9, 7) = 1.91;
  matrix1(9, 8) = 1.83;
  matrix1(9, 9) = 1.17;
  matrix1(9, 10) = 1.79;
  matrix1(9, 11) = 1.34;
  matrix1(9, 12) = 1.38;
  matrix1(9, 13) = 1.78;
  matrix1(9, 14) = 1.40;
  matrix1(9, 15) = 1.99;
  matrix1(9, 16) = 1.59;
  matrix1(9, 17) = 1.05;
  matrix1(9, 18) = 1.17;
  matrix1(9, 19) = 1.61;

  matrix1(10, 0) = 1.10;
  matrix1(10, 1) = 1.05;
  matrix1(10, 2) = 1.52;
  matrix1(10, 3) = 1.54;
  matrix1(10, 4) = 1.30;
  matrix1(10, 5) = 1.60;
  matrix1(10, 6) = 1.86;
  matrix1(10, 7) = 1.51;
  matrix1(10, 8) = 1.37;
  matrix1(10, 9) = 1.02;
  matrix1(10, 10) = 1.92;
  matrix1(10, 11) = 1.48;
  matrix1(10, 12) = 1.02;
  matrix1(10, 13) = 1.60;
  matrix1(10, 14) = 1.24;
  matrix1(10, 15) = 1.52;
  matrix1(10, 16) = 1.66;
  matrix1(10, 17) = 1.91;
  matrix1(10, 18) = 1.09;
  matrix1(10, 19) = 1.61;

  matrix1(11, 0) = 1.42;
  matrix1(11, 1) = 1.09;
  matrix1(11, 2) = 1.45;
  matrix1(11, 3) = 1.51;
  matrix1(11, 4) = 1.76;
  matrix1(11, 5) = 1.37;
  matrix1(11, 6) = 1.09;
  matrix1(11, 7) = 1.14;
  matrix1(11, 8) = 1.42;
  matrix1(11, 9) = 1.81;
  matrix1(11, 10) = 1.96;
  matrix1(11, 11) = 1.01;
  matrix1(11, 12) = 1.78;
  matrix1(11, 13) = 1.86;
  matrix1(11, 14) = 1.30;
  matrix1(11, 15) = 1.39;
  matrix1(11, 16) = 1.25;
  matrix1(11, 17) = 1.49;
  matrix1(11, 18) = 1.26;
  matrix1(11, 19) = 1.33;

  matrix1(12, 0) = 1.53;
  matrix1(12, 1) = 1.71;
  matrix1(12, 2) = 1.31;
  matrix1(12, 3) = 1.14;
  matrix1(12, 4) = 1.67;
  matrix1(12, 5) = 1.81;
  matrix1(12, 6) = 1.76;
  matrix1(12, 7) = 1.44;
  matrix1(12, 8) = 1.34;
  matrix1(12, 9) = 1.07;
  matrix1(12, 10) = 1.27;
  matrix1(12, 11) = 1.32;
  matrix1(12, 12) = 1.93;
  matrix1(12, 13) = 1.26;
  matrix1(12, 14) = 1.74;
  matrix1(12, 15) = 1.25;
  matrix1(12, 16) = 1.23;
  matrix1(12, 17) = 1.81;
  matrix1(12, 18) = 1.84;
  matrix1(12, 19) = 1.17;

  matrix1(13, 0) = 1.58;
  matrix1(13, 1) = 1.19;
  matrix1(13, 2) = 1.05;
  matrix1(13, 3) = 1.09;
  matrix1(13, 4) = 1.49;
  matrix1(13, 5) = 1.57;
  matrix1(13, 6) = 1.65;
  matrix1(13, 7) = 1.06;
  matrix1(13, 8) = 1.86;
  matrix1(13, 9) = 1.15;
  matrix1(13, 10) = 1.69;
  matrix1(13, 11) = 1.85;
  matrix1(13, 12) = 1.46;
  matrix1(13, 13) = 1.66;
  matrix1(13, 14) = 1.76;
  matrix1(13, 15) = 1.26;
  matrix1(13, 16) = 1.58;
  matrix1(13, 17) = 1.95;
  matrix1(13, 18) = 1.45;
  matrix1(13, 19) = 1.26;

  matrix1(14, 0) = 1.79;
  matrix1(14, 1) = 1.64;
  matrix1(14, 2) = 1.78;
  matrix1(14, 3) = 1.51;
  matrix1(14, 4) = 1.05;
  matrix1(14, 5) = 1.25;
  matrix1(14, 6) = 1.79;
  matrix1(14, 7) = 1.64;
  matrix1(14, 8) = 1.99;
  matrix1(14, 9) = 1.24;
  matrix1(14, 10) = 1.49;
  matrix1(14, 11) = 1.87;
  matrix1(14, 12) = 1.64;
  matrix1(14, 13) = 1.30;
  matrix1(14, 14) = 1.76;
  matrix1(14, 15) = 1.20;
  matrix1(14, 16) = 1.37;
  matrix1(14, 17) = 1.37;
  matrix1(14, 18) = 1.89;
  matrix1(14, 19) = 1.96;

  matrix1(15, 0) = 1.91;
  matrix1(15, 1) = 1.69;
  matrix1(15, 2) = 1.12;
  matrix1(15, 3) = 1.82;
  matrix1(15, 4) = 1.02;
  matrix1(15, 5) = 1.92;
  matrix1(15, 6) = 1.97;
  matrix1(15, 7) = 1.15;
  matrix1(15, 8) = 1.64;
  matrix1(15, 9) = 1.28;
  matrix1(15, 10) = 1.96;
  matrix1(15, 11) = 1.87;
  matrix1(15, 12) = 1.39;
  matrix1(15, 13) = 1.86;
  matrix1(15, 14) = 1.59;
  matrix1(15, 15) = 1.38;
  matrix1(15, 16) = 1.99;
  matrix1(15, 17) = 1.28;
  matrix1(15, 18) = 1.74;
  matrix1(15, 19) = 1.08;

  matrix1(16, 0) = 1.98;
  matrix1(16, 1) = 1.70;
  matrix1(16, 2) = 1.42;
  matrix1(16, 3) = 1.27;
  matrix1(16, 4) = 1.86;
  matrix1(16, 5) = 1.63;
  matrix1(16, 6) = 1.63;
  matrix1(16, 7) = 1.68;
  matrix1(16, 8) = 1.36;
  matrix1(16, 9) = 1.84;
  matrix1(16, 10) = 1.21;
  matrix1(16, 11) = 1.29;
  matrix1(16, 12) = 1.19;
  matrix1(16, 13) = 1.09;
  matrix1(16, 14) = 1.54;
  matrix1(16, 15) = 1.59;
  matrix1(16, 16) = 1.69;
  matrix1(16, 17) = 1.87;
  matrix1(16, 18) = 1.91;
  matrix1(16, 19) = 1.45;

  matrix1(17, 0) = 1.57;
  matrix1(17, 1) = 1.73;
  matrix1(17, 2) = 1.21;
  matrix1(17, 3) = 1.20;
  matrix1(17, 4) = 1.36;
  matrix1(17, 5) = 1.11;
  matrix1(17, 6) = 1.90;
  matrix1(17, 7) = 1.43;
  matrix1(17, 8) = 1.20;
  matrix1(17, 9) = 1.34;
  matrix1(17, 10) = 1.78;
  matrix1(17, 11) = 1.03;
  matrix1(17, 12) = 1.60;
  matrix1(17, 13) = 1.00;
  matrix1(17, 14) = 1.62;
  matrix1(17, 15) = 1.75;
  matrix1(17, 16) = 1.26;
  matrix1(17, 17) = 1.73;
  matrix1(17, 18) = 1.53;
  matrix1(17, 19) = 1.41;

  matrix1(18, 0) = 1.10;
  matrix1(18, 1) = 1.27;
  matrix1(18, 2) = 1.92;
  matrix1(18, 3) = 1.09;
  matrix1(18, 4) = 1.89;
  matrix1(18, 5) = 1.52;
  matrix1(18, 6) = 1.79;
  matrix1(18, 7) = 1.16;
  matrix1(18, 8) = 1.50;
  matrix1(18, 9) = 1.44;
  matrix1(18, 10) = 1.47;
  matrix1(18, 11) = 1.30;
  matrix1(18, 12) = 1.01;
  matrix1(18, 13) = 1.93;
  matrix1(18, 14) = 1.58;
  matrix1(18, 15) = 1.97;
  matrix1(18, 16) = 1.69;
  matrix1(18, 17) = 1.28;
  matrix1(18, 18) = 1.39;
  matrix1(18, 19) = 1.37;

  matrix1(19, 0) = 1.30;
  matrix1(19, 1) = 1.05;
  matrix1(19, 2) = 1.81;
  matrix1(19, 3) = 1.11;
  matrix1(19, 4) = 1.88;
  matrix1(19, 5) = 1.42;
  matrix1(19, 6) = 1.41;
  matrix1(19, 7) = 1.15;
  matrix1(19, 8) = 1.17;
  matrix1(19, 9) = 1.87;
  matrix1(19, 10) = 1.90;
  matrix1(19, 11) = 1.56;
  matrix1(19, 12) = 1.48;
  matrix1(19, 13) = 1.97;
  matrix1(19, 14) = 1.23;
  matrix1(19, 15) = 1.27;
  matrix1(19, 16) = 1.36;
  matrix1(19, 17) = 1.27;
  matrix1(19, 18) = 1.48;
  matrix1(19, 19) = 1.53;

  double result_check = 0.0358009468269194807741324658459869567154;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, s21_matrix_test_helper::kEpsilon);
  EXPECT_TRUE(matrix1 == matrix_before);
  TEST_TIMEOUT_END
}
