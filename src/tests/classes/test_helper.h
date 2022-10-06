#ifndef S21MATRIX_PLUS_TESTS_CLASSES_TEST_HELPER_H_
#define S21MATRIX_PLUS_TESTS_CLASSES_TEST_HELPER_H_

#include "./../../s21_matrix_oop.h"

namespace s21_matrix_test_helper {
constexpr double epsilon_ = 1e-7;
constexpr int random_test_num_ = 50;
constexpr int random_matrix_max_size = 20;  // 9!

S21Matrix TestMoveConstructor(const S21Matrix test);
void Print(const S21Matrix& matrix);
void PrintWolfram(const S21Matrix& matrix);
void PrintPlanet(const S21Matrix& matrix);
void PrintMathway(const S21Matrix& matrix);
void PrintTest(const S21Matrix& matrix);
int GetRandInt(const int min, int max);
double GetRandDouble(const double min, double max);
S21Matrix GetRandMatrix(int rows, int cols, double min, double max);
void FillMatrix(S21Matrix& matrix, double value);
void CheckMatrix(const S21Matrix& matrix, double value);
void TestInverse(const S21Matrix& matrix);
S21Matrix GetIdentityMatrix(int size);
}  // namespace s21_matrix_test_helper

#endif  // S21MATRIX_PLUS_TESTS_CLASSES_TEST_HELPER_H_