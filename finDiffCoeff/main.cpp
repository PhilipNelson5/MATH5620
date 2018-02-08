#include "finDiffCoeff.hpp"
#include <iostream>
#include "../matrix/matrix.hpp"
#include "../matrix/matrix_util.hpp"
#include "../matrix/vector_util.hpp"

int main()
{
  auto coeffs = centralFinDiffCoeff<double, 1, 4>();

  std::cout << coeffs << std::endl;
  return EXIT_SUCCESS;
}
