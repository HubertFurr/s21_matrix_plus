#include "class_random_suites.h"

#include "class_test_helper.h"

RandomDeterminantMatrixWithZeros::RandomDeterminantMatrixWithZeros() {
  int num_rows = s21_matrix_test_helper::GetRandInt(2, 20);
  int num_cols = num_rows;
  test_matrix_ = S21Matrix(num_rows, num_cols);

  int is_row = s21_matrix_test_helper::GetRandInt(0, 1);
  int zero_number = s21_matrix_test_helper::GetRandInt(0, num_rows - 1);

  for (int i = 0; i < test_matrix_.get_rows(); ++i) {
    for (int j = 0; j < test_matrix_.get_cols(); ++j) {
      if ((is_row == 1 && i == zero_number) ||
          (is_row == 0 && j == zero_number)) {
        test_matrix_(i, j) = 0.0;
      } else {
        test_matrix_(i, j) = s21_matrix_test_helper::GetRandDouble(-1e8, 1e8);
      }
    }
  }
}

RandomDeterminantMatrixWithDuplicates::RandomDeterminantMatrixWithDuplicates() {
  int num_rows = s21_matrix_test_helper::GetRandInt(3, 20);
  int num_cols = num_rows;
  test_matrix_ = S21Matrix(num_rows, num_cols);

  int is_row = s21_matrix_test_helper::GetRandInt(0, 1);
  int dublicate_number1 = s21_matrix_test_helper::GetRandInt(0, num_rows - 1);
  int dublicate_number2;
  if (dublicate_number1 == num_rows - 1) {
    dublicate_number2 = dublicate_number1 - 2;
  } else {
    dublicate_number2 = dublicate_number1 + 1;
  }

  double rand_double = s21_matrix_test_helper::GetRandDouble(-1e8, 1e8);

  for (int i = 0; i < test_matrix_.get_rows(); ++i) {
    for (int j = 0; j < test_matrix_.get_cols(); ++j) {
      if ((is_row == 1 && (i == dublicate_number1 || i == dublicate_number2)) ||
          (is_row == 0 && (j == dublicate_number1 || j == dublicate_number2))) {
        test_matrix_(i, j) = rand_double;
      } else {
        test_matrix_(i, j) = s21_matrix_test_helper::GetRandDouble(-1e8, 1e8);
      }
    }
  }
}

RandomDeterminantMatrixWithProportional::
    RandomDeterminantMatrixWithProportional() {
  int num_rows = s21_matrix_test_helper::GetRandInt(2, 30);
  int num_cols = num_rows;
  test_matrix_ = S21Matrix(num_rows, num_cols);

  int is_row = s21_matrix_test_helper::GetRandInt(0, 1);
  int dublicate_number = s21_matrix_test_helper::GetRandInt(1, num_rows - 1);

  for (int i = 0; i < test_matrix_.get_rows(); ++i) {
    for (int j = 0; j < test_matrix_.get_cols(); ++j) {
      if ((is_row == 1 && (i == dublicate_number))) {
        test_matrix_(i, j) = test_matrix_(0, j) * 2.0;
      } else if (is_row == 0 && (j == dublicate_number)) {
        test_matrix_(i, j) = test_matrix_(i, 0) * 2.0;
      } else {
        test_matrix_(i, j) = s21_matrix_test_helper::GetRandDouble(-2, 2);
      }
    }
  }
}

RandomCofactorMatrixWithZeros::RandomCofactorMatrixWithZeros() {
  int num_rows = s21_matrix_test_helper::GetRandInt(2, 20);
  int num_cols = num_rows;
  test_matrix_ = S21Matrix{num_rows, num_cols};
  std::cout << num_rows << " " << num_cols << "!!\n";

  for (int i = 0; i < test_matrix_.get_rows(); ++i) {
    for (int j = 0; j < test_matrix_.get_cols(); ++j) {
      if (i == 0 || i == test_matrix_.get_rows() - 1) {
        test_matrix_(i, j) = 0.0;
      } else {
        test_matrix_(i, j) = s21_matrix_test_helper::GetRandDouble(-1e8, 1e8);
      }
    }
  }
}

RandomCofactorMatrixWithDuplicates::RandomCofactorMatrixWithDuplicates() {
  int num_rows = s21_matrix_test_helper::GetRandInt(3, 20);
  int num_cols = num_rows;
  std::cout << num_rows << " " << num_cols << "!!\n";
  s21_matrix_test_helper::Print(test_matrix_);
  test_matrix_ = S21Matrix{num_rows, num_cols};
  s21_matrix_test_helper::Print(test_matrix_);
  double rand_double = s21_matrix_test_helper::GetRandDouble(-1e8, 1e8);

  for (int i = 0; i < test_matrix_.get_rows(); ++i) {
    for (int j = 0; j < test_matrix_.get_cols(); ++j) {
      if (i == 0 || i == 1 || i == test_matrix_.get_rows() - 1) {
        test_matrix_(i, j) = rand_double;
      } else {
        test_matrix_(i, j) = s21_matrix_test_helper::GetRandDouble(-1e8, 1e8);
      }
    }
  }
  s21_matrix_test_helper::Print(test_matrix_);
}

RandomCofactorMatrixWithProportional::RandomCofactorMatrixWithProportional() {
  int num_rows = s21_matrix_test_helper::GetRandInt(3, 30);
  int num_cols = num_rows;
  std::cout << num_rows << " " << num_cols << "!!\n";
  s21_matrix_test_helper::Print(test_matrix_);
  test_matrix_ = S21Matrix{num_rows, num_cols};
  s21_matrix_test_helper::Print(test_matrix_);
std::cout << "0!!\n";
  for (int i = 0; i < test_matrix_.get_rows(); ++i) {
    for (int j = 0; j < test_matrix_.get_cols(); ++j) {
      if (i == 1) {
        test_matrix_(i, j) = test_matrix_(0, j) * 2.0;
      } else if (i == test_matrix_.get_rows() - 1) {
        test_matrix_(i, j) = test_matrix_(0, j) * 3.0;
      } else {
        test_matrix_(i, j) = s21_matrix_test_helper::GetRandDouble(-2, 2);
      }
    }
  }
  std::cout << "00!!\n";
  s21_matrix_test_helper::Print(test_matrix_);
}