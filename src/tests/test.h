#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

// 1 - включить тесты, потенциально вылетающие в timeout
// 2 - выключить тесты, потенциально вылетающие в timeout
#define _GTEST_TIMEOUT 1

// 1 - включить отображение доп информации в тестах
// #define __DEBUG 1

#include <gtest/gtest.h>

#include "./../s21_matrix_oop.h"
#include "./classes/class_test_helper.h"

#if (_GTEST_TIMEOUT == 1)
#define TEST_TIMEOUT_BEGIN if (1) {
#define TEST_TIMEOUT_END }
#else
#define TEST_TIMEOUT_BEGIN if (0) {
#define TEST_TIMEOUT_END }
#endif

#endif  // SRC_TESTS_TEST_H_
