#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

// Не объявлен - запускать тесты в отдельном потоке с проверкой на timeout
// 1 - запускать все тесты в одном потоке без проверки на timeout
// 2 - вообще не запускать тесты с проверкой на timeout
// #define _GTEST_NOFORK 1

#include <gtest/gtest.h>

#include <future>

#include "./../s21_matrix_oop.h"
#include "./classes/class_test_helper.h"

#ifndef _GTEST_NOFORK
#define TEST_TIMEOUT_BEGIN                           \
  std::promise<bool> promisedFinished;               \
  auto futureResult = promisedFinished.get_future(); \
                              std::thread([&](std::promise<bool>& promisedFinished) {
#define TEST_TIMEOUT_FAIL_END(X)                                     \
  promisedFinished.set_value(true);                                          \
  }, std::ref(promisedFinished)).detach();                           \
  EXPECT_TRUE(futureResult.wait_for(std::chrono::milliseconds(X)) != \
              std::future_status::timeout);

#define TEST_TIMEOUT_SUCCESS_END(X)                                   \
  finished.set_value(true);                                           \
  }, std::ref(promisedFinished)).detach();                            \
  EXPECT_FALSE(futureResult.wait_for(std::chrono::milliseconds(X)) != \
               std::future_status::timeout);
#else
#if (_GTEST_NOFORK == 1)
#define TEST_TIMEOUT_BEGIN if (1) {
#define TEST_TIMEOUT_FAIL_END(X) }
#define TEST_TIMEOUT_SUCCESS_END(X) }
#else
#define TEST_TIMEOUT_BEGIN if (0) {
#define TEST_TIMEOUT_FAIL_END(X) }
#define TEST_TIMEOUT_SUCCESS_END(X) }
#endif
#endif

void test_matrix_value(const S21Matrix& matrix_check, double check);
S21Matrix get_matrix();

#endif  // SRC_TESTS_TEST_H_
