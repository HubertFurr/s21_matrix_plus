#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

// 1 - включить тесты, потенциально вылетающие в timeout
// 2 - выключить тесты, потенциально вылетающие в timeout
#define _GTEST_TIMEOUT 2

// 1 - включить отображение доп информации в тестах
// #define __DEBUG 1

#include <gtest/gtest.h>

#include <future>

#include "./../s21_matrix_oop.h"
#include "./classes/class_test_helper.h"

#if (_GTEST_TIMEOUT == 1)
#define TEST_TIMEOUT_BEGIN if (1) {
#define TEST_TIMEOUT_END }
#else
#define TEST_TIMEOUT_BEGIN if (0) {
#define TEST_TIMEOUT_END }
#endif

void test_matrix_value(const S21Matrix& matrix_check, double check);
S21Matrix get_matrix();

#endif  // SRC_TESTS_TEST_H_
