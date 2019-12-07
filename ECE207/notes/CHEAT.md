---
title: 'Cheat Sheet'
author: 'Aditya Arora'
tags: [Notebooks/ECE207]
header-includes: |
  \usepackage{mathtools}
---

## Time Domain Analysis

### Impulse

$$\delta[k] := \begin{cases}
1, \; k = 0\\
0, \; \text{otherwise}
\end{cases}
$$

$$\sum_{n=-\infty}^{\infty}\delta[n] = 1$$

**Sifting formula**: $$x[k] = \sum_{n=-\infty}^{\infty}x[n]\delta[k-n] = \sum_{n=-\infty}^{\infty}x[k-n]\delta[n]$$

For impulse response $h[k]$ (response for input $\delta[k]$), its response to any $x[k]$ is
$$y[k] = \sum_{n=-\infty}^{\infty}x[n]h[k-n] = \sum_{n=-\infty}^{\infty}x[k-n]h[n]$$

Convolution: $$(x\ast y )[k] = \sum_{n=-\infty}^{\infty}x[n]y[k-
n]$$
Properties:

1. Commutative
2. Associative
3. Distributive

An LTI system with impulse response $h[k]$ is causal iff
$$h[k] = 0 \; \forall\; k < 0$$
