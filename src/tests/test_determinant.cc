#include "test.h"

// https://planetcalc.ru/8351/

TEST(test_class, test_determinant0_1) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(1, 0) = 1.4;
  matrix1(1, 1) = 1.5;
  matrix1(1, 2) = 1.6;
  matrix1(2, 0) = 1.7;
  matrix1(2, 1) = 1.8;
  matrix1(2, 2) = 1.9;

  double result_check = 0.0;

  double result = matrix1.Determinant();
  ASSERT_NEAR(result_check, result, 1e-9);
}

TEST(test_class, test_determinant0_2) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = -66;
  matrix1(0, 1) = -66;
  matrix1(0, 2) = -66;
  matrix1(1, 0) = -66;
  matrix1(1, 1) = -66;
  matrix1(1, 2) = -66;
  matrix1(2, 0) = -66;
  matrix1(2, 1) = -66;
  matrix1(2, 2) = -66;

  double result_check = 0.0;

  double result = matrix1.Determinant();
  ASSERT_NEAR(result_check, result, 1e-9);
}

TEST(test_class, test_determinant1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  matrix1(0, 0) = 1.5;

  double result_check = 1.5;

  double result = matrix1.Determinant();
  ASSERT_NEAR(result_check, result, 1e-9);
}

TEST(test_class, test_determinant110) {
  S21Matrix matrix1{20, 20};
  EXPECT_EQ(matrix1.get_cols(), 20);
  EXPECT_EQ(matrix1.get_rows(), 20);

  matrix1(0, 0) = 1.07;
  matrix1(0, 1) = 1.63;
  matrix1(0, 2) = 1.91;
  matrix1(0, 3) = 1.95;
  matrix1(0, 4) = 1.78;
  matrix1(0, 5) = 1.24;
  matrix1(0, 6) = 1.74;
  matrix1(0, 7) = 1.54;
  matrix1(0, 8) = 1.82;
  matrix1(0, 9) = 1.86;
  matrix1(0, 10) = 1.26;
  matrix1(0, 11) = 1.50;
  matrix1(0, 12) = 1.74;
  matrix1(0, 13) = 1.26;
  matrix1(0, 14) = 1.99;
  matrix1(0, 15) = 1.76;
  matrix1(0, 16) = 1.66;
  matrix1(0, 17) = 1.26;
  matrix1(0, 18) = 1.85;
  matrix1(0, 19) = 1.06;

  matrix1(1, 0) = 1.55;
  matrix1(1, 1) = 1.36;
  matrix1(1, 2) = 1.65;
  matrix1(1, 3) = 1.99;
  matrix1(1, 4) = 1.18;
  matrix1(1, 5) = 1.24;
  matrix1(1, 6) = 1.53;
  matrix1(1, 7) = 1.03;
  matrix1(1, 8) = 1.40;
  matrix1(1, 9) = 1.54;
  matrix1(1, 10) = 1.66;
  matrix1(1, 11) = 1.64;
  matrix1(1, 12) = 1.29;
  matrix1(1, 13) = 1.98;
  matrix1(1, 14) = 1.85;
  matrix1(1, 15) = 1.40;
  matrix1(1, 16) = 1.38;
  matrix1(1, 17) = 1.64;
  matrix1(1, 18) = 1.65;
  matrix1(1, 19) = 1.33;

  matrix1(2, 0) = 1.51;
  matrix1(2, 1) = 1.09;
  matrix1(2, 2) = 1.58;
  matrix1(2, 3) = 1.15;
  matrix1(2, 4) = 1.25;
  matrix1(2, 5) = 1.49;
  matrix1(2, 6) = 1.73;
  matrix1(2, 7) = 1.03;
  matrix1(2, 8) = 1.54;
  matrix1(2, 9) = 1.90;
  matrix1(2, 10) = 1.32;
  matrix1(2, 11) = 1.13;
  matrix1(2, 12) = 1.22;
  matrix1(2, 13) = 1.25;
  matrix1(2, 14) = 1.82;
  matrix1(2, 15) = 1.35;
  matrix1(2, 16) = 1.09;
  matrix1(2, 17) = 1.03;
  matrix1(2, 18) = 1.14;
  matrix1(2, 19) = 1.70;

  matrix1(3, 0) = 1.34;
  matrix1(3, 1) = 1.15;
  matrix1(3, 2) = 1.75;
  matrix1(3, 3) = 1.59;
  matrix1(3, 4) = 1.94;
  matrix1(3, 5) = 1.60;
  matrix1(3, 6) = 1.56;
  matrix1(3, 7) = 1.63;
  matrix1(3, 8) = 1.83;
  matrix1(3, 9) = 1.41;
  matrix1(3, 10) = 1.57;
  matrix1(3, 11) = 1.38;
  matrix1(3, 12) = 1.56;
  matrix1(3, 13) = 1.46;
  matrix1(3, 14) = 1.59;
  matrix1(3, 15) = 1.19;
  matrix1(3, 16) = 1.17;
  matrix1(3, 17) = 1.71;
  matrix1(3, 18) = 1.52;
  matrix1(3, 19) = 1.07;

  matrix1(4, 0) = 1.89;
  matrix1(4, 1) = 1.10;
  matrix1(4, 2) = 1.45;
  matrix1(4, 3) = 1.47;
  matrix1(4, 4) = 1.58;
  matrix1(4, 5) = 1.91;
  matrix1(4, 6) = 1.84;
  matrix1(4, 7) = 1.12;
  matrix1(4, 8) = 1.76;
  matrix1(4, 9) = 1.25;
  matrix1(4, 10) = 1.60;
  matrix1(4, 11) = 1.48;
  matrix1(4, 12) = 1.17;
  matrix1(4, 13) = 1.87;
  matrix1(4, 14) = 1.31;
  matrix1(4, 15) = 1.57;
  matrix1(4, 16) = 1.96;
  matrix1(4, 17) = 1.25;
  matrix1(4, 18) = 1.31;
  matrix1(4, 19) = 1.83;

  matrix1(5, 0) = 1.67;
  matrix1(5, 1) = 1.24;
  matrix1(5, 2) = 1.31;
  matrix1(5, 3) = 1.24;
  matrix1(5, 4) = 1.70;
  matrix1(5, 5) = 1.23;
  matrix1(5, 6) = 1.97;
  matrix1(5, 7) = 1.28;
  matrix1(5, 8) = 1.07;
  matrix1(5, 9) = 1.05;
  matrix1(5, 10) = 1.46;
  matrix1(5, 11) = 1.38;
  matrix1(5, 12) = 1.19;
  matrix1(5, 13) = 1.50;
  matrix1(5, 14) = 1.66;
  matrix1(5, 15) = 1.82;
  matrix1(5, 16) = 1.82;
  matrix1(5, 17) = 1.45;
  matrix1(5, 18) = 1.39;
  matrix1(5, 19) = 1.88;

  matrix1(6, 0) = 1.70;
  matrix1(6, 1) = 1.10;
  matrix1(6, 2) = 1.33;
  matrix1(6, 3) = 1.57;
  matrix1(6, 4) = 1.42;
  matrix1(6, 5) = 1.79;
  matrix1(6, 6) = 1.31;
  matrix1(6, 7) = 1.73;
  matrix1(6, 8) = 1.34;
  matrix1(6, 9) = 1.40;
  matrix1(6, 10) = 1.25;
  matrix1(6, 11) = 1.81;
  matrix1(6, 12) = 1.35;
  matrix1(6, 13) = 1.07;
  matrix1(6, 14) = 1.85;
  matrix1(6, 15) = 1.49;
  matrix1(6, 16) = 1.17;
  matrix1(6, 17) = 1.12;
  matrix1(6, 18) = 1.08;
  matrix1(6, 19) = 1.94;

  matrix1(7, 0) = 1.23;
  matrix1(7, 1) = 1.86;
  matrix1(7, 2) = 1.83;
  matrix1(7, 3) = 1.70;
  matrix1(7, 4) = 1.89;
  matrix1(7, 5) = 1.10;
  matrix1(7, 6) = 1.14;
  matrix1(7, 7) = 1.76;
  matrix1(7, 8) = 1.83;
  matrix1(7, 9) = 1.69;
  matrix1(7, 10) = 1.75;
  matrix1(7, 11) = 1.57;
  matrix1(7, 12) = 1.01;
  matrix1(7, 13) = 1.58;
  matrix1(7, 14) = 1.82;
  matrix1(7, 15) = 1.67;
  matrix1(7, 16) = 1.99;
  matrix1(7, 17) = 1.38;
  matrix1(7, 18) = 1.54;
  matrix1(7, 19) = 1.13;

  matrix1(8, 0) = 1.13;
  matrix1(8, 1) = 1.83;
  matrix1(8, 2) = 1.56;
  matrix1(8, 3) = 1.46;
  matrix1(8, 4) = 1.31;
  matrix1(8, 5) = 1.01;
  matrix1(8, 6) = 1.36;
  matrix1(8, 7) = 1.86;
  matrix1(8, 8) = 1.37;
  matrix1(8, 9) = 1.23;
  matrix1(8, 10) = 1.56;
  matrix1(8, 11) = 1.27;
  matrix1(8, 12) = 1.00;
  matrix1(8, 13) = 1.54;
  matrix1(8, 14) = 1.83;
  matrix1(8, 15) = 1.15;
  matrix1(8, 16) = 1.83;
  matrix1(8, 17) = 1.69;
  matrix1(8, 18) = 1.35;
  matrix1(8, 19) = 1.71;

  matrix1(9, 0) = 1.69;
  matrix1(9, 1) = 1.62;
  matrix1(9, 2) = 1.78;
  matrix1(9, 3) = 1.07;
  matrix1(9, 4) = 1.95;
  matrix1(9, 5) = 1.90;
  matrix1(9, 6) = 1.02;
  matrix1(9, 7) = 1.91;
  matrix1(9, 8) = 1.83;
  matrix1(9, 9) = 1.17;
  matrix1(9, 10) = 1.79;
  matrix1(9, 11) = 1.34;
  matrix1(9, 12) = 1.38;
  matrix1(9, 13) = 1.78;
  matrix1(9, 14) = 1.40;
  matrix1(9, 15) = 1.99;
  matrix1(9, 16) = 1.59;
  matrix1(9, 17) = 1.05;
  matrix1(9, 18) = 1.17;
  matrix1(9, 19) = 1.61;

  matrix1(10, 0) = 1.10;
  matrix1(10, 1) = 1.05;
  matrix1(10, 2) = 1.52;
  matrix1(10, 3) = 1.54;
  matrix1(10, 4) = 1.30;
  matrix1(10, 5) = 1.60;
  matrix1(10, 6) = 1.86;
  matrix1(10, 7) = 1.51;
  matrix1(10, 8) = 1.37;
  matrix1(10, 9) = 1.02;
  matrix1(10, 10) = 1.92;
  matrix1(10, 11) = 1.48;
  matrix1(10, 12) = 1.02;
  matrix1(10, 13) = 1.60;
  matrix1(10, 14) = 1.24;
  matrix1(10, 15) = 1.52;
  matrix1(10, 16) = 1.66;
  matrix1(10, 17) = 1.91;
  matrix1(10, 18) = 1.09;
  matrix1(10, 19) = 1.61;

  matrix1(11, 0) = 1.42;
  matrix1(11, 1) = 1.09;
  matrix1(11, 2) = 1.45;
  matrix1(11, 3) = 1.51;
  matrix1(11, 4) = 1.76;
  matrix1(11, 5) = 1.37;
  matrix1(11, 6) = 1.09;
  matrix1(11, 7) = 1.14;
  matrix1(11, 8) = 1.42;
  matrix1(11, 9) = 1.81;
  matrix1(11, 10) = 1.96;
  matrix1(11, 11) = 1.01;
  matrix1(11, 12) = 1.78;
  matrix1(11, 13) = 1.86;
  matrix1(11, 14) = 1.30;
  matrix1(11, 15) = 1.39;
  matrix1(11, 16) = 1.25;
  matrix1(11, 17) = 1.49;
  matrix1(11, 18) = 1.26;
  matrix1(11, 19) = 1.33;

  matrix1(12, 0) = 1.53;
  matrix1(12, 1) = 1.71;
  matrix1(12, 2) = 1.31;
  matrix1(12, 3) = 1.14;
  matrix1(12, 4) = 1.67;
  matrix1(12, 5) = 1.81;
  matrix1(12, 6) = 1.76;
  matrix1(12, 7) = 1.44;
  matrix1(12, 8) = 1.34;
  matrix1(12, 9) = 1.07;
  matrix1(12, 10) = 1.27;
  matrix1(12, 11) = 1.32;
  matrix1(12, 12) = 1.93;
  matrix1(12, 13) = 1.26;
  matrix1(12, 14) = 1.74;
  matrix1(12, 15) = 1.25;
  matrix1(12, 16) = 1.23;
  matrix1(12, 17) = 1.81;
  matrix1(12, 18) = 1.84;
  matrix1(12, 19) = 1.17;

  matrix1(13, 0) = 1.58;
  matrix1(13, 1) = 1.19;
  matrix1(13, 2) = 1.05;
  matrix1(13, 3) = 1.09;
  matrix1(13, 4) = 1.49;
  matrix1(13, 5) = 1.57;
  matrix1(13, 6) = 1.65;
  matrix1(13, 7) = 1.06;
  matrix1(13, 8) = 1.86;
  matrix1(13, 9) = 1.15;
  matrix1(13, 10) = 1.69;
  matrix1(13, 11) = 1.85;
  matrix1(13, 12) = 1.46;
  matrix1(13, 13) = 1.66;
  matrix1(13, 14) = 1.76;
  matrix1(13, 15) = 1.26;
  matrix1(13, 16) = 1.58;
  matrix1(13, 17) = 1.95;
  matrix1(13, 18) = 1.45;
  matrix1(13, 19) = 1.26;

  matrix1(14, 0) = 1.79;
  matrix1(14, 1) = 1.64;
  matrix1(14, 2) = 1.78;
  matrix1(14, 3) = 1.51;
  matrix1(14, 4) = 1.05;
  matrix1(14, 5) = 1.25;
  matrix1(14, 6) = 1.79;
  matrix1(14, 7) = 1.64;
  matrix1(14, 8) = 1.99;
  matrix1(14, 9) = 1.24;
  matrix1(14, 10) = 1.49;
  matrix1(14, 11) = 1.87;
  matrix1(14, 12) = 1.64;
  matrix1(14, 13) = 1.30;
  matrix1(14, 14) = 1.76;
  matrix1(14, 15) = 1.20;
  matrix1(14, 16) = 1.37;
  matrix1(14, 17) = 1.37;
  matrix1(14, 18) = 1.89;
  matrix1(14, 19) = 1.96;

  matrix1(15, 0) = 1.91;
  matrix1(15, 1) = 1.69;
  matrix1(15, 2) = 1.12;
  matrix1(15, 3) = 1.82;
  matrix1(15, 4) = 1.02;
  matrix1(15, 5) = 1.92;
  matrix1(15, 6) = 1.97;
  matrix1(15, 7) = 1.15;
  matrix1(15, 8) = 1.64;
  matrix1(15, 9) = 1.28;
  matrix1(15, 10) = 1.96;
  matrix1(15, 11) = 1.87;
  matrix1(15, 12) = 1.39;
  matrix1(15, 13) = 1.86;
  matrix1(15, 14) = 1.59;
  matrix1(15, 15) = 1.38;
  matrix1(15, 16) = 1.99;
  matrix1(15, 17) = 1.28;
  matrix1(15, 18) = 1.74;
  matrix1(15, 19) = 1.08;

  matrix1(16, 0) = 1.98;
  matrix1(16, 1) = 1.70;
  matrix1(16, 2) = 1.42;
  matrix1(16, 3) = 1.27;
  matrix1(16, 4) = 1.86;
  matrix1(16, 5) = 1.63;
  matrix1(16, 6) = 1.63;
  matrix1(16, 7) = 1.68;
  matrix1(16, 8) = 1.36;
  matrix1(16, 9) = 1.84;
  matrix1(16, 10) = 1.21;
  matrix1(16, 11) = 1.29;
  matrix1(16, 12) = 1.19;
  matrix1(16, 13) = 1.09;
  matrix1(16, 14) = 1.54;
  matrix1(16, 15) = 1.59;
  matrix1(16, 16) = 1.69;
  matrix1(16, 17) = 1.87;
  matrix1(16, 18) = 1.91;
  matrix1(16, 19) = 1.45;

  matrix1(17, 0) = 1.57;
  matrix1(17, 1) = 1.73;
  matrix1(17, 2) = 1.21;
  matrix1(17, 3) = 1.20;
  matrix1(17, 4) = 1.36;
  matrix1(17, 5) = 1.11;
  matrix1(17, 6) = 1.90;
  matrix1(17, 7) = 1.43;
  matrix1(17, 8) = 1.20;
  matrix1(17, 9) = 1.34;
  matrix1(17, 10) = 1.78;
  matrix1(17, 11) = 1.03;
  matrix1(17, 12) = 1.60;
  matrix1(17, 13) = 1.00;
  matrix1(17, 14) = 1.62;
  matrix1(17, 15) = 1.75;
  matrix1(17, 16) = 1.26;
  matrix1(17, 17) = 1.73;
  matrix1(17, 18) = 1.53;
  matrix1(17, 19) = 1.41;

  matrix1(18, 0) = 1.10;
  matrix1(18, 1) = 1.27;
  matrix1(18, 2) = 1.92;
  matrix1(18, 3) = 1.09;
  matrix1(18, 4) = 1.89;
  matrix1(18, 5) = 1.52;
  matrix1(18, 6) = 1.79;
  matrix1(18, 7) = 1.16;
  matrix1(18, 8) = 1.50;
  matrix1(18, 9) = 1.44;
  matrix1(18, 10) = 1.47;
  matrix1(18, 11) = 1.30;
  matrix1(18, 12) = 1.01;
  matrix1(18, 13) = 1.93;
  matrix1(18, 14) = 1.58;
  matrix1(18, 15) = 1.97;
  matrix1(18, 16) = 1.69;
  matrix1(18, 17) = 1.28;
  matrix1(18, 18) = 1.39;
  matrix1(18, 19) = 1.37;

  matrix1(19, 0) = 1.30;
  matrix1(19, 1) = 1.05;
  matrix1(19, 2) = 1.81;
  matrix1(19, 3) = 1.11;
  matrix1(19, 4) = 1.88;
  matrix1(19, 5) = 1.42;
  matrix1(19, 6) = 1.41;
  matrix1(19, 7) = 1.15;
  matrix1(19, 8) = 1.17;
  matrix1(19, 9) = 1.87;
  matrix1(19, 10) = 1.90;
  matrix1(19, 11) = 1.56;
  matrix1(19, 12) = 1.48;
  matrix1(19, 13) = 1.97;
  matrix1(19, 14) = 1.23;
  matrix1(19, 15) = 1.27;
  matrix1(19, 16) = 1.36;
  matrix1(19, 17) = 1.27;
  matrix1(19, 18) = 1.48;
  matrix1(19, 19) = 1.53;

  matrix1.PrintWolfram();
  matrix1.PrintPlanet();

  double result_check = 0.0358009468269194807741324658459869567154;

  double result = matrix1.Determinant();
  ASSERT_NEAR(result_check, result, 1e-9);
}

