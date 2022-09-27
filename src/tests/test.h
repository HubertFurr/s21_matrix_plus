#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <gtest/gtest.h>

#include "./../s21_matrix_oop.h"

void test_matrix_value(const S21Matrix &matrix_check, double check);
S21Matrix get_matrix();

#endif  // SRC_TESTS_TEST_H_
