#include <gtest/gtest.h>

#include "../../s21_matrix_oop.h"

class RandomDeterminantMatrixWithZeros : public ::testing::TestWithParam<int> {
 public:
  RandomDeterminantMatrixWithZeros();

 protected:
  S21Matrix test_matrix_;
};

class RandomDeterminantMatrixWithDuplicates
    : public ::testing::TestWithParam<int> {
 public:
  RandomDeterminantMatrixWithDuplicates();

 protected:
  S21Matrix test_matrix_;
};

class RandomDeterminantMatrixWithProportional
    : public ::testing::TestWithParam<int> {
 public:
  RandomDeterminantMatrixWithProportional();

 protected:
  S21Matrix test_matrix_;
};

class RandomCofactorMatrixWithZeros : public ::testing::TestWithParam<int> {
 public:
  RandomCofactorMatrixWithZeros();

 protected:
  S21Matrix test_matrix_;
};

class RandomCofactorMatrixWithDuplicates
    : public ::testing::TestWithParam<int> {
 public:
  RandomCofactorMatrixWithDuplicates();

 protected:
  S21Matrix test_matrix_;
};

class RandomCofactorMatrixWithProportional
    : public ::testing::TestWithParam<int> {
 public:
  RandomCofactorMatrixWithProportional();

 protected:
  S21Matrix test_matrix_;
};