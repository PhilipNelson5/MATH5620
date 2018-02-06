#include "finDiffCoeff.hpp"
#include <iostream>

int main()
{
  for(auto && e : centralFinDiffCoeff(2, 1e-10, [](double x){return x*x;}, 5))
    std::cout << e << " ";
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
