#ifndef FIN_DIFF_COEFF_HPP
#define FIN_DIFF_COEFF_HPP

#include <cmath>
#include <vector>

unsigned int fact(unsigned int const& n)
{
  if(n==0)
    return 1;
  unsigned int f = 1u;
  for (auto i = 1u; i <= n; ++i)
    f *= i;
  return f;
}

unsigned int binCoeff(unsigned int const& n, unsigned int const& k)
{
  auto nf = fact(n);
  auto kf = fact(k);
  auto nkf = fact(n - k);

  return nf / (kf * nkf);
}

template <typename T, typename F>
std::vector<T> centralFinDiffCoeff(unsigned int const& n, unsigned int const& h, F f, T x)
{
  std::vector<T> coeffs;
  for (auto i = 0u; i <= n; ++i)
  {
    coeffs.push_back(pow(-1, i) * binCoeff(n, i) * f(x + (n / 2.0 - i) * h));
  }
  return coeffs;
}
#endif
