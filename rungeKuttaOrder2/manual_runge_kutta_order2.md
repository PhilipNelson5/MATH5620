---
title: Runge Kutta Order 2
math: true
layout: default
---

{% include mathjax.html %}

<a href="https://philipnelson5.github.io/MATH5620/SoftwareManual"> Table of Contents </a>
# Kunge Kutta Order 2

**Routine Name:** `runge_kutta_order2`

**Author:** Philip Nelson

**Language:** C++

## Description

`runge_kutta_order2` is in a family of implicit and explicit iterative methods, which include the well-known routine called the Euler Method, used in temporal discretization for the approximate solutions of ordinary differential equations. These methods were developed around 1900 by the German mathematicians C. Runge and M. W. Kutta.[1](https://en.wikipedia.org/wiki/Runge–Kutta_methods)

## Input

`runge_kutta_order2(T x0, T y0, T x, T dt, F f)` requires:

* `T x0` - the initial `x`
* `T y0` - the initial `y`
* `T x` - the value of `x` for which you want to find value of `y`
* `T dt` - the delta t step
* `F f` - the function defining \\(\frac{dy}{dx}\\)

## Output

The value of `y` at `x`.

## Code
{% highlight c++ %}
template <typename T, typename F>
T runge_kutta_order2(T x0, T y0, T x, T dt, F f)
{
  auto tol = maceps<T>().maceps;
  while (std::abs(x - x0) > tol)
  {
    y0 = y0 + (dt * f(x0, y0));
    x0 += dt;
  }
  return y0;
}
{% endhighlight %}

## Example
{% highlight c++ %}
int main()
{
  std::cout <<
    runge_kutta_order2(0.0, -1.0, 0.4, 0.1, [](double a, double b){return a*a+2*b;})
    << std::endl;
}
{% endhighlight %}

## Result
```
----- Lambda Differential Equation -----

lambda = 1
exact	0 -> 10
approx	0 -> 10
exact	0.2 -> 12.214
approx	0.2 -> 12.214
exact	0.4 -> 14.9182
approx	0.4 -> 14.9183
exact	0.6 -> 18.2212
approx	0.6 -> 18.2212

lambda = -1
exact	0 -> 10
approx	0 -> 10
exact	0.2 -> 8.18731
approx	0.2 -> 8.18732
exact	0.4 -> 6.7032
approx	0.4 -> 6.70321
exact	0.6 -> 5.48812
approx	0.6 -> 5.48813

lambda = 100
exact	0 -> 10
approx	0 -> 10
exact	0.2 -> 4.85165e+09
approx	0.2 -> 4.90044e+09
exact	0.4 -> 2.35385e+18
approx	0.4 -> inf
exact	0.6 -> 1.14201e+27

----- Logistic Differential Equaiton -----

p0 = 25
exact	0 -> 25
approx	0 -> 25
exact	0.2 -> 25.4922
approx	0.2 -> 25.4922
exact	0.4 -> 25.9937
approx	0.4 -> 25.9937
exact	0.6 -> 26.5049
approx	0.6 -> 26.5049

p0 = 40000
exact	0 -> 40000
approx	0 -> 40000
exact	0.2 -> 22570.2
approx	0.2 -> 22570.4
exact	0.4 -> 15815.2
approx	0.4 -> 15815.4
exact	0.6 -> 12228
approx	0.6 -> 12228.2
```

**Last Modification date:** 3 April 2018
