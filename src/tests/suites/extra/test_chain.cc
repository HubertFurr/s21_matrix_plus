#include <iostream>  // TODO: remove
#include <utility>

#include "./../../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Проверяем работу цепочек - опреаторы= должны позволять создавать цепочки
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestChain, TestChain1) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{2, 2};
  S21Matrix matrix3{3, 3};

  EXPECT_EQ((matrix1 = matrix2 = matrix3).get_cols(), matrix3.get_cols());
  EXPECT_TRUE(matrix1 == matrix3);
}

TEST(TestChain, TestChain2) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{2, 2};
  S21Matrix matrix3{3, 3};

  auto size3 = matrix3.get_cols();

  EXPECT_EQ((matrix1 = std::move(matrix2) = std::move(matrix3)).get_cols(),
            size3);
  EXPECT_FALSE(matrix1 == matrix3);
}

TEST(TestChain, TestChain3) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};
  S21Matrix matrix3{1, 1};
  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 2.0;
  matrix3(0, 0) = 3.0;

  EXPECT_EQ((matrix1 += matrix2 += matrix3)(0, 0), 6.0);
  EXPECT_EQ(matrix1(0, 0), 6.0);
}

TEST(TestChain, TestChain4) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};
  S21Matrix matrix3{1, 1};
  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 2.0;
  matrix3(0, 0) = 3.0;

  EXPECT_EQ((matrix1 -= matrix2 -= matrix3)(0, 0), 2.0);
  EXPECT_EQ(matrix1(0, 0), 2.0);
}

TEST(TestChain, TestChain5) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};
  S21Matrix matrix3{1, 1};
  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 2.0;
  matrix3(0, 0) = 3.0;

  EXPECT_EQ((matrix1 *= matrix2 *= matrix3)(0, 0), 6.0);
  EXPECT_EQ(matrix1(0, 0), 6.0);
}

TEST(TestChain, TestChain6) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};
  S21Matrix matrix3{1, 1};
  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 2.0;
  matrix3(0, 0) = 3.0;

  EXPECT_EQ((matrix1 *= matrix2 *= matrix3 *= 2.0)(0, 0), 12.0);
  EXPECT_EQ(matrix1(0, 0), 12.0);
}
