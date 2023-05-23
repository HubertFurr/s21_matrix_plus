#include <chrono>
#include <iostream>

#include "./../../test.h"

TEST(TestSpeed, TestCreate1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]" << std::endl;

  double** matrix1 = nullptr;
  double* matrix2 = nullptr;

  auto start1 = std::chrono::steady_clock::now();
  matrix1 = new double* [rows] {};
  for (int i = 0; i < rows; ++i) {
    matrix1[i] = new double[cols]{};
  }
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "new double**: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  auto start2 = std::chrono::steady_clock::now();
  matrix2 = new double[rows * cols]{};
  auto end2 = std::chrono::steady_clock::now();
  auto diff2 = end2 - start2;
  std::cout
      << "new double*: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  for (int i = 0; i < rows; ++i) {
    delete[] matrix1[i];
  }
  delete[] matrix1;
  matrix1 = nullptr;
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "delete double**: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start2 = std::chrono::steady_clock::now();
  delete[] matrix2;
  matrix2 = nullptr;
  end2 = std::chrono::steady_clock::now();
  diff2 = end2 - start2;
  std::cout
      << "delete double*: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
      << " ms)" << std::endl;

  start2 = std::chrono::steady_clock::now();
  S21Matrix{rows, cols};
  end2 = std::chrono::steady_clock::now();
  diff2 = end2 - start2;
  std::cout
      << "new matrix"
      << "[" << rows << " x " << cols << "]"
      << ": "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestCreate2) {
  int rows = 512;
  int cols = 512;
  std::cout << "[" << rows << " x " << cols << "]" << std::endl;

  double** matrix1 = nullptr;
  double* matrix2 = nullptr;

  auto start1 = std::chrono::steady_clock::now();
  matrix1 = new double* [rows] {};
  for (int i = 0; i < rows; ++i) {
    matrix1[i] = new double[cols]{};
  }
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "new double**: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  auto start2 = std::chrono::steady_clock::now();
  matrix2 = new double[rows * cols]{};
  auto end2 = std::chrono::steady_clock::now();
  auto diff2 = end2 - start2;
  std::cout
      << "new double*: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  for (int i = 0; i < rows; ++i) {
    delete[] matrix1[i];
  }
  delete[] matrix1;
  matrix1 = nullptr;
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "delete double**: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start2 = std::chrono::steady_clock::now();
  delete[] matrix2;
  matrix2 = nullptr;
  end2 = std::chrono::steady_clock::now();
  diff2 = end2 - start2;
  std::cout
      << "delete double*: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start2 = std::chrono::steady_clock::now();
  S21Matrix{rows, cols};
  end2 = std::chrono::steady_clock::now();
  diff2 = end2 - start2;
  std::cout
      << "new matrix"
      << "[" << rows << " x " << cols << "]"
      << ": "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestCopy1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]" << std::endl;

  S21Matrix matrix1(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.1);

  auto start = std::chrono::steady_clock::now();
  S21Matrix matrix2(matrix1);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "Copy matrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMove1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]" << std::endl;

  S21Matrix matrix1(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.1);
  S21Matrix matrix_copy1 = matrix1;
  S21Matrix matrix_copy2 = matrix1;

  auto start = std::chrono::steady_clock::now();
  S21Matrix matrix2(std::move(matrix1));
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "Move ctor(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;

  start = std::chrono::steady_clock::now();
  matrix_copy1 = std::move(matrix_copy2);
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout
      << "Move assign(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestSum1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]"
            << " + "
            << "[" << rows << " x " << cols << "]" << std::endl;

  S21Matrix matrix1(rows, cols);
  S21Matrix matrix2(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start = std::chrono::steady_clock::now();
  matrix1.SumMatrix(matrix2);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "SumMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;

  start = std::chrono::steady_clock::now();
  S21Matrix result = matrix1 + matrix2;
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout
      << "operator+(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestSum2) {
  int rows = 51200;
  int cols = 1;
  std::cout << "[" << rows << " x " << cols << "]"
            << " + "
            << "[" << rows << " x " << cols << "]" << std::endl;

  S21Matrix matrix1(rows, cols);
  S21Matrix matrix2(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start = std::chrono::steady_clock::now();
  matrix1.SumMatrix(matrix2);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "SumMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;

  start = std::chrono::steady_clock::now();
  S21Matrix result = matrix1 + matrix2;
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout
      << "operator+(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestSub1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]"
            << " - "
            << "[" << rows << " x " << cols << "]" << std::endl;

  S21Matrix matrix1(rows, cols);
  S21Matrix matrix2(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start = std::chrono::steady_clock::now();
  matrix1.SubMatrix(matrix2);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "SubMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;

  start = std::chrono::steady_clock::now();
  S21Matrix result = matrix1 - matrix2;
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout
      << "operator-(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestSub2) {
  int rows = 51200;
  int cols = 1;
  std::cout << "[" << rows << " x " << cols << "]"
            << " - "
            << "[" << rows << " x " << cols << "]" << std::endl;

  S21Matrix matrix1(rows, cols);
  S21Matrix matrix2(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start = std::chrono::steady_clock::now();
  matrix1.SubMatrix(matrix2);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "SubMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;

  start = std::chrono::steady_clock::now();
  S21Matrix result = matrix1 - matrix2;
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout
      << "operator-(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulMatrix1) {
  int rows = 1024;
  int cols = 1024;

  S21Matrix matrix1(rows, cols);
  S21Matrix matrix2(rows, cols);
  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  S21Matrix matrix3 = matrix1;

  auto start1 = std::chrono::steady_clock::now();
  matrix1.MulMatrix(matrix2);
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "MulMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  S21Matrix result = matrix3 * matrix2;
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "operator*(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulMatrix2) {
  int rows = 1024;
  int cols = 1024;

  S21Matrix matrix1(rows, cols);
  S21Matrix matrix2(rows, cols);
  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start1 = std::chrono::steady_clock::now();
  S21Matrix result = matrix1 * matrix2;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "operator*(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulMatrix(matrix2);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulMatrix3) {
  int rows = 2048;
  int cols = 2048;

  S21Matrix matrix1(rows, cols);
  S21Matrix matrix2(cols, 1);

  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << 1 << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start1 = std::chrono::steady_clock::now();
  S21Matrix result = matrix1 * matrix2;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "operator*(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulMatrix(matrix2);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulMatrix4) {
  int rows = 512;
  int cols = 784;

  S21Matrix matrix1(rows, cols);
  S21Matrix matrix2(cols, 1);

  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << 1 << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start1 = std::chrono::steady_clock::now();
  S21Matrix result = matrix1 * matrix2;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "operator*(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulMatrix(matrix2);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulNumber1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]"
            << " * 2.0" << std::endl;

  S21Matrix matrix1(rows, cols);
  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);

  auto start1 = std::chrono::steady_clock::now();
  S21Matrix result = matrix1 * 2.0;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "opeartor*(number): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulNumber(2.0);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulNumber(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulNumber2) {
  int rows = 51200;
  int cols = 1;
  std::cout << "[" << rows << " x " << cols << "]"
            << " * 2.0" << std::endl;

  S21Matrix matrix1(rows, cols);
  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);

  auto start1 = std::chrono::steady_clock::now();
  S21Matrix result = matrix1 * 2.0;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "opeartor*(number): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulNumber(2.0);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulNumber(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestEq1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]"
            << " == "
            << "[" << rows << " x " << cols << "]" << std::endl;

  S21Matrix matrix1(rows, cols);
  S21Matrix matrix2(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 1.0);

  auto start1 = std::chrono::steady_clock::now();
  bool result = matrix1 == matrix2;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "Equal matrix: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
  EXPECT_TRUE(result);
}