TEST(test_class, test_determinant111) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;
  double result_check = -0.02;

  double result = matrix1.Determinant();
  ASSERT_NEAR(result_check, result, 1e-9);
}

TEST(test_class, test_determinant112) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 0;
  matrix1(0, 1) = 1;
  matrix1(0, 2) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;
  matrix1(1, 2) = 5;
  matrix1(2, 0) = 6;
  matrix1(2, 1) = 0;
  matrix1(2, 2) = 7;
  double result_check = -39;

  matrix1.PrintWolfram();

  double result = matrix1.Determinant();
  ASSERT_NEAR(result_check, result, 1e-9);
}

TEST(test_class, test_determinant113) {
  S21Matrix matrix1{6, 6};
  EXPECT_EQ(matrix1.get_cols(), 6);
  EXPECT_EQ(matrix1.get_rows(), 6);

  matrix1(0, 0) = -8.25324401422404;
  matrix1(1, 0) = 7.73323425720446;
  matrix1(2, 0) = 1.84863350028172;
  matrix1(3, 0) = -10.0115760930348;
  matrix1(4, 0) = -5.15668712323532;
  matrix1(5, 0) = 0.833224474685267;
  matrix1(0, 1) = 6.72777522937395;
  matrix1(1, 1) = -5.02706401585601;
  matrix1(2, 1) = -0.966418515890837;
  matrix1(3, 1) = 7.74789611180313;
  matrix1(4, 1) = 0.869955397676677;
  matrix1(5, 1) = -2.01394975557923;
  matrix1(0, 2) = -4.55829650838859;
  matrix1(1, 2) = 3.51532235136256;
  matrix1(2, 2) = -7.3990064188838;
  matrix1(3, 2) = 0.485122002195567;
  matrix1(4, 2) = 9.88733662408777;
  matrix1(5, 2) = -3.07178143155761;
  matrix1(0, 3) = -6.01939426595345;
  matrix1(1, 3) = -7.33630517800339;
  matrix1(2, 3) = -3.09628330147825;
  matrix1(3, 3) = 8.41876223543659;
  matrix1(4, 3) = -3.80699184164405;
  matrix1(5, 3) = 1.82289709686302;
  matrix1(0, 4) = 9.28037635562941;
  matrix1(1, 4) = 8.25562612293288;
  matrix1(2, 4) = 3.07955321925692;
  matrix1(3, 4) = 1.94713557977229;
  matrix1(4, 4) = 7.41955809853971;
  matrix1(5, 4) = -9.39580690651201;
  matrix1(0, 5) = 2.73021495575085;
  matrix1(1, 5) = -5.90446221316233;
  matrix1(2, 5) = 5.84046185878105;
  matrix1(3, 5) = -2.47668161639012;
  matrix1(4, 5) = 1.28693996206857;
  matrix1(5, 5) = 4.85558348917402;

  matrix1.PrintWolfram();

  double result_check = -109019.85742181906954580110;
  // -109019.8574218190695458011059860276028262641611763794321624559040
  // -109019.85742181935
  double result = matrix1.Determinant();
  ASSERT_NEAR(result_check, result, 1e-9);
}