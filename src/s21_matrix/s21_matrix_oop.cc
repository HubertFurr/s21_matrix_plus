#include "./../s21_matrix_oop.h"

#include <cmath>
#include <iostream>

/**
 * @brief Конструктор по умолчанию (Default constructor)
 * Создает объект S21Matrix размером [3 x 3], заполненный нулями
 *
 * Выносим объявление полей в initializer list, чтобы избежать двойной
 * инициализации.
 *
 * Используем new c {} (можно и () - для double нет разницы) - чтобы выделить
 * память с value-initialization, чтобы инициализировать значения нулями (т.к.
 * double - POD-тип)
 */
S21Matrix::S21Matrix()
    : rows_(3), cols_(3), matrix_(new double[rows_ * cols_]{}) {
  std::cout << "Default constructor" << std::endl;
}

/**
 * @brief Параметризованный конструктор (Parameterized Constructor)
 * Создает объект S21Matrix размером [rows x cols], заполненный нулями
 */
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  std::cout << "int int constructor" << std::endl;
  if (rows_ <= 0 || cols_ <= 0) {
    rows_ = 0;
    cols_ = 0;
    throw std::length_error("matrix size must be greater than 0");
  }

  matrix_ = new double[rows_ * cols_]{};
}

/**
 * @brief Конструктор копирования (Copy Constructor)
 * Создает объект S21Matrix путем копирования данных из объекта other
 */
S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_),
      cols_(other.cols_),
      matrix_(new double[rows_ * cols_]{}) {
  std::cout << "Copy constructor" << std::endl;
  std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
}

/**
 * @brief Конструктор переноса (Move Constructor)
 * Создает объект S21Matrix путем передачи владения ресурсами от объекта other
 *
 * noexcept - указывает, что наша функция (конструктор переноса) не генерирует
 * (не выбрасывает) исключение или аварийно завершает свою работу. Компилятор
 * рекомендует использовать слово noexcept для конструктора переноса и оператора
 * переноса (т.к. не происходит никаких операций с памятью, а происходит простое
 * присвоение указателя)
 *
 * Noexcept сильно уменьшает размер итогового бинарного файла и ускоряет работу
 * программы. Но использовать его необходимо осторожно, т.к. если функция,
 * помеченная noexcept, выпустит исключение наружу, то ваша программа вызовет
 * std::terminate() и завершится, даже не соблаговолив вызвать деструкторы для
 * уже созданных переменных (стек НЕ обязан развернуться).
 */
S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  std::cout << "Move constructor" << std::endl;
  // Обязательно зануляем указатель из other, т.к. в противном случае оба
  // указателя будут указывать на один участок памяти и при вызове деструктора
  // other будет очищена память текущего объекта
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

/**
 * @brief Освобождает память, выделенную под массив matrix_. Эта функция будет
 * вызываться из других функций в случаях, когда требуется выполнить
 * перераспределение памяти или освобождение памяти.
 *
 * Проверка на nullptr не производится, т.к. это успешно делает сам delete
 * В качестве альтернативы можно было бы контролировать необходимость очистки
 * памяти по rows_ и cols_ (и учитывать это во всей программе)
 */
void S21Matrix::Free() {
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  // Для избежания сбоев при повторном освобождении указателей и повторном
  // использовании указателей
  matrix_ = nullptr;
}

/**
 * @brief Деструктор объекта (Destructor)
 * Вызывается, когда заканчивается время жизни объекта, чтобы освободить
 * ресурсы, занимаемые объектом
 */
S21Matrix::~S21Matrix() { Free(); }

/**
 * @brief Оператор присваивания копированием
 *
 * Если в программе объявить класс, в котором оператор присваивания не
 * перегружается, то для этого класса компилятором будет создан оператор
 * присваивания по умолчанию. При вызове оператора присваивания по умолчанию
 * происходит побайтовое копирование одного экземпляра класса другому.
 *
 * В нашем случае это недопустимо, т.к. в этом случае 2 экземпляра S21Matrix в
 * поле matrix_ будут указывать на один и тот же участок памяти
 *
 * @param other копируемый объект S21Matrix
 * @return S21Matrix&
 */
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  std::cout << "Use =&" << std::endl;
  // Проверка на самоприсваивание, иначе после Free() уже нечего будет
  // присваивать (т.к. всё удалится)
  if (this != &other) {
    Free();

    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = new double[rows_ * cols_]();

    std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
  }

  return *this;
}

