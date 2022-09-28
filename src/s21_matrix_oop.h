#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

class S21Matrix {
 private:
  int rows_, cols_;
  double* matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double number);

  void Print() const;
  double& operator()(int row, int col) const;
  int get_cols() const;
  int get_rows() const;

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  bool operator==(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  friend S21Matrix operator*(const double number, const S21Matrix& matrix);
  friend S21Matrix operator*(const S21Matrix& matrix, const double number);
};

#endif  // SRC_S21_MATRIX_H_
