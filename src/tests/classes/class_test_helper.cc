#include "class_test_helper.h"

#include <gtest/gtest.h>

#include <random>
namespace s21_matrix_test_helper {
void Print(const S21Matrix& matrix) {
  std::cout.precision(10);
  // std::cout.setf(std::ios::fixed);
  std::cout << "[" << matrix.get_rows() << " x " << matrix.get_cols() << "]"
            << std::endl;
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      std::cout << matrix(i, j);
      if (j != matrix.get_cols() - 1) {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }
  std::cout << std::endl;
}

/**
 * @brief формат для https://www.wolframalpha.com/
 *
 * @param matrix
 */
void PrintWolfram(const S21Matrix& matrix) {
  std::cout.precision(0);
  std::cout.setf(std::ios::fixed);
  std::cout << "[{";
  for (int i = 0; i < matrix.get_rows(); ++i) {
    std::cout << "{";
    for (int j = 0; j < matrix.get_cols(); ++j) {
      std::cout << matrix(i, j);
      if (j != matrix.get_cols() - 1) {
        std::cout << ",";
      }
    }
    std::cout << "}";
    if (i != matrix.get_rows() - 1) {
      std::cout << ",";
    }
  }
  std::cout << "}]" << std::endl;
}

/**
 * @brief формат для https://planetcalc.ru/8351/
 *
 * @param matrix
 */
void PrintPlanet(const S21Matrix& matrix) {
  std::cout.precision(2);
  std::cout.setf(std::ios::fixed);
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      std::cout << matrix(i, j);
      if (j != matrix.get_cols() - 1) {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

/**
 * @brief формат для https://www.mathway.com/ru/Precalculus
 *
 * @param matrix
 */
void PrintMathway(const S21Matrix& matrix) {
  std::cout.precision(2);
  std::cout.setf(std::ios::fixed);
  std::cout << "[";
  for (int i = 0; i < matrix.get_rows(); ++i) {
    std::cout << "[";
    for (int j = 0; j < matrix.get_cols(); ++j) {
      std::cout << matrix(i, j);
      if (j != matrix.get_cols() - 1) {
        std::cout << ",";
      }
    }
    std::cout << "]";
    if (i != matrix.get_rows() - 1) {
      std::cout << ",";
    }
  }
  std::cout << "]" << std::endl;
}

void PrintTest(const S21Matrix& matrix) {
  std::cout.precision(0);
  std::cout.setf(std::ios::fixed);
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      std::cout << "matrix1(" << i << ", " << j << ") = " << matrix(i, j) << ";"
                << std::endl;
    }
  }
}

int GetRandInt(int min, int max) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> distr(min, max);
  return distr(generator);
}

double GetRandDouble(double min, double max) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_real_distribution<double> distr(min, max);
  return distr(generator);
}

S21Matrix RandomS21Matrix(int rows, int cols) {
  S21Matrix result{rows, cols};

  for (int i = 0; i < result.get_rows(); ++i) {
    for (int j = 0; j < result.get_cols(); ++j) {
      result(i, j) = s21_matrix_test_helper::GetRandDouble(-1, 1);
    }
  }

  return result;
}

void FillS21Matrix(S21Matrix& matrix, double value) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      matrix(i, j) = value;
    }
  }
}

void CheckS21Matrix(const S21Matrix& matrix, double value) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      ASSERT_NEAR(matrix(i, j), value, epsilon_);
    }
  }
}
}  // namespace s21_matrix_test_helper
