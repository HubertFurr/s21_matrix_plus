/* ************************************************************************** */
/*                                              ############       ####       */
/*                                              ############       ####       */
/*   s21_matrix_oop.h                                       ####       ####   */
/*                                                          ####       ####   */
/*   By: hubertfu@student.21-school.ru              ########           ####   */
/*                                                  ########           ####   */
/*                                              ####                   ####   */
/*   Created: 2022-09-25                        ####                   ####   */
/*   Updated: 2023-05-23                            ############       ####   */
/*                                                  ############       ####   */
/* ************************************************************************** */

/**
 * @file s21_matrix_oop.h
 * @author Hubert Furr (hubertfu@student.21-school.ru)
 * @brief Заголовочный файл проекта CPP1 s21_matrix+, реализующий библиотеку для
 * работы с матрицами.
 * @version 2.1
 * @date 2023-05-22
 *
 * @copyright School-21 (c) 2023
 *
 */

#ifndef CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_

class S21Matrix {
 public:
  S21Matrix() noexcept;
  // Зачем explicit - см. brief конструктора
  explicit S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  ~S21Matrix() noexcept;

  // В заголовочном файле можно помечать методы как [[nodiscard]], например
  // EqMatrix() можно объявить как:
  // [[nodiscard]] bool EqMatrix(const S21Matrix& other) const;
  // Однако не стоит это делать - см. brief метода
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double number) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  int get_cols() const noexcept;
  int get_rows() const noexcept;
  void set_rows(int new_rows);
  void set_cols(int new_cols);

  // Зачем указывать &, && и delete - см. brief метода
  double& operator()(int row, int col) &;
  double& operator()(int row, int col) && = delete;
  const double& operator()(int row, int col) const&;
  const double& operator()(int row, int col) const&& = delete;
  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator*(double number) const noexcept;
  friend S21Matrix operator*(double number, const S21Matrix& matrix) noexcept;
  S21Matrix& operator*=(double number);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);

 private:
  void Free() noexcept;
  const double& GetMatrixElement(int row, int col) const;
  void SwapRows(int row1, int row2) noexcept;
  S21Matrix GetMinorMatrix(const int skip_row, const int skip_column) const;

  int rows_, cols_;
  double* matrix_;
  const double kEpsilon = 1e-7;
};

#endif  // CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_
