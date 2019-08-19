---
title: 'Periodic Inputs and Fourier Series'
author: 'Aditya Arora'
tags: [Notebooks/ECE207]
header-includes: |
  \usepackage{mathtools}
---
There are applications such as modulation and demodulation of radio signal, where we are interested in the response of the system
$$
\begin{cases}
      Q(D)y(t) = P(D)x(t) \\
      y(-\infty) = 0,\dots, y^{n-1}(-\infty) = 0
\end{cases}
$$
to periodic inputs i.e. there exists $\tau$ such that:
$$x(t+\tau) = x(t)\;\; \forall\;t\;\epsilon\;\mathbb{R}$$

In such applications the transients are irrelevant or insignificant, so we do not impose $x(t) = 0\;\;\forall\; t < 0$, or specify initial conditions at $t = 0$ or specify initial conditions at $t=0$. As we saw in Chapter 3, the steady-state response of an LTI system to a sinusoidal input is easily characterized. We will use the Fourier
