#include "finDiffCoeff.hpp"
#include <iostream>

int main()
{
  auto coeffs = centralFinDiffCoeff(2, 1e-10, [](double x) { return x; }, 5);
  for (auto&& c : coeffs)
    std::cout << c << " ";
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
