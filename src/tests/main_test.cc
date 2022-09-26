#include "test.h"

int main(int argc, char *argv[]) {
  // Передаем параметры командной строки в gtest
  testing::InitGoogleTest(&argc, argv);
  // Запускаем все тесты
  return RUN_ALL_TESTS();
}