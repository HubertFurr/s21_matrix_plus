#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

// TODO(hubertfu): explicit ?
// struct A {
//   explicit A(int a1 = 0);
// };

// A a = 0; /* not allowed */
// A b; /* allowed */
// A c(0); /* allowed */

class S21Matrix {
 private:
  int rows_, cols_;
  double* matrix_;
  const double epsilon_ = 1e-7;

  void Free();
  void SwapRows(int n1, int n2);
  S21Matrix GetMinorMatrix(const int skip_row, const int skip_column) const;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double number);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  int get_cols() const;
  int get_rows() const;
  void set_rows(int new_rows);
  void set_cols(int new_cols);

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  double& operator()(int row, int col) const;
  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator-=(const S21Matrix& other);
  friend S21Matrix operator*(const S21Matrix& matrix, const double number);
  friend S21Matrix operator*(const double number, const S21Matrix& matrix);
  S21Matrix operator*=(const double number);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*=(const S21Matrix& other);
};

#endif  // SRC_S21_MATRIX_H_
