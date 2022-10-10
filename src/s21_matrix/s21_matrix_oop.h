#ifndef S21MATRIX_PLUS_S21_MATRIX_OOP_H_
#define S21MATRIX_PLUS_S21_MATRIX_OOP_H_

class S21Matrix {
 private:
  int rows_, cols_;
  double* matrix_;
  const double epsilon_ = 1e-7;

  void Free();
  double& get_matrix_element(int row, int col) const;
  void SwapRows(int n1, int n2);
  S21Matrix GetMinorMatrix(const int skip_row, const int skip_column) const;

 public:
  // Возможно использование ключевого слова explicit для конструкторов, но на в
  // контексте данного класса не нашел необходимости в этом.
  // Неявные преобразования чаще всего нам полезны, поэтому необходимость
  // использования explicit надо четко для себя объяснить

  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  // Nodiscard -  атрибут используется, чтобы обозначить, что возвращаемое
  // значение функции должно быть обязательно использовано при вызове.
  // Особенно актуально в случаях, когда функция возвращает код ошибки (таким
  // образом компилятор всегда напомнит, если вы не сохраняете код ошибки и,
  // соответственно не проверяете его).
  // В данном случае добавил у некоторых функций для примера. Можно добавить ко
  // всем функциям, которые никак не меняют объект и что-то возвращают
  // (использование таких функций без сохранения результатов не имеет смысла и
  // компилятор будет нас предупреждать), но не стал, т.к.  многие тесты делают
  // проверки на исключения без сохранения результата функций

  [[nodiscard]] bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double number);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  [[nodiscard]] int get_cols() const noexcept;
  [[nodiscard]] int get_rows() const noexcept;
  void set_rows(int new_rows);
  void set_cols(int new_cols);

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  // Зачем указывать &, && и delete - см. brief метода
  double& operator()(int row, int col) &;
  double& operator()(int row, int col) && = delete;
  const double& operator()(int row, int col) const&;
  const double& operator()(int row, int col) const&& = delete;
  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*(double number) const;
  friend S21Matrix operator*(double number, const S21Matrix& matrix);
  S21Matrix operator*=(double number);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*=(const S21Matrix& other);
};

#endif  // S21MATRIX_PLUS_S21_MATRIX_OOP_H_
