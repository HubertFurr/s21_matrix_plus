#include "class_determinant_random.h"

#include "class_test_helper.h"

RandomMatrixWithZeros::RandomMatrixWithZeros() {
  int num_rows = S21TestHelper::GetRandInt(2, 20);
  int num_cols = num_rows;
  test_matrix_ = S21Matrix(num_rows, num_cols);

  int is_row = S21TestHelper::GetRandInt(0, 1);
  int zero_number = S21TestHelper::GetRandInt(0, num_rows - 1);

  for (int i = 0; i < test_matrix_.get_rows(); ++i) {
    for (int j = 0; j < test_matrix_.get_cols(); ++j) {
      if ((is_row == 1 && i == zero_number) ||
          (is_row == 0 && j == zero_number)) {
        test_matrix_(i, j) = 0.0;
      } else {
        test_matrix_(i, j) = S21TestHelper::GetRandDouble(-1e8, 1e8);
      }
    }
  }
}

RandomMatrixWithDuplicates::RandomMatrixWithDuplicates() {
  int num_rows = S21TestHelper::GetRandInt(3, 20);
  int num_cols = num_rows;
  test_matrix_ = S21Matrix(num_rows, num_cols);

  int is_row = S21TestHelper::GetRandInt(0, 1);
  int dublicate_number1 = S21TestHelper::GetRandInt(0, num_rows - 1);
  int dublicate_number2;
  if (dublicate_number1 == num_rows - 1) {
    dublicate_number2 = dublicate_number1 - 2;
  } else {
    dublicate_number2 = dublicate_number1 + 1;
  }

  double rand_double = S21TestHelper::GetRandDouble(-1e8, 1e8);

  for (int i = 0; i < test_matrix_.get_rows(); ++i) {
    for (int j = 0; j < test_matrix_.get_cols(); ++j) {
      if ((is_row == 1 && (i == dublicate_number1 || i == dublicate_number2)) ||
          (is_row == 0 && (j == dublicate_number1 || j == dublicate_number2))) {
        test_matrix_(i, j) = rand_double;
      } else {
        test_matrix_(i, j) = S21TestHelper::GetRandDouble(-1e8, 1e8);
      }
    }
  }
}

RandomMatrixWithProportional::RandomMatrixWithProportional() {
  int num_rows = S21TestHelper::GetRandInt(2, 30);
  int num_cols = num_rows;
  test_matrix_ = S21Matrix(num_rows, num_cols);

  int is_row = S21TestHelper::GetRandInt(0, 1);
  int dublicate_number = S21TestHelper::GetRandInt(1, num_rows - 1);

  for (int i = 0; i < test_matrix_.get_rows(); ++i) {
    for (int j = 0; j < test_matrix_.get_cols(); ++j) {
      if ((is_row == 1 && (i == dublicate_number))) {
        test_matrix_(i, j) = test_matrix_(0, j) * 2.0;
      } else if (is_row == 0 && (j == dublicate_number)) {
        test_matrix_(i, j) = test_matrix_(i, 0) * 2.0;
      } else {
        test_matrix_(i, j) = S21TestHelper::GetRandDouble(-2, 2);
      }
    }
  }
}