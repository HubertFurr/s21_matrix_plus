#include "test.h"

TEST(test_class, basic_constructor) {
  S21Matrix M;
  EXPECT_EQ(M.get_cols(), 3);
  EXPECT_EQ(M.get_rows(), 3);
}