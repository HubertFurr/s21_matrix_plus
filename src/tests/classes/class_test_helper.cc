#include "class_test_helper.h"

#include <gtest/gtest.h>

#include <random>

void S21TestHelper::Print(const S21Matrix& matrix) {
  // std::cout.precision(14);;
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

void S21TestHelper::PrintWolfram(const S21Matrix& matrix) {
  std::cout.precision(2);
  std::cout.setf(std::ios::fixed);
  std::cout << "det{";
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
  std::cout << "}" << std::endl;
}

void S21TestHelper::PrintPlanet(const S21Matrix& matrix) {
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

void S21TestHelper::PrintTest(const S21Matrix& matrix) {
  std::cout.precision(2);
  std::cout.setf(std::ios::fixed);
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      std::cout << "matrix1(" << i << ", " << j << ") = " << matrix(i, j) << ";"
                << std::endl;
    }
  }
}

int S21TestHelper::GetRandInt(const int min, const int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);
  return distr(gen);
}

double S21TestHelper::GetRandDouble(const double min, const double max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> distr(min, max);
  return distr(gen);
}

S21Matrix S21TestHelper::RandomS21Matrix(const int rows, const int cols) {
  S21Matrix result{rows, cols};

  for (int i = 0; i < result.get_rows(); ++i) {
    for (int j = 0; j < result.get_cols(); ++j) {
      result(i, j) = S21TestHelper::GetRandDouble(-2, 2);
    }
  }

  return result;
}

void S21TestHelper::FillS21Matrix(S21Matrix& matrix, double value) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      matrix(i, j) = value;
    }
  }
}

void S21TestHelper::CheckS21Matrix(const S21Matrix matrix, double value) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      ASSERT_NEAR(matrix(i, j), value, epsilon_);
    }
  }
}
