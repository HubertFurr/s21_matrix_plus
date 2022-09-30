#include "./../s21_matrix_oop.h"

#include <cmath>
#include <iostream>
// #include <vector>

S21Matrix::S21Matrix() {
  std::cout << "Default constructor" << std::endl;
  // TODO(hubertfu):const проверить
  // TODO(hubertfu):explicit проверить
  rows_ = 3;
  cols_ = 3;

  // Выделяем память с value-initialization (Т.к. double - POD-тип)
  matrix_ = new double[rows_ * cols_]{};
}

S21Matrix::S21Matrix(int rows, int cols) {
  std::cout << "int int constructor" << std::endl;
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double[rows_ * cols_]{};
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  std::cout << "Copy constructor" << std::endl;
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double[rows_ * cols_]{};
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

void S21Matrix::PrintWolfram() const {
  // std::cout.precision(14);;
  // std::cout.setf(std::ios::fixed);
  std::cout << "det{";
  for (int i = 0; i < rows_; ++i) {
    std::cout << "{";
    for (int j = 0; j < cols_; ++j) {
      std::cout << (*this)(i, j);
      if (j != cols_ - 1) {
        std::cout << ",";
      }
    }
    std::cout << "}";
    if (i != rows_ - 1) {
      std::cout << ",";
    }
  }
  std::cout << "}" << std::endl;
}

void S21Matrix::PrintPlanet() const {
  // std::cout.precision(14);;
  // std::cout.setf(std::ios::fixed);
  // std::cout << "det{";
  for (int i = 0; i < rows_; ++i) {
    // std::cout << "{";
    for (int j = 0; j < cols_; ++j) {
      std::cout << (*this)(i, j);
      if (j != cols_ - 1) {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int S21Matrix::get_cols() const { return cols_; }

int S21Matrix::get_rows() const { return rows_; }

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
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

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

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

S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
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
  return tmp;
}

S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
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

S21Matrix S21Matrix::operator*=(const double number) {
  MulNumber(number);
  return *this;
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.get_rows()) {
    throw std::logic_error("Incorrect matrix size for multiplication");
  }

  S21Matrix result{rows_, cols_};

  for (int i = 0; i < result.get_rows(); i++) {
    for (int j = 0; j < result.get_cols(); j++) {
      for (int k = 0; k < cols_; k++) {
        result(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }
  *this = std::move(result);
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix tmp = *this;
  tmp.MulMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

void S21Matrix::SwapRows(int n1, int n2) {
  if (n1 != n2) {
    for (int i = 0; i < cols_; ++i) {
      std::swap((*this)(n1, i), (*this)(n2, i));
    }
  }
}

/**
 * @brief функция для вычисления определителя (детерминанта) матрицы
 *
 * Прямые методы вычисления определителя могут быть основаны непосредственно на
 * его определении, как суммы по перестановкам, или на разложении Лапласа по
 * определителям меньшего порядка. Однако такие методы очень неэффективны, так
 * как требуют О(n!) операций для вычисления определителя n-го порядка.
 * Определитель матрицы 12х12 уже не посчитается за адекватное время
 *
 * Поэтому будем вычислять методом "Гаусса-Жордана", сложность данного алгоритма
 * составляет уже O(n^3)
 *
 *
 * @author Hubert Furr (hubertfu@student.21-school.ru)
 * @return double расчитанный определитель (детерминант)
 */
double S21Matrix::Determinant() {
  // double result = 0;
  if (rows_ != cols_) {
    throw std::logic_error("Incorrect matrix size for Determinant");
  }

  double det = 1;
  S21Matrix tmp = *this;
  int size = rows_;
  // std::cout << "\n\n"
  //           << "matrix:"
  //           << "\n";
  // tmp.Print();

  for (int i = 0; i < size; ++i) {
    // Выбор опорного элемента. pivoting = индекс опорного элемента
    int pivoting = i;
    for (int j = i + 1; j < size; j++) {
      if (std::abs(tmp(j, i)) > std::abs(tmp(pivoting, i))) {
        pivoting = j;
      }
    }

    if (std::abs(tmp(pivoting, i)) < epsilon_) {
      det = 0;
      break;
    }

    // Меняем местами текущую строку и строку с опорным элементом
    tmp.SwapRows(i, pivoting);
    // std::cout << "after pivo:"
    //           << "\n";
    // tmp.Print();

    det *= tmp(i, i);

    if (i != pivoting) {
      det = -det;
    }

    for (int j = i + 1; j < size; ++j) {
      double el = tmp(j, i) / tmp(i, i);
      for (int k = 0; k < size; ++k) {
        tmp(j, k) -= tmp(i, k) * el;
      }
    }
    // std::cout << "after minus row:"
    //           << "\n";
    // tmp.Print();
  }

  return det;
}
