#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

class S21Matrix {
 private:
  int rows_, cols_;
  double* matrix_;

 public:
  S21Matrix();
  ~S21Matrix();

  void Print();
  double& operator()(int row, int col);
  int get_cols();
  int get_rows();
};

#endif  // SRC_S21_MATRIX_H_
