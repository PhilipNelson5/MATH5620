---
title: Thomas Algorithm
math: true
layout: default
---

{% include mathjax.html %}

<a href="https://philipnelson5.github.io/MATH5620/SoftwareManual"> Table of Contents </a>
# Logistic Differential Equation

**Routine Name:** triDiagThomas

**Author:** Philip Nelson

**Language:** C++

## Description

`triDiagThomas` solves a tridiagonal linear system of equations using the Thomas Algorithm.

\\[\begin{bmatrix}

b_{1}&{c_{1}&{}&{}&{0}\\{a_{2}&{b_{2}&{c_{2}&{}&{}\\{}&{a_{3}&{b_{3}&\ddots &{}\\{}&{}&\ddots &\ddots &{c_{n-1}\\{0}&{}&{}&{a_{n}&{b_{n}\\
\end{bmatrix}

\begin{bmatrix}
{x_{1}}\\{x_{2}}\\{x_{3}}\\\vdots \\{x_{n}}\\
\end{bmatrix}

=

\begin{bmatrix}
d_{1}}\\{d_{2}}\\{d_{3}\\\vdots \\{d_{n}\\
\end{bmatrix} \\]

## Input

`triDiagThomas` can be called in two ways:

#### Method 1:
`std::array<T, M> triDiagThomas(std::array<T, M> const& d)`

* `std::array<T, M> d` - an array of type `T` and size `M` (d vector)

```
std::array<T, M> triDiagThomas(std::array<T, M> const& a,
                               std::array<T, M> const& b,
                               std::array<T, M> const& c,
                               std::array<T, M> const& d)
```

* `std::array<T, M> a` - an array of type `T` and size `M` (main diagonal)
* `std::array<T, M> b` - an array of type `T` and size `M` (lower diagonal)
* `std::array<T, M> c` - an array of type `T` and size `M` (upper diagonal)
* `std::array<T, M> d` - an array of type `T` and size `M` (d vector)

## Output

`triDiagThomas` returns a `std::array<T, M>` with the solution vector `x`

## Code
{% highlight c++ %}
std::array<T, M> triDiagThomas(std::array<T, M> const& a,
                               std::array<T, M> const& b,
                               std::array<T, M> const& c,
                               std::array<T, M> const& d)
{
  std::array<double, M> cp, dp, x;
  cp[0] = c[0] / b[0];
  dp[0] = d[0] / b[0];
  for (auto i = 1u; i < N; ++i)
  {
    double bottom = (b[i] - (a[i] * cp[i - 1]));
    cp[i] = c[i] / bottom;
    dp[i] = (d[i] - (a[i] * dp[i - 1])) / bottom;
  }

  x[N - 1] = dp[N - 1];

  for (auto i = (int)N - 2; i >= 0; --i)
  {
    x[i] = dp[i] - cp[i] * x[i + 1];
  }
  return x;
}
{% endhighlight %}

## Example
{% highlight c++ %}
int main()
{
  double a = 1.0;
  double b = 2.0;
  double t = 50;
  double p0 = 10.0;

  std::cout << "alpha:\t" << a << "\nbeta:\t" << b << "\ntime:\t" << t << "\nP0:\t" << p0 << std::endl;

  std::cout << "------------\nresult:\t" << logistic(a, b, t, p0) << std::endl;
}
{% endhighlight %}

## Result
```
alpha:	1
beta:	2
time:	50
P0:	10
-----------
result:	0.5
```

**Last Modification date:** 17 January 2018