/**
 * @brief Оператор присваивания переносом
 *
 * Цель использования оператора переноса такая же, как и конструктора переноса –
 * ускорить выполнение программы за счет избежания непосредственного копирования
 * данных при присваивании так называемых rvalue-ссылок, которые используются в
 * выражениях в правой части оператора присваивания.
 *
 * Если в классе не реализован оператор переноса, то этот оператор заменяется
 * оператором копирования.
 *
 * В общем случае оператор состоит из следующих действий:
 * 1) Проверка, не происходит ли присваивание экземпляра самому себе в случаях,
 * когда функция может каким-либо образом возвращать этот же экземпляр
 * 2) Освобождение памяти под выделенные внутренние данные. Экземпляр lvalue уже
 * создан ранее и в нем уже есть некоторые данные;
 * 3) Присваивание внутренним указателям адресов данных, которые необходимо
 * скопировать в текущий экземпляр.
 *
 * Использование noexcept - см. описание конструктора переноса
 *
 * @param other объект S21Matrix, у которого забираем владение ресурсами
 * @return S21Matrix&
 */
S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  std::cout << "Use =&&" << std::endl;
  if (this != &other) {
    Free();

    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }

  return *this;
}

/**
 * @brief Индексация по элементам матрицы (строка row, колонка col).
 *
 * Возвращает ссылку на элемент, которая позволяет как получить его значение,
 * так и изменить при необходимости.
 *
 * @param row номер столбца запрашиваемого элемента
 * @param col номер строки запрашиваемого элемента
 * @return double& ссылка на значение (row, col)
 */
double &S21Matrix::operator()(int row, int col) {
  return get_matrix_element(row, col);
}

/**
 * @brief Индексация по элементам матрицы (строка row, колонка col).
 *
 * Перегрузка оператора () для const-объектов. В целом идентичен обычной
 * перегрузке оператора (), за исключением того, что возвращает const-ссылку.
 * Соответственно позволяет получить значение элемента, но не позволяет его
 * изменить.
 *
 * @param row номер столбца запрашиваемого элемента
 * @param col номер строки запрашиваемого элемента
 * @return double& const-ссылка на значение (row, col)
 */
const double &S21Matrix::operator()(int row, int col) const {
  return get_matrix_element(row, col);
}

/**
 * @brief Accessor (Getter) поля rows_
 *
 * В общем случае метод, позволяющий получить данные, доступ к которым напрямую
 * ограничен (приватное поле). Основное назначение - реализовать гибкий
 * механизм инкапсуляции
 *
 * @return int значение поля rows_
 */
int S21Matrix::get_rows() const noexcept { return rows_; }

/**
 * @brief Accessor (Getter) поля cols_
 *
 * @return int значение поля cols_
 */
int S21Matrix::get_cols() const noexcept { return cols_; }

/**
 * @brief Mutator (Setter) поля rows_
 *
 * В общем случае метод, позволяющий модифицировать данные, доступ к которым
 * напрямую ограничен (приватное поле). Основное назначение - реализовать гибкий
 * механизм инкапсуляции, позволив изменить значение поля, обработав при этом
 * все ограничения (произведя дополнительные действия при необходимости) и
 * сохранив инвариант объекта
 *
 * @param new_rows новое значение для rows_
 */
void S21Matrix::set_rows(int new_rows) {
  if (new_rows <= 0) {
    throw std::length_error("matrix size must be greater than 0");
  }

  if (new_rows < rows_) {
    rows_ = new_rows;
  } else if (new_rows > rows_) {
    S21Matrix tmp{new_rows, cols_};
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    *this = std::move(tmp);
  }
}

/**
 * @brief Mutator (Setter) поля cols_
 *
 * @param new_rows новое значение для cols_
 */
void S21Matrix::set_cols(int new_cols) {
  if (new_cols <= 0) {
    throw std::length_error("matrix size must be greater than 0");
  }

  if (new_cols < cols_) {
    cols_ = new_cols;
  } else if (new_cols > cols_) {
    S21Matrix tmp{rows_, new_cols};
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    *this = std::move(tmp);
  }
}

/**
 * @brief По сути accessor и mutator для поля matrix_, однако не совсем и он
 * приватный, т.к. позволяет и получить и изменить данные. Нужен для
 * использования в перегрузке оператора (), который уже разделяет поведение для
 * const и не-const объектов
 *
 * @param row номер столбца запрашиваемого элемента
 * @param col номер строки запрашиваемого элемента
 * @return double& ссылка на значение (row, col)
 */
double &S21Matrix::get_matrix_element(int row, int col) const {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input for (), index is out of range.");
  }
  return matrix_[row * cols_ + col];
}

/**
 * @brief Проверяет матрицы на равенство между собой
 *
 * Матрицы считаются равными, если у них одинаковый размер и элементы с
 * одинаковым индексом отличаются не более чем на this->epsilon_
 *
 * @param other сравниваемая матрица
 * @return true если матрицы равны
 * @return false если матрицы не равны
 */
bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  bool result = true;

  if (rows_ != other.get_rows() || cols_ != other.get_cols()) {
    result = false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (std::fabs(other(i, j) - (*this)(i, j)) > epsilon_) {
          result = false;
          break;
        }
      }

      if (result == false) {
        break;
      }
    }
  }

  return result;
}

/**
 * @brief Перегрузка оператора == для объекта
 *
 * @param other сравниваемая матрица
 * @return true если матрицы равны
 * @return false если матрицы не равны
 */
bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

/**
 * @brief Прибавляет вторую матрицы к текущей
 *
 * Суммой двух матриц A[m × n] и B[m × n] одинаковых размеров называется матрица
 * C[m × n] = A + B тех же размеров, элементы которой определяются равенствами
 * C(i,j) = A(i,j) + B(i,j).
 *
 * Сложить матрицы разных размеров нельзя
 *
 * @param other 2е слагаемое (матрица)
 */
void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.get_rows() || cols_ != other.get_cols()) {
    throw std::logic_error("Incorrect matrix size for Sum");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i * cols_ + j] =
          matrix_[i * cols_ + j] + other.matrix_[i * cols_ + j];
    }
  }
}

/**
 * @brief Перегрузка оператора + для объекта
 *
 * @param other 2е слагаемое (матрица)
 * @return S21Matrix результат сложения двух матриц
 */
S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  std::cout << "start operator+" << std::endl;
  // SumMatrix(other);
  // return *this;
  S21Matrix tmp = *this;
  tmp.SumMatrix(other);
  std::cout << "end operator+" << std::endl;
  return tmp;
  // return std::move(tmp);
}

/**
 * @brief Перегрузка оператора += для объекта
 *
 * @param other 2е слагаемое (матрица)
 * @return S21Matrix результат сложения двух матриц
 */
S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

/**
 * @brief Вычитает из текущей матрицы другую
 *
 * Разностью двух матриц A[m × n] и B[m × n] одинаковых размеров называется
 * матрица C[m × n] = A - B тех же размеров, элементы которой определяются
 * равенствами C(i,j) = A(i,j) - B(i,j).
 *
 * Вычесть матрицы разных размеров нельзя
 *
 * @param other
 */
void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.get_rows() || cols_ != other.get_cols()) {
    throw std::logic_error("Incorrect matrix size for Sub");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i * cols_ + j] =
          matrix_[i * cols_ + j] - other.matrix_[i * cols_ + j];
    }
  }
}

/**
 * @brief Перегрузка оператора - для объекта
 *
 * @param other Вычитаемое (матрица)
 * @return S21Matrix Результат вычитания двух матриц (матрица)
 */
S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix tmp = *this;
  tmp.SubMatrix(other);
  return tmp;
}

/**
 * @brief Перегрузка оператора -= для объекта
 *
 * @param other Вычитаемое (матрица)
 * @return S21Matrix Результат вычитания двух матриц (матрица)
 */
S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

void S21Matrix::MulNumber(const double number) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i * cols_ + j] = matrix_[i * cols_ + j] * number;
    }
  }
}

S21Matrix operator*(const S21Matrix &matrix, const double number) {
  S21Matrix tmp(matrix);
  tmp.MulNumber(number);
  return tmp;
}

S21Matrix operator*(const double number, const S21Matrix &matrix) {
  S21Matrix tmp = matrix * number;
  return tmp;
}

S21Matrix S21Matrix::operator*=(const double number) {
  MulNumber(number);
  return *this;
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.get_rows()) {
    throw std::logic_error("Incorrect matrix size for multiplication");
  }

  S21Matrix result{rows_, cols_};

  for (int i = 0; i < result.get_rows(); i++) {
    for (int j = 0; j < result.get_cols(); j++) {
      for (int k = 0; k < cols_; k++) {
        result(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }
  *this = std::move(result);
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix tmp = *this;
  tmp.MulMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

void S21Matrix::SwapRows(int n1, int n2) {
  // TODO(hubertfu): exception?
  if (n1 != n2) {
    for (int i = 0; i < cols_; ++i) {
      std::swap((*this)(n1, i), (*this)(n2, i));
    }
  }
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix result{cols_, rows_};

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result(j, i) = (*this)(i, j);
    }
  }

  return result;
}

S21Matrix S21Matrix::GetMinorMatrix(const int skip_row,
                                    const int skip_column) const {
  // TODO(hubertfu): exception?
  S21Matrix result{rows_ - 1, cols_ - 1};

  int shift_i = 0;
  for (int i = 0; i < result.get_rows(); i++) {
    if (i == skip_row) {
      shift_i = 1;
    }
    int shift_j = 0;
    for (int j = 0; j < result.get_cols(); j++) {
      if (j == skip_column) {
        shift_j = 1;
      }
      result(i, j) = (*this)(i + shift_i, j + shift_j);
    }
  }

  return result;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_ || rows_ == 1) {
    throw std::logic_error("Incorrect matrix size for CalcComplements");
  }
  S21Matrix result{rows_, cols_};

  for (int i = 0; i < result.get_rows(); ++i) {
    for (int j = 0; j < result.get_cols(); ++j) {
      S21Matrix minor_matrix = GetMinorMatrix(i, j);
      result(i, j) = minor_matrix.Determinant();

      if ((i + j) % 2 != 0) {
        result(i, j) = -result(i, j);
      }
    }
  }

  return result;
}

