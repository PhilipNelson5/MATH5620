---
title: Power Iteration
math: true
layout: default
---

{% include mathjax.html %}

<a href="https://philipnelson5.github.io/MATH5620/SoftwareManual"> Table of Contents </a>
# Power Iteration

**Routine Name:** powerIteration

**Author:** Philip Nelson

**Language:** C++

## Description

`powerIteration` calculates the largest Eigenvector of a `N`x`N` matrix. The largest Eigenvalue can be determined with the 2-Norm.

## Input


`powerIteration(Matrix<T, N, N> const& A, unsigned int const& MAX)` requires:

* `Matrix<T, N, N> const& A` - an `N`x`N` matrix
* `unsigned int const& MAX` - the maximum number of iterations

## Output

An array with the largest Eigenvector

## Code
{% highlight c++ %}
template <typename T, std::size_t N>
std::array<T, N> powerIteration(Matrix<T, N, N> const& A, unsigned int const& MAX)
{
  std::array<T, N> b_k;

  for (auto&& e : b_k)
    e = randDouble(0.0, 10.0);

  for (auto i = 0u; i < MAX; ++i)
  {
    auto Ab_k = A * b_k;
    auto norm = pNorm(Ab_k, 2);
    b_k = Ab_k / norm;
  }
  return b_k;
}
{% endhighlight %}

## Example
{% highlight c++ %}
int main()
{
  Matrix<double, 5, 5> A( // 5x5 Hilbert matrix
    [](unsigned int const& i, unsigned int const& j) { return 1.0 / (i + j + 1.0); });
  auto eigval = pNorm(A * eigvec, 2);
  std::cout << "A\n" << A << std::endl;
  std::cout << "v\n" << eigvec << std::endl;
  std::cout << "lambda\n" << eigval << std::endl << std::endl;
  std::cout << "A*v\n" << A * eigvec << std::endl;
  std::cout << "lambda*v\n" << eigval * eigvec << std::endl;
}
{% endhighlight %}

## Result
```
A
|          1       0.5     0.333      0.25       0.2 |
|        0.5     0.333      0.25       0.2     0.167 |
|      0.333      0.25       0.2     0.167     0.143 |
|       0.25       0.2     0.167     0.143     0.125 |
|        0.2     0.167     0.143     0.125     0.111 |

v
[      0.768     0.446     0.322     0.253      0.21 ]

lambda
1.57

A*v
[        1.2     0.699     0.504     0.397     0.329 ]

lambda*v
[        1.2     0.699     0.504     0.397     0.329 ]
```

**Last Modification date:** 22 February 2018
