#include "test_helper.h"

#include <gtest/gtest.h>

#include <random>

namespace s21_matrix_test_helper {

S21Matrix TestMoveConstructor(S21Matrix test) { return test; }

void Print(const S21Matrix& matrix) {
  // std::cout.precision(10);
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
  // std::cout.precision(0);
  // std::cout.setf(std::ios::fixed);
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
  // std::cout.precision(2);
  // std::cout.setf(std::ios::fixed);
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

/**
 * @brief Формат для gtest
 *
 * @param matrix
 */
void PrintTest(const S21Matrix& matrix) {
  // std::cout.precision(0);
  // std::cout.setf(std::ios::fixed);
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
  std::uniform_int_distribution<> distribution(min, max);
  return distribution(generator);
}

double GetRandDouble(double min, double max) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_real_distribution<double> distribution(min, max);
  return distribution(generator);
}

S21Matrix GetRandMatrix(int rows, int cols, double min, double max) {
  S21Matrix result{rows, cols};

  for (int i = 0; i < result.get_rows(); ++i) {
    for (int j = 0; j < result.get_cols(); ++j) {
      result(i, j) = s21_matrix_test_helper::GetRandDouble(min, max);
    }
  }

  return result;
}

void FillMatrix(S21Matrix& matrix, double value) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      matrix(i, j) = value;
    }
  }
}

void CheckMatrix(const S21Matrix& matrix, double value) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      ASSERT_NEAR(matrix(i, j), value, s21_matrix_test_helper::kEpsilon);
    }
  }
}

void TestInverse(const S21Matrix& matrix) {
  S21Matrix matrix_before = matrix;
  double det = matrix.Determinant();
  if (std::abs(det) < s21_matrix_test_helper::kEpsilon) {
    EXPECT_ANY_THROW(matrix.InverseMatrix());
  } else {
    S21Matrix matrix_inverse = matrix.InverseMatrix();
    S21Matrix matrix_mult = matrix * matrix_inverse;
    S21Matrix matrix_identity =
        s21_matrix_test_helper::GetIdentityMatrix(matrix.get_rows());
    EXPECT_TRUE(matrix_mult == matrix_identity);
  }
  EXPECT_TRUE(matrix == matrix_before);
}

/**
 * @brief Возвращает единичную матрицу [size x size].
 *
 * @details
 * Для матрицы 0×0 единичная матрица будет тоже 0×0 - это не косяк,
 * действительно для пустой матрицы размерности 0×0 матрица является собственной
 * обратной.
 * via: https://ru.frwiki.wiki/wiki/Matrice_vide
 *
 * @param size
 * @return S21Matrix
 */
S21Matrix GetIdentityMatrix(int size) {
  S21Matrix result{size, size};

  for (int i = 0; i < result.get_rows(); i++) {
    for (int j = 0; j < result.get_cols(); j++) {
      if (i == j) {
        result(i, j) = 1.0;
      }
    }
  }

  return result;
}

}  // namespace s21_matrix_test_helper