/**
 * @brief функция для вычисления определителя (детерминанта) матрицы
 *
 * Прямые методы вычисления определителя могут быть основаны непосредственно на
 * его определении, как суммы по перестановкам, или на разложении Лапласа по
 * определителям меньшего порядка. Однако такие методы очень неэффективны, так
 * как требуют О(n!) операций для вычисления определителя n-го порядка.
 * Определитель матрицы 12х12 уже не посчитается за адекватное время
 *
 * Поэтому будем вычислять методом "Гаусса-Жордана", сложность данного алгоритма
 * составляет уже O(n^3)
 *
 *
 * @author Hubert Furr (hubertfu@student.21-school.ru)
 * @return double расчитанный определитель (детерминант)
 */
double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::logic_error("Incorrect matrix size for Determinant");
  }

  double result = 1;
  S21Matrix tmp = *this;
  int size = rows_;
  // std::cout << "\n\n"
  //           << "matrix:"
  //           << "\n";
  // tmp.Print();

  for (int i = 0; i < size; ++i) {
    // Выбор опорного элемента. pivoting = индекс опорного элемента
    int pivoting = i;
    for (int j = i + 1; j < size; j++) {
      if (std::abs(tmp(j, i)) > std::abs(tmp(pivoting, i))) {
        pivoting = j;
      }
    }

    if (std::abs(tmp(pivoting, i)) < epsilon_) {
      result = 0;
      break;
    }

    // Меняем местами текущую строку и строку с опорным элементом
    tmp.SwapRows(i, pivoting);
    // std::cout << "after pivo:"
    //           << "\n";
    // tmp.Print();

    result *= tmp(i, i);
    // double koef = tmp(i, i);

    // for (int j = 0; j < size; ++j) {
    // tmp(i, j) /= koef;
    // }

    if (i != pivoting) {
      result = -result;
    }

    for (int j = i + 1; j < size; ++j) {
      double el = tmp(j, i) / tmp(i, i);
      for (int k = i; k < size; ++k) {
        // вообще
        // std::cout << j << " " << k << "(" << tmp(j, k) << ") = " << tmp(i, k)
        // << " * " << el << " == " << tmp(i, k) * el << std::endl;
        tmp(j, k) -= tmp(i, k) * el;
        // tmp.Print();
      }
    }
    // std::cout << "after minus row:"
    //           << "\n";
    // tmp.Print();
  }

  return result;
}

// double S21Matrix::Determinant() const {
//   if (rows_ != cols_) {
//     throw std::logic_error("Incorrect matrix size for Determinant");
//   }

//   double result = 0;

//   if (rows_ == 1) {
//     result = (*this)(0, 0);
//   } else {
//     if (rows_ == 2) {
//       result = (*this)(0, 0) * (*this)(1, 1) - (*this)(1, 0) * (*this)(0, 1);
//     } else if (rows_ > 2) {
//       int sign = 1;

//       for (int i = 0; i < rows_; i++) {
//         S21Matrix minor_matrix = GetMinorMatrix(i, 0);
//         double det = minor_matrix.Determinant();
//         if (sign == 1) {
//           result += (*this)(i, 0) * det;
//         } else {
//           result -= (*this)(i, 0) * det;
//         }

//         sign = -sign;
//       }
//     }
//   }

//   return result;
// }

S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ != cols_) {
    throw std::logic_error("Incorrect matrix size for Inverse");
  }

  double det = Determinant();

  if (std::fabs(det) < epsilon_) {
    throw std::logic_error("Determinant must be non-zero to calculate Inverse");
  }

  S21Matrix result{rows_, cols_};

  if (rows_ == 1) {
    result(0, 0) = 1 / det;
  } else {
    S21Matrix matrix_cofactor_transposed = Transpose().CalcComplements();
    // TODO(hubertfu): мб лучше делить в цикле?
    result = matrix_cofactor_transposed * (1.0 / det);
  }

  return result;
}
