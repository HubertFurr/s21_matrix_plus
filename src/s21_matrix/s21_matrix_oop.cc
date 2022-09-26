#include "./../s21_matrix_oop.h"

#include <iostream>

S21Matrix::S21Matrix() {
  // TODO(hubertfu):const проверить
  rows_ = 3;
  cols_ = 3;

  // Выделяем память с value-initialization (Т.к. double - POD-тип)
  matrix_ = new double[rows_ * cols_]();
}

S21Matrix::S21Matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double[rows_ * cols_]();
}

// TODO(hubertfu): 
// initializer_list - https://radioprog.ru/post/1262
// initializer lists - https://www.educative.io/answers/what-are-initializer-lists-in-cpp

S21Matrix::~S21Matrix() { delete[] matrix_; }

double& S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row * cols_ + col];
}

void S21Matrix::Print() {
  std::cout << "[" << rows_ << " x " << cols_ << "]" << std::endl;
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      std::cout << (*this)(i, j);
      if (j != cols_ - 1) {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }
  std::cout << std::endl;
}

int S21Matrix::get_cols() const { return cols_; }

int S21Matrix::get_rows() const { return rows_; }