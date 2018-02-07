#include "matrix.hpp"
#include "matrix_util.hpp"
#include "termColors.hpp"
#include "vector_util.hpp"
#include <iostream>
#include <string>

template <typename T, typename R>
void test(T a, R r, std::string name)
{
  std::cout << GREEN << "[RUN     ] " << RESET << name << std::endl;
  if (a == r)
    std::cout << GREEN << "[      OK] " << RESET << std::endl;
  else
    std::cout << RED << "[    FAIL] " << RESET << std::endl;
}

int main()
{
  Matrix<int, 2, 2> a({{4, 0}, {1, -9}});
  Matrix<int, 2, 2> _a({{8, 0}, {2, -18}});
  Matrix<int, 2, 3> b({{1, 2, 3}, {4, 5, 6}});
  Matrix<int, 3, 2> c({{7, 8}, {9, 10}, {11, 12}});
  Matrix<int, 2, 2> _bc({{58, 64}, {139, 154}});
  Matrix<int, 2, 2> d({{3, 8}, {4, 6}});
  Matrix<int, 2, 2> e({{4, 0}, {1, -9}});
  Matrix<int, 2, 2> _de_add({{7, 8}, {5, -3}});
  Matrix<int, 2, 2> _de_sub({{-1, 8}, {3, 15}});
  Matrix<int, 2, 2> _e_neg({{-4, 0}, {-1, 9}});
  Matrix<int, 3, 3> _id({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
  Matrix<int, 3, 3> f({{6, 1, 1}, {4, -2, 5}, {2, 8, 7}});
  Matrix<int, 1, 3> g({{2, 4, 6}});
  Matrix<int, 3, 1> h({{7}, {9}, {11}});
  Matrix<int, 3, 3> i({{6, 1, 1}, {4, -2, 5}, {2, 8, 7}});
  Matrix<int, 2, 3> _i_row({{6, 1, 1}, {2, 8, 7}});
  Matrix<int, 3, 2> _i_col({{6, 1}, {4, 5}, {2, 7}});
  Matrix<int, 3, 3> _i_swap({{4, -2, 5}, {6, 1, 1}, {2, 8, 7}});
  Matrix<int, 3, 3> j({{6, 1, 1}, {4, -2, 5}, {2, -8, 7}});
  Matrix<int, 3, 3> k({{6, 1, 1}, {4, -2, 5}, {2, 8, 7}});
  k.swapRows(0, 1);
  std::array<double, 4> l = {11, 18, -20, 5};

  test(d + e, _de_add, "matrix addition");
  test(d - e, _de_sub, "matrix subtraction");
  test(b * c, _bc, "matrix multiplication");
  test(2 * a, _a, "scalar * matrix");
  test(a * 2, _a, "matrix * scalar");
  test(-e, _e_neg, "unary minus, negation");
  test(identity<double, 3>(), _id, "identity construction");
  test(determinant(f), -306, "determinant");
  test(dotProduct(g, h), 116, "dot product");
  test(removeRow(i, 1), _i_row, "remove row");
  test(removeCol(i, 1), _i_col, "remove col");
  test(k, _i_swap, "swap row");
  test(j.findLargestInCol(1, 0), 2u, "find largest element in column");
  test(pNorm(l, 1), 54, "one norm");
  test(infNorm(l), 20, "infinity norm");

  // Matrix<double, 4, 4> A1({{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 1, 0}, {1, 1, 1, 1}});
  // Matrix<double, 4, 4> A(1, 10);
  // std::array<double, 4> B = {4, 7, 2, 5};
  // std::array<double, 4> X = {4, 7, 2, 5};
  // auto B = A*X;
  // std::cout << " A" << std::endl << A << std::endl;
  // std::cout << " b" << std::endl << B << std::endl;
  // std::cout << " x" << std::endl << X << std::endl;
  //
  // std::cout << A.solveLinearSystemLU(B) << std::endl;
  //
  // std::cout << B+X << std::endl;
  // std::cout << X-B << std::endl;

  Matrix<double, 4, 4> __A({{-2, 1, 0, 0}, {1, -2, 1, 0}, {0, 1, -2, 1}, {0, 0, 1, -2}});
  std::array<double, 4> __x = {4, -3, 5, 1};

  auto __d = __A * __x;
  auto testx = __A.triDiagThomas(__d);

  std::cout << " A\n" << __A << std::endl;
  std::cout << " d\n" << __d << std::endl;
  std::cout << " Real x\n" << __x << std::endl;
  std::cout << " Calculated x\n" << testx << std::endl;
}
