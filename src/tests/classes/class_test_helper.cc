#include "class_test_helper.h"

#include <random>

int S21TestHelper::GetRandInt(const int min, const int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);
  return distr(gen);
}

double S21TestHelper::GetRandDouble(const double min, const double max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> distr(min, max);
  return distr(gen);
}
