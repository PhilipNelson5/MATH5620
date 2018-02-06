---
title: Finite Difference Coefficients
math: true
layout: default
---

{% include mathjax.html %}

<a href="https://philipnelson5.github.io/MATH5620/SoftwareManual"> Table of Contents </a>
# Finite Difference Coefficients

**Routine Name:** centralFinDiffCoeff

**Author:** Philip Nelson

**Language:** C++

## Description

`centralFinDiffCoeff` returns a vector of the coefficients for finite difference approximations of an arbitrary order of accuracy for a given derivative. This routine uses binomial coefficients to calculate the coefficients with the formula below:

\\[ \delta_{h}^{n}[f](x)=\sum _{i=0}^{n}(-1)^{i}{\binom{n}{i}}f\left(x+\left({\frac{n}{2}}-i\right)h\right)\\]

```
$ make
$ ./finDiffCoeff.out
```

This will compile and run the driver program.

## Input

`std::vector<T> centralFinDiffCoeff(unsigned int const& n, unsigned int const& h, F f, T x)`

* `unsigned int n` - order of the derivative
* `unsigned int h` - the value of \\(h\\)
* `F f` - the function \\(f\\), given as a lambda
* `T x` - the point where \\(f\\) is evaluated at

## Output

`centralFinDiffCoeff` returns a vector of coefficients.

## Code
{% highlight c++ %}
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
{% endhighlight %}

## Example
{% highlight c++ %}
int main()
{
  auto coeffs = centralFinDiffCoeff(2, 1e-10, [](double x) { return x; }, 5);
  for (auto&& c : coeffs)
    std::cout << c << " ";
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
{% endhighlight %}

## Result
```
5 -10 5
```

**Last Modification date:** 11 January 2018
