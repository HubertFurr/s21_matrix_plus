#include "test.h"

TEST(test_class, basic_constructor) {
  S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.get_cols(), 3);
  EXPECT_EQ(matrix_check.get_rows(), 3);
  // M(0,0) = 5;
  test_matrix_value(matrix_check, 0);
  // EXPECT_EQ(M(0, 0), 0);
}

TEST(test_class, basic_constructor_const) {
  const S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.get_cols(), 3);
  EXPECT_EQ(matrix_check.get_rows(), 3);
  test_matrix_value(matrix_check, 0);
}

TEST(test_class, params_constructor) {
  S21Matrix matrix_check(5, 5);
  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  test_matrix_value(matrix_check, 0);
}

TEST(test_class, params_constructor_const) {
  const S21Matrix matrix_check(5, 5);
  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  test_matrix_value(matrix_check, 0);
}

TEST(test_class, copy_constructor) {
  const S21Matrix matrix_check = S21Matrix(2, 2);
  matrix_check(0, 0) = 4;
  matrix_check(0, 1) = 4;
  matrix_check(1, 0) = 4;
  matrix_check(1, 1) = 4;
  // matrix_check.Print();
  S21Matrix matrix_check2 = matrix_check;
  // matrix_check2.Print();
  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);
  test_matrix_value(matrix_check, 4);
  EXPECT_EQ(matrix_check2.get_cols(), 2);
  EXPECT_EQ(matrix_check2.get_rows(), 2);
  test_matrix_value(matrix_check2, 4);
  // matrix_check.Print();
  // matrix_check2.Print();
}

TEST(test_class, move_constructor) {
  S21Matrix matrix_check = get_matrix();

  // std::move
  // std::cout << matrix_check.get_rows() << '\n';
  // std::cout << matrix_check.get_cols() << '\n';
  // matrix_check = get_matrix();
  // S21Matrix matrix_check2 = matrix_check;

  // std::cout << matrix_check.get_rows() << '\n';
  // std::cout << matrix_check.get_cols() << '\n';

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  test_matrix_value(matrix_check, 0);
}

// int i1;                 //undefined value
// int i2 = 42;            //note: inits with 42
// int i3(42);             //inits with 42
// int i4 = int();         //inits with 42
// int i5{42};             //inits with 42
// int i6 = {42};          //inits with 42
// int i7{};               //inits with 0
// int i8 = {};            //inits with 0
// auto i9 = 42;           //inits with 42
// auto i10{42};           //C++11: std::initializer_list<int>, C++14: int
// auto i11 = {42};        //inits std::initializer_list<int> with 42
// auto i12 = int{42};     //inits int with 42
// int i13();              //declares a function
// int i14(7, 9);          //compile-time error
// int i15 = (7, 9);       //OK, inits int with 9 (comma operator)
// int i16 = int(7, 9);    //compile-time error
// int i17(7, 9);          //compile-time error
// auto i18 = (7, 9);      //OK, inits int with 9 (comma operator)
// auto i19 = int(7, 9);   //compile-time error

// Способы инициализации - https://habr.com/ru/company/jugru/blog/469465/
// TEST(test_class, constructor1) {
//   S21Matrix matrix_check(3,3);// = {5,5};
//   EXPECT_EQ(matrix_check.get_cols(), 5);
//   EXPECT_EQ(matrix_check.get_rows(), 5);
//   test_matrix_value(matrix_check, 0);
// }

// TODO(hubertfu): хорошо подумать про const ссылки
void test_matrix_value(const S21Matrix &matrix_check, double check) {
  for (int i = 0; i < matrix_check.get_rows(); ++i) {
    for (int j = 0; j < matrix_check.get_cols(); ++j) {
      EXPECT_EQ(matrix_check(i, j), check);
    }
  }
}

S21Matrix get_matrix() {
  S21Matrix result(5, 5);
  return result;
}