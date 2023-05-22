#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений конструкторов
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConstructor, TestConstructorException1) {
  EXPECT_ANY_THROW(S21Matrix(-1, 99));
}

TEST(TestConstructor, TestConstructorException2) {
  EXPECT_ANY_THROW(S21Matrix(99, -1));
}

TEST(TestConstructor, TestConstructorException3) {
  EXPECT_ANY_THROW(S21Matrix(-1, -1));
}

TEST(TestConstructor, TestConstructorException4) {
  EXPECT_ANY_THROW(S21Matrix(-99, -99));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного создания объектов
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты операторов присваивания
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConstructor, TestAssignmentCopy) {
  S21Matrix matrix_test{5, 5};
  S21Matrix matrix_check{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix_test, 2.0);
  s21_matrix_test_helper::FillMatrix(matrix_check, 5.0);

  matrix_check = matrix_test;

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 5);

  s21_matrix_test_helper::CheckMatrix(matrix_test, 2.0);
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestConstructor, TestAssignmentMove1) {
  S21Matrix matrix_test{5, 5};
  S21Matrix matrix_check{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix_test, 2.0);
  s21_matrix_test_helper::FillMatrix(matrix_check, 5.0);

  matrix_check = s21_matrix_test_helper::TestMoveConstructor(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 5);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestConstructor, TestAssignmentMove2) {
  S21Matrix matrix_test{5, 5};
  S21Matrix matrix_check{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix_test, 2.0);
  s21_matrix_test_helper::FillMatrix(matrix_check, 5.0);

  matrix_check = std::move(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_rows(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}
