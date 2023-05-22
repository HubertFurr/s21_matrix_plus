#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на обычные матрицы
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestTranspose, TestTranspose1) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  S21Matrix result_check{99, 95};
  EXPECT_EQ(result_check.get_rows(), 99);
  EXPECT_EQ(result_check.get_cols(), 95);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.99);
  s21_matrix_test_helper::FillMatrix(result_check, 1.99);

  s21_matrix_test_helper::CheckMatrix(matrix1, 1.99);
  s21_matrix_test_helper::CheckMatrix(result_check, 1.99);

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose2) {
  S21Matrix matrix1{99, 95};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 95);

  S21Matrix result_check{95, 99};
  EXPECT_EQ(result_check.get_rows(), 95);
  EXPECT_EQ(result_check.get_cols(), 99);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0);
  s21_matrix_test_helper::CheckMatrix(result_check, 0.0);

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose3) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  S21Matrix result_check{99, 99};
  EXPECT_EQ(result_check.get_rows(), 99);
  EXPECT_EQ(result_check.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, -1.5);
  s21_matrix_test_helper::FillMatrix(result_check, -1.5);

  s21_matrix_test_helper::CheckMatrix(matrix1, -1.5);
  s21_matrix_test_helper::CheckMatrix(result_check, -1.5);

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose4) {
  S21Matrix matrix1{1, 4};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 4);

  S21Matrix result_check{4, 1};
  EXPECT_EQ(result_check.get_rows(), 4);
  EXPECT_EQ(result_check.get_cols(), 1);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(0, 3) = 4;

  result_check(0, 0) = 1;
  result_check(1, 0) = 2;
  result_check(2, 0) = 3;
  result_check(3, 0) = 4;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose5) {
  S21Matrix matrix1{4, 1};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 1);

  S21Matrix result_check{1, 4};
  EXPECT_EQ(result_check.get_rows(), 1);
  EXPECT_EQ(result_check.get_cols(), 4);

  matrix1(0, 0) = 1;
  matrix1(1, 0) = 2;
  matrix1(2, 0) = 3;
  matrix1(3, 0) = 4;

  result_check(0, 0) = 1;
  result_check(0, 1) = 2;
  result_check(0, 2) = 3;
  result_check(0, 3) = 4;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose6) {
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

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose7) {
  S21Matrix matrix1{3, 2};
  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 2);

  S21Matrix result_check{2, 3};
  EXPECT_EQ(result_check.get_rows(), 2);
  EXPECT_EQ(result_check.get_cols(), 3);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = 6;

  result_check(0, 0) = 1;
  result_check(1, 0) = 2;
  result_check(0, 1) = 3;
  result_check(1, 1) = 4;
  result_check(0, 2) = 5;
  result_check(1, 2) = 6;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose8) {
  S21Matrix matrix1{7, 7};
  EXPECT_EQ(matrix1.get_rows(), 7);
  EXPECT_EQ(matrix1.get_cols(), 7);

  S21Matrix result_check{7, 7};
  EXPECT_EQ(result_check.get_rows(), 7);
  EXPECT_EQ(result_check.get_cols(), 7);

  matrix1(0, 0) = 1.91308;
  matrix1(0, 1) = 0.60095;
  matrix1(0, 2) = -0.44777;
  matrix1(0, 3) = -0.50040;
  matrix1(0, 4) = -1.12823;
  matrix1(0, 5) = -1.81865;
  matrix1(0, 6) = -0.70084;
  matrix1(1, 0) = 1.95162;
  matrix1(1, 1) = 1.16720;
  matrix1(1, 2) = 1.28391;
  matrix1(1, 3) = -1.83298;
  matrix1(1, 4) = 1.30395;
  matrix1(1, 5) = -1.94659;
  matrix1(1, 6) = 0.92036;
  matrix1(2, 0) = -1.49041;
  matrix1(2, 1) = 1.08027;
  matrix1(2, 2) = 1.69253;
  matrix1(2, 3) = 0.59772;
  matrix1(2, 4) = 0.36828;
  matrix1(2, 5) = -0.47550;
  matrix1(2, 6) = 0.17188;
  matrix1(3, 0) = -0.41712;
  matrix1(3, 1) = -0.57195;
  matrix1(3, 2) = -1.52959;
  matrix1(3, 3) = 0.79822;
  matrix1(3, 4) = -0.81870;
  matrix1(3, 5) = -0.71609;
  matrix1(3, 6) = -1.58015;
  matrix1(4, 0) = -0.90661;
  matrix1(4, 1) = -0.09334;
  matrix1(4, 2) = 0.63205;
  matrix1(4, 3) = 1.27734;
  matrix1(4, 4) = 0.34700;
  matrix1(4, 5) = -0.91391;
  matrix1(4, 6) = 0.63581;
  matrix1(5, 0) = 1.30982;
  matrix1(5, 1) = 1.27461;
  matrix1(5, 2) = 0.56120;
  matrix1(5, 3) = -0.54912;
  matrix1(5, 4) = 1.28915;
  matrix1(5, 5) = 0.63719;
  matrix1(5, 6) = 0.38849;
  matrix1(6, 0) = -0.53430;
  matrix1(6, 1) = -0.10767;
  matrix1(6, 2) = 1.19456;
  matrix1(6, 3) = 0.05376;
  matrix1(6, 4) = 0.83746;
  matrix1(6, 5) = -0.85603;
  matrix1(6, 6) = -0.73690;

  result_check(0, 0) = 1.91308;
  result_check(0, 1) = 1.95162;
  result_check(0, 2) = -1.49041;
  result_check(0, 3) = -0.41712;
  result_check(0, 4) = -0.90661;
  result_check(0, 5) = 1.30982;
  result_check(0, 6) = -0.5343;
  result_check(1, 0) = 0.60095;
  result_check(1, 1) = 1.1672;
  result_check(1, 2) = 1.08027;
  result_check(1, 3) = -0.57195;
  result_check(1, 4) = -0.09334;
  result_check(1, 5) = 1.27461;
  result_check(1, 6) = -0.10767;
  result_check(2, 0) = -0.44777;
  result_check(2, 1) = 1.28391;
  result_check(2, 2) = 1.69253;
  result_check(2, 3) = -1.52959;
  result_check(2, 4) = 0.63205;
  result_check(2, 5) = 0.56120;
  result_check(2, 6) = 1.19456;
  result_check(3, 0) = -0.5004;
  result_check(3, 1) = -1.83298;
  result_check(3, 2) = 0.59772;
  result_check(3, 3) = 0.79822;
  result_check(3, 4) = 1.27734;
  result_check(3, 5) = -0.54912;
  result_check(3, 6) = 0.05376;
  result_check(4, 0) = -1.12823;
  result_check(4, 1) = 1.30395;
  result_check(4, 2) = 0.36828;
  result_check(4, 3) = -0.81870;
  result_check(4, 4) = 0.347;
  result_check(4, 5) = 1.28915;
  result_check(4, 6) = 0.83746;
  result_check(5, 0) = -1.81865;
  result_check(5, 1) = -1.94659;
  result_check(5, 2) = -0.47550;
  result_check(5, 3) = -0.71609;
  result_check(5, 4) = -0.91391;
  result_check(5, 5) = 0.63719;
  result_check(5, 6) = -0.85603;
  result_check(6, 0) = -0.70084;
  result_check(6, 1) = 0.92036;
  result_check(6, 2) = 0.17188;
  result_check(6, 3) = -1.58015;
  result_check(6, 4) = 0.63581;
  result_check(6, 5) = 0.38849;
  result_check(6, 6) = -0.73690;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose9) {
  S21Matrix matrix1{1, 20};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 20);

  S21Matrix result_check{20, 1};
  EXPECT_EQ(result_check.get_rows(), 20);
  EXPECT_EQ(result_check.get_cols(), 1);

  matrix1(0, 0) = -1.32;
  matrix1(0, 1) = -1.36;
  matrix1(0, 2) = -0.09;
  matrix1(0, 3) = -0.06;
  matrix1(0, 4) = 0.49;
  matrix1(0, 5) = 0.09;
  matrix1(0, 6) = 0.61;
  matrix1(0, 7) = -1.45;
  matrix1(0, 8) = 0.55;
  matrix1(0, 9) = -0.34;
  matrix1(0, 10) = 1.26;
  matrix1(0, 11) = -1.58;
  matrix1(0, 12) = 1.29;
  matrix1(0, 13) = -1.57;
  matrix1(0, 14) = 1.62;
  matrix1(0, 15) = 1.85;
  matrix1(0, 16) = 0.34;
  matrix1(0, 17) = -0.09;
  matrix1(0, 18) = 1.22;
  matrix1(0, 19) = 0.58;

  result_check(0, 0) = -1.32;
  result_check(1, 0) = -1.36;
  result_check(2, 0) = -0.09;
  result_check(3, 0) = -0.06;
  result_check(4, 0) = 0.49;
  result_check(5, 0) = 0.09;
  result_check(6, 0) = 0.61;
  result_check(7, 0) = -1.45;
  result_check(8, 0) = 0.55;
  result_check(9, 0) = -0.34;
  result_check(10, 0) = 1.26;
  result_check(11, 0) = -1.58;
  result_check(12, 0) = 1.29;
  result_check(13, 0) = -1.57;
  result_check(14, 0) = 1.62;
  result_check(15, 0) = 1.85;
  result_check(16, 0) = 0.34;
  result_check(17, 0) = -0.09;
  result_check(18, 0) = 1.22;
  result_check(19, 0) = 0.58;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}
