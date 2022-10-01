#include <gtest/gtest.h>

#include "../../s21_matrix_oop.h"

class RandomMatrixWithZeros : public ::testing::TestWithParam<int> {
 public:
  RandomMatrixWithZeros();

 protected:
  S21Matrix test_matrix_;
};

class RandomMatrixWithDuplicates : public ::testing::TestWithParam<int> {
 public:
  RandomMatrixWithDuplicates();

 protected:
  S21Matrix test_matrix_;
};

class RandomMatrixWithProportional : public ::testing::TestWithParam<int> {
 public:
  RandomMatrixWithProportional();

 protected:
  S21Matrix test_matrix_;
};
