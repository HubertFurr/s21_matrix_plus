#include "./../../s21_matrix_oop.h"

// В рамках С++ по идее тут лучше использовать namespace s21_matrix_test_helper
// Однако в качестве эксперимента попробуем сделать аналог статичного класса

class S21TestHelper final {
 private:
 public:
  static constexpr double epsilon_ = 1e-7;
  static constexpr int random_test_num_ = 50;

  S21TestHelper() = delete;
  ~S21TestHelper() = delete;
  static int GetRandInt(const int min, const int max);
  static double GetRandDouble(const double min, const double max);
  static S21Matrix RandomS21Matrix(const int rows, const int cols);
  static void FillS21Matrix(S21Matrix& matrix, double value);
  static void CheckS21Matrix(const S21Matrix matrix, double value);
};
