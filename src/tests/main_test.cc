#include "test.h"

int main(int argc, char *argv[]) {
  // Задаем фильтры для запуска некоторых тестов
  // ::testing::GTEST_FLAG(filter) = "*TestInverse*";

  // Передаем параметры командной строки в gtest
  testing::InitGoogleTest(&argc, argv);

  // Запускаем все тесты
  return RUN_ALL_TESTS();
}
  // TODO:
  // S21Matrix& operator+=(const S21Matrix& other);
  // S21Matrix& operator-=(const S21Matrix& other);
  // S21Matrix& operator*=(const S21Matrix& other);
  // S21Matrix& operator*=(const double& number);
  // S21Matrix& operator=(const S21Matrix& other);

  // Конструктор переноса через присваивание

  // Дефолтная матрица 0х0