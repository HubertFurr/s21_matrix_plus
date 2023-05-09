#ifndef CPP1_S21_MATRIXPLUS_TESTS_CLASSES_RANDOM_SUITES_H_
#define CPP1_S21_MATRIXPLUS_TESTS_CLASSES_RANDOM_SUITES_H_

#include <gtest/gtest.h>

#include "../../s21_matrix/s21_matrix_oop.h"

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

class RandomInverseMatrixWithZeros : public RandomDeterminantMatrixWithZeros {};
class RandomInverseMatrixWithDuplicates
    : public RandomDeterminantMatrixWithDuplicates {};
class RandomInverseMatrixWithProportiona
    : public RandomDeterminantMatrixWithProportional {};

class RandomInverseMatrixRangeOne : public ::testing::TestWithParam<int> {
 public:
  RandomInverseMatrixRangeOne();

 protected:
  S21Matrix test_matrix_;
};

class RandomInverseMatrixRangeTwo : public ::testing::TestWithParam<int> {
 public:
  RandomInverseMatrixRangeTwo();

 protected:
  S21Matrix test_matrix_;
};

class RandomInverseMatrixRangeThree : public ::testing::TestWithParam<int> {
 public:
  RandomInverseMatrixRangeThree();

 protected:
  S21Matrix test_matrix_;
};

class RandomMulNumberMatrixRangeOne : public RandomInverseMatrixRangeOne {};

class RandomMulMatrixRangeOne : public RandomInverseMatrixRangeOne {};

#endif  // CPP1_S21_MATRIXPLUS_TESTS_CLASSES_RANDOM_SUITES_H_
