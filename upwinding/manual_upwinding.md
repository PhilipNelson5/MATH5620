---
title: Upwinding
math: true
layout: default
---

{% include mathjax.html %}

<a href="https://philipnelson5.github.io/MATH5620/SoftwareManual"> Table of Contents </a>
# Upwinding

**Routine Name:** `upwinding`

**Author:** Philip Nelson

**Language:** C++

## Description

`upwinding` is in a class of numerical discretization methods for solving hyperbolic partial differential equations. Upwind schemes use an adaptive or solution-sensitive finite difference stencil to numerically simulate the direction of propagation of information in a flow field. The upwind schemes attempt to discretize hyperbolic partial differential equations by using differencing biased in the direction determined by the sign of the characteristic speeds. Historically, the origin of upwind methods can be traced back to the work of Courant, Isaacson, and Rees who proposed the CIR method.[1](https://en.wikipedia.org/wiki/Upwind_scheme)

## Input

```
upwinding(const T xDomain[],
          const T tDomain[],
          const T dx,
          const T dt,
          F eta,
          const T c
         )
```

* `T xDomain[]` - two member array with the spacial bounds
* `T tDomain[]` - two member array with the temporal bounds
* `T dx` - the spacial step
* `T dt` - the temporal step
* `F eta` - the function eta
* `T c` - the constant

## Output

A `std::vector<std::array<T, S - 2>>` with the solution over time.

## Code
{% highlight c++ %}
template <std::size_t S, typename T, typename F>
std::vector<std::array<T, S - 2>> upwinding(const T xDomain[],
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

  std::vector<double> coeffs = {c * dx / dt, 1 - c * dx / dt};

  auto A = makeNDiag<double, S - 2, S - 2>(coeffs, -1u);

  std::vector<std::array<T, S - 2>> solution = {U};

  for (auto t = tDomain[0]; t < tDomain[1]; t += dt)
  {
    U = A * U;
    solution.push_back(U);
  }

  return solution;
}
{% endhighlight %}

## Example
{% highlight c++ %}
int main()
{
  constexpr double xDomain[] = {0.0, 1.0};
  constexpr double tDomain[] = {0.0, 1.0};
  // constexpr auto dt = 1.0e-3;
  // constexpr auto dx = 1.0e-3;
  constexpr auto dt = .1; // for view able output
  constexpr auto dx = .1; // for view able output
  constexpr std::size_t S = ((xDomain[1] - xDomain[0]) / dx);
  auto c = 0.7;
  auto eta = [](const double& x) -> double {
    return (x >= 0.3 && x <= 0.6) ? 100 : 0;
  };

  auto solution = upwinding<S, double>(xDomain, tDomain, dx, dt, eta, c);

  for (auto i = 0u; i < solution.size(); ++i)
  {
    for (auto j = 0u; j < solution[i].size(); ++j)
    {
      std::cout << std::setprecision(3) << std::setw(7) << solution[i][j]
    }
    std::cout << '\n';
  }

  return EXIT_SUCCESS;
}
{% endhighlight %}

## Result
```
      0       0     100     100     100       0       0       0
      0       0      30     100     100      70       0       0
      0       0       9      51     100      91      49       0
      0       0     2.7    21.6    65.7    97.3    78.4    34.3
      0       0    0.81    8.37    34.8    75.2    91.6    65.2
      0       0   0.243    3.08    16.3    46.9    80.1    83.7
      0       0  0.0729    1.09    7.05    25.5    56.9    81.2
      0       0  0.0219   0.379    2.88    12.6    34.9    64.2
      0       0 0.00656   0.129    1.13    5.79    19.3    43.7
      0       0 0.00197  0.0433   0.429    2.53    9.84    26.6
      0       0 0.00059  0.0144   0.159    1.06    4.72    14.9
      0       0 0.000177 0.00472  0.0578   0.429    2.16    7.76
```

**Last Modification date:** 5 May 2018
