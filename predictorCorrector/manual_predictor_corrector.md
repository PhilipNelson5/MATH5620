---
title: Predictor Corrector
math: true
layout: default
---

{% include mathjax.html %}

<a href="https://philipnelson5.github.io/MATH5620/SoftwareManual"> Table of Contents </a>
# Predictor Corrector

**Routine Name:** `predictor_corrector`

**Author:** Philip Nelson

**Language:** C++

## Description

`predictor_corrector` belong to a class of algorithms designed to integrate ordinary differential equations – to find an unknown function that satisfies a given differential equation. All such algorithms proceed in two steps:

1. The initial, "prediction" step, starts from a function fitted to the function-values and derivative-values at a preceding set of points to extrapolate ("anticipate") this function's value at a subsequent, new point.

2. The next, "corrector" step refines the initial approximation by using the predicted value of the function and another method to interpolate that unknown function's value at the same subsequent point.
[1](https://en.wikipedia.org/wiki/Predictor–corrector_method)

Three families of linear multistep methods are commonly used: Adams–Bashforth methods, Adams–Moulton methods, and the backward differentiation formulas (BDFs).

The Adams–Bashforth methods are explicit methods. The coefficients are \\(a_{s-1}=-1\\) and \\(a_{s-2}=\cdots =a_0=0\\), while the \\(b_j\\) are chosen such that the methods has order s (this determines the methods uniquely).

The Adams–Moulton methods are similar to the Adams–Bashforth methods in that they also have \\(a_{s-1}=-1 and \\(a_{s-2}=\cdots =a_0=0\\). Again the b coefficients are chosen to obtain the highest order possible. However, the Adams–Moulton methods are implicit methods. By removing the restriction that \\(b_s = 0\\) , an s-step Adams–Moulton method can reach order s+1, while an s-step Adams–Bashforth methods has only order s.

[1](https://en.wikipedia.org/wiki/Linear_multistep_method)

## Input

`predictor_corrector(T x0, T y0, T x, T dt, F f)` requires:

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
T predictor_corrector(T x0, T y0, T x, T dt, F f)
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
    predictor_corrector(0.0, -1.0, 0.4, 0.1, [](double a, double b){return a*a+2*b;})
    << std::endl;
}
{% endhighlight %}

## Result
```
-2.05836
```

**Last Modification date:** 3 April 2018
