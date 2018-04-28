---
title: Implicit Euler
math: true
layout: default
---

{% include mathjax.html %}

<a href="https://philipnelson5.github.io/MATH5620/SoftwareManual"> Table of Contents </a>
# Implicit Euler Method

**Routine Name:** `implicit_euler`

**Author:** Philip Nelson

**Language:** C++

## Description

`implicit_euler`, also known as the backward Euler method, is one of the most basic numerical methods for the solution of ordinary differential equations. It is similar to the (standard) Euler method, but differs in that it is an implicit method. The backward Euler method has order one in time. [1](https://en.wikipedia.org/wiki/Backward_Euler_method)

## Input

`implicit_euler(T x0, T y0, T x, T dt, F f)` requires:

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
T implicit_euler(T x0, T y0, T x, T dt, F f)
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
    implicit_euler(0.0, -1.0, 0.4, 0.1, [](double a, double b){return a*a+2*b;})
    << std::endl;
}
{% endhighlight %}

## Result
```
-2.05836
```

**Last Modification date:** 3 April 2018
