#ifndef LAX_WENDORF_HPP
#define LAX_WENDORF_HPP

#include "../matrix/matrix.hpp"
#include "../matrix/matrix_util.hpp"
#include <iomanip>
#include <iostream>

template <std::size_t S, typename T, typename F>
std::vector<std::array<T, S - 2>> warming_and_beam(const T xDomain[],
                                            const T tDomain[],
                                            const T dx,
                                            const T dt,
                                            F eta,
                                            const T c)
{
  std::array<T, S - 2> U;
  for (auto i = 0u; i < S - 2; ++i)
  {
    auto A = xDomain[0];
    auto x = A + (i + 1) * dx;
    U[i] = eta(x);
  }

  auto a = c * dx / dt / dt;
  auto b = c * c * dx * dx / dt / dt / 2;
  std::vector<double> coeffs = {b - a, 4 * a - 2 * b, 1 - 2 * a + b};

  auto A = makeNDiag<double, S - 2, S - 2>(coeffs, -2u);

  std::vector<std::array<T, S - 2>> solution = {U};

  for (auto t = tDomain[0]; t < tDomain[1]; t += dt)
  {
    U = A * U;
    solution.push_back(U);
  }

  return solution;
}

#endif
