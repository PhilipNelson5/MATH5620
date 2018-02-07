#ifndef VECTOR_UTILL_HPP
#define VECTOR_UTILL_HPP

#include <algorithm>
#include <array>
#include <cmath>

template <typename T, std::size_t N>
double pNorm(std::array<T, N> v, unsigned int const& p)
{
  double sum = 0.0;
  for (auto&& x : v)
    sum += std::pow(std::abs(x), p);
  return std::pow(sum, 1.0 / p);
}

template <typename T, std::size_t N>
double infNorm(std::array<T, N> v)
{
  T max = std::abs(v[0]);
  for (auto&& x : v)
    max = std::max(max, std::abs(x));
  return max;
}

#define vector_add_subtract(op)                                                               \
  template <typename T, typename U, typename R = decltype(T() op U()), std::size_t N>         \
  std::array<R, N> operator op(std::array<T, N> const& a, std::array<U, N> const& b)          \
  {                                                                                           \
    std::array<R, N> result;                                                                  \
    for (auto i = 0u; i < N; ++i)                                                             \
      result[i] = a[i] op b[i];                                                               \
    return result;                                                                            \
  }

vector_add_subtract(+) vector_add_subtract(-)

  template <typename T, std::size_t M>
  std::ostream& operator<<(std::ostream& o, std::array<T, M> const& a)
{
  o << "[ ";
  for (auto i = 0u; i < M; ++i)
    o << std::setw(9) << std::setprecision(4) << std::setfill(' ') << a[i];
  o << " ]" << std::endl;

  return o;
}

#endif
