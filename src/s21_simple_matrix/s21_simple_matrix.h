/* ************************************************************************** */
/*                                              ############       ####       */
/*                                              ############       ####       */
/*   s21_simple_matrix.h                                    ####       ####   */
/*                                                          ####       ####   */
/*   By: hubertfu@student.21-school.ru              ########           ####   */
/*                                                  ########           ####   */
/*                                              ####                   ####   */
/*   Created: 2023-06-29                        ####                   ####   */
/*   Updated: 2023-06-29                            ############       ####   */
/*                                                  ############       ####   */
/* ************************************************************************** */

// TODO: дать ссылку на реализацию правила 0
/**
 * @file s21_matrix_oop.h
 * @author Hubert Furr (hubertfu@student.21-school.ru)
 * @brief Упрощенный класс матриц, показывающий использование двух концепций:
 * - Правило 3.5 - The Rule of The Big Three (and a half)
 * - Правило 4.5 - The Rule of The Big Four (and a half)
 * via:
 * https://blog.feabhas.com/2014/12/the-rule-of-the-big-three-and-a-half-resource-management-in-c/
 * https://blog.feabhas.com/2015/01/the-rule-of-the-big-four-and-a-half-move-semantics-and-resource-management/
 *
 * Кроме это есть еще очень важное правило: правило 0 - The Rule of Zero. Такой
 * вариант реализации матриц можно посмотреть тут: <ТУТ БУДЕТ ССЫЛКА>
 *
 * via:
 * https://blog.feabhas.com/2015/01/the-rule-of-zero/
 *
 *
 * @version 1.0
 * @date 2023-06-29
 *
 * @copyright School-21 (c) 2023
 *
 */

#ifndef CPP1_S21_MATRIXPLUS_SRC_S21_SIMPLE_MATRIX_S21_SIMPLE_MATRIX_H_
#define CPP1_S21_MATRIXPLUS_SRC_S21_SIMPLE_MATRIX_S21_SIMPLE_MATRIX_H_

class SimpleMatrix final {
 public:
  SimpleMatrix() noexcept;
  explicit SimpleMatrix(int rows, int cols);
  SimpleMatrix(const SimpleMatrix& other);
  SimpleMatrix(SimpleMatrix&& other) noexcept;
  SimpleMatrix& operator=(SimpleMatrix other);
  SimpleMatrix& operator=(SimpleMatrix&& other) noexcept;
  ~SimpleMatrix() noexcept;

  void swap(SimpleMatrix& other) noexcept;

 private:
  int rows_, cols_;
  double* matrix_;
};

#endif  // CPP1_S21_MATRIXPLUS_SRC_S21_SIMPLE_MATRIX_S21_SIMPLE_MATRIX_H_
