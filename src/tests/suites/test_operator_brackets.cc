#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestOperatorBrackets, TestOperatorBracketsException1) {
  S21Matrix matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(100, 99));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException2) {
  S21Matrix matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(99, 100));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException3) {
  S21Matrix matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(100, 100));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException4) {
  S21Matrix matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(6, 5));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException5) {
  S21Matrix matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(5, 6));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException6) {
  S21Matrix matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(999, 999));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException7) {
  S21Matrix matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(-1, 0));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException8) {
  S21Matrix matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(0, -1));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException9) {
  S21Matrix matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(-1, -1));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException10) {
  S21Matrix matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0);
  EXPECT_ANY_THROW(matrix_check(-99, -99));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного доступа к полям
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestOperatorBrackets, TestOperatorBrackets1) {
  S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.get_rows(), 3);
  EXPECT_EQ(matrix_check.get_cols(), 3);

  ASSERT_NEAR(matrix_check(0, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(0, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, s21_matrix_test_helper::epsilon_);

  matrix_check(0, 0) = 1.0;
  matrix_check(0, 1) = 2.0;
  matrix_check(1, 0) = 3.0;
  matrix_check(1, 1) = 4.0;

  ASSERT_NEAR(matrix_check(0, 0), 1.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(0, 1), 2.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 0), 3.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 1), 4.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, s21_matrix_test_helper::epsilon_);
}

TEST(TestOperatorBrackets, TestOperatorBracketsConst1) {
  S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.get_rows(), 3);
  EXPECT_EQ(matrix_check.get_cols(), 3);

  ASSERT_NEAR(matrix_check(0, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(0, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, s21_matrix_test_helper::epsilon_);

  matrix_check(0, 0) = 1.0;
  matrix_check(0, 1) = 2.0;
  matrix_check(1, 0) = 3.0;
  matrix_check(1, 1) = 4.0;

  ASSERT_NEAR(matrix_check(0, 0), 1.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(0, 1), 2.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 0), 3.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 1), 4.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, s21_matrix_test_helper::epsilon_);

  const S21Matrix matrix_copy = matrix_check;

  ASSERT_NEAR(matrix_copy(0, 0), 1.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_copy(0, 1), 2.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_copy(0, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_copy(1, 0), 3.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_copy(1, 1), 4.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_copy(1, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_copy(2, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_copy(2, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_copy(2, 2), 0.0, s21_matrix_test_helper::epsilon_);
}

TEST(TestOperatorBrackets, TestOperatorBracketsConst2) {
  const S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.get_rows(), 3);
  EXPECT_EQ(matrix_check.get_cols(), 3);

  ASSERT_NEAR(matrix_check(0, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(0, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, s21_matrix_test_helper::epsilon_);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, s21_matrix_test_helper::epsilon_);

  // Расскомментировать, чтобы проверить наличие ошибки при компиляции
  // (конст матрицы нельзя менять!)
  // matrix_check(0, 0) = 1.0;
  // matrix_check(0, 1) = 2.0;
  // matrix_check(1, 0) = 3.0;
  // matrix_check(1, 1) = 4.0;
}
