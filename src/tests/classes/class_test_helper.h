#include "./../../s21_matrix_oop.h"

namespace s21_matrix_test_helper {
constexpr double epsilon_ = 1e-7;
constexpr int random_test_num_ = 50;
constexpr int random_matrix_max_size = 20;

void Print(const S21Matrix& matrix);
void PrintWolfram(const S21Matrix& matrix);
void PrintPlanet(const S21Matrix& matrix);
void PrintMathway(const S21Matrix& matrix);
void PrintTest(const S21Matrix& matrix);
int GetRandInt(const int min, int max);
double GetRandDouble(const double min, double max);
S21Matrix RandomS21Matrix(const int rows, int cols);
void FillS21Matrix(S21Matrix& matrix, double value);
void CheckS21Matrix(const S21Matrix& matrix, double value);
}  // namespace s21_matrix_test_helper
