#ifndef VECTOR_UTILL_HPP
#define VECTOR_UTILL_HPP

#include <array>
#include <cmath>
#include <algorithm>

template <typename T, std::size_t N>
double pNorm(std::array<T, N> v, unsigned int const & p)
{
  double sum = 0.0;
  for(auto&&x:v)
    sum += std::pow(std::abs(x), p);
  return std::pow(sum, 1.0/p);
}

template <typename T, std::size_t N>
double infNorm(std::array<T, N> v)
{
  T max = std::abs(v[0]);
  for(auto&&x:v)
    max = std::max(max, std::abs(x));
  return max;
}

#endif
