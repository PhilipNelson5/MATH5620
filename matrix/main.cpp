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

void runTests()
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
  Matrix<double, 4, 4> m({{-2, 1, 0, 0}, {1, -2, 1, 0}, {0, 1, -2, 1}, {0, 0, 1, -2}});
  std::array<double, 4> n = {4, 7, 2, 5};
  auto o = m * n;

  std::cout << BLUE << "[      TESTS BEGINNING     ]\n\n" << RESET;
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
  test(pNorm(l, 1), 54, "vector one norm");
  test(infNorm(l), 20, "vector infinity norm");
  test(oneNorm(i), 13, "matrix one norm");
  test(infNorm(i), 17, "matrix infinity norm");
  test(pNorm(m.jacobiIteration(o) - n, 2) < 1e-10, true, "jacobi iteration");

  std::cout << BLUE << "[      TESTS COMPLETE     ]\n\n" << RESET;
}

int main()
{
  // runTests();

  // Matrix<double, 4, 4> U({{3, 5, -6, 4}, {0, 4, -6, 9}, {0, 0, 3, 11}, {0, 0, 0, -9}});
  // std::array<double, 4> x{4, 6, -7, 9};
  // auto B = U * x;
  //
  // std::cout << " U\n" << U << std::endl;
  // std::cout << " b\n" << B << std::endl;
  // std::cout << " Real x\n" << x << std::endl;
  // std::cout << " Calculated x\n";
  // std::cout << U.backSub(B) << std::endl;
  //
  // std::cout << " v" << l << std::endl;
  // std::cout << "1 Norm: " << pNorm(l, 1) << std::endl;
  // std::cout << "2 Norm: " << pNorm(l, 2) << std::endl;

  // Matrix<double, 4, 4> A({{-2, 1, 0, 0}, {1, -2, 1, 0}, {0, 1, -2, 1, 0}, {0, 0, 1, -2}});
  Matrix<double, 5, 5> A(
    [](unsigned int const& i, unsigned int const& j) { return 1.0 / (i + j + 1.0); });
  auto eigvec = powerIteration(A, 1000u);
  auto eigval = pNorm(A * eigvec, 2);
  std::cout << "A\n" << A << std::endl;
  std::cout << "v\n" << eigvec << std::endl;
  std::cout << "lambda\n" << eigval << std::endl << std::endl;
  std::cout << "A*v\n" << A * eigvec << std::endl;
  std::cout << "lambda*v\n" << eigval * eigvec << std::endl;
}
