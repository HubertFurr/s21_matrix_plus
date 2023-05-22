#include "./../../test.h"

TEST(TestExtra, TestOperatorBracketsConst2) {
  const S21Matrix matrix_check{3, 3};
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

  // Расскомментировать, чтобы проверить наличие ошибки при компиляции
  // (конст матрицы нельзя менять!)
  // matrix_check(0, 0) = 1.0;
  // matrix_check(0, 1) = 2.0;
  // matrix_check(1, 0) = 3.0;
  // matrix_check(1, 1) = 4.0;
}

TEST(TestExtra, TestOperatorBracketsParrot) {
  // Расскомментировать, чтобы проверить, позволяет ли класс получать висячие
  // ссылки
  // S21Matrix matrix_check;
  // double& y = matrix_check(0, 0);
  // // double& z = S21Matrix{}(0,0);
  // // const double& zz = S21Matrix{}(0, 0);

  // std::cout << y << std::endl;
  // // std::cout << z << std::endl;
  // // std::cout << zz << std::endl;

  // const S21Matrix matrix_check_const;

  // // double& cy = matrix_check_const(0, 0);
  // const double& ccy = matrix_check_const(0, 0);
  // // double& cz = S21Matrix{}(0,0);
  // // const double& czz = S21Matrix{}(0, 0);

  // // std::cout << cy << std::endl;
  // std::cout << ccy << std::endl;
  // // std::cout << cz << std::endl;
  // // std::cout << czz << std::endl;
}

// Просто проверяем, что данные операции компилируются и выполняются
TEST(TestExtra, TestConstRef1) {
  S21Matrix result1 = S21Matrix(1, 1) + S21Matrix(1, 1);
  S21Matrix result2 = S21Matrix(1, 1) - S21Matrix(1, 1);
  S21Matrix result3 = S21Matrix(1, 1) * S21Matrix(1, 1);
  bool result4 = S21Matrix(1, 1) == S21Matrix(1, 1);
  S21Matrix result5 = S21Matrix(1, 1) * 2.0;
  S21Matrix result6 = 2.0 * S21Matrix(1, 1);

  EXPECT_TRUE(result1 == S21Matrix(1, 1));
  EXPECT_TRUE(result2 == S21Matrix(1, 1));
  EXPECT_TRUE(result3 == S21Matrix(1, 1));
  EXPECT_TRUE(result4);
  EXPECT_TRUE(result5 == S21Matrix(1, 1));
  EXPECT_TRUE(result6 == S21Matrix(1, 1));
}
