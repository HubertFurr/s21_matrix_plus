#include "./../s21_matrix_oop.h"

#include <cmath>
#include <iostream>

S21Matrix::S21Matrix() {
  std::cout << "Default constructor" << std::endl;
  // TODO(hubertfu):const проверить
  rows_ = 3;
  cols_ = 3;

  // Выделяем память с value-initialization (Т.к. double - POD-тип)
  matrix_ = new double[rows_ * cols_]();
}

S21Matrix::S21Matrix(int rows, int cols) {
  std::cout << "int int constructor" << std::endl;
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double[rows_ * cols_]();
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  std::cout << "Copy constructor" << std::endl;
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double[rows_ * cols_]();
  // other.Print();
  std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
  // std::cout << "other[]:" << other.matrix_[0] << std::endl;
  // std::cout << "other():" << other(0, 0) << std::endl;
  // Print();
  // Копируем
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  std::cout << "Move constructor" << std::endl;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.rows_);
  std::swap(matrix_, other.matrix_);
}

// TODO(hubertfu):
// initializer_list - https://radioprog.ru/post/1262
// initializer lists -
// https://www.educative.io/answers/what-are-initializer-lists-in-cpp

S21Matrix::~S21Matrix() { delete[] matrix_; }

double &S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row * cols_ + col];
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  std::cout << "Use =&" << std::endl;
  if (this != &other) {
    delete[] matrix_;

    rows_ = other.rows_;
    cols_ = other.cols_;

    matrix_ = new double[rows_ * cols_]();
    std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
  }
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  std::cout << "Use =&&" << std::endl;
  if (this != &other) {
    delete[] matrix_;

    // int a = 5, b = 3;
    // std::cout << a << ' ' << b << '\n';
    // std::swap(a,b);
    // std::cout << a << ' ' << b << '\n';

    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;

    // std::cout << rows_ << ' ' << other.rows_ << '\n';
    // std::cout << matrix_ << ' ' << other.matrix_ << '\n';

    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);

    // std::cout << rows_ << ' ' << other.rows_ << '\n';
    // std::cout << matrix_ << ' ' << other.matrix_ << '\n';

    // rows_ = other.rows_;
    // cols_ = other.cols_;
    // matrix_ = other.matrix_;

    // other.matrix_ = nullptr;
    // other.rows_ = 0;
    // other.cols_ = 0;
  }
  return *this;
}

void S21Matrix::Print() const {
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

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool result = true;

  if (rows_ != other.get_rows() || cols_ != other.get_cols()) {
    result = false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (std::fabs(other(i, j) - (*this)(i, j)) > 1e-7) {
          result = false;
          break;
        }
      }
      if (result == false) {
        break;
      }
    }
  }

  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.get_rows() || cols_ != other.get_cols()) {
    throw std::logic_error("Incorrect matrix size");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i * cols_ + j] =
          matrix_[i * cols_ + j] + other.matrix_[i * cols_ + j];
    }
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  std::cout << "start operator+" << std::endl;
  // SumMatrix(other);
  // return *this;
  S21Matrix tmp = *this;
  tmp.SumMatrix(other);
  std::cout << "end operator+" << std::endl;
  return tmp;
  // return std::move(tmp);
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.get_rows() || cols_ != other.get_cols()) {
    throw std::logic_error("Incorrect matrix size");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i * cols_ + j] =
          matrix_[i * cols_ + j] - other.matrix_[i * cols_ + j];
    }
  }
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix tmp = *this;
  tmp.SubMatrix(other);
  std::cout << "end operator+" << std::endl;
  return tmp;
}

void S21Matrix::MulNumber(const double number) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i * cols_ + j] = matrix_[i * cols_ + j] * number;
    }
  }
}

S21Matrix operator*(const S21Matrix &matrix, const double number) {
  S21Matrix tmp = matrix;
  tmp.MulNumber(number);
  return tmp;
}

S21Matrix operator*(const double number, const S21Matrix &matrix) {
  S21Matrix tmp = matrix * number;
  return tmp;
}
