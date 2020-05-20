---
title: 'Midterm Prep<br />'
created: '2020-02-17T14:25:37.028Z'
author: 'Aditya Arora'
---

\newcommand{\N}{\mathbb{N}}
\newcommand{\Z}{\mathbb{Z}}
\newcommand{\C}{\mathbb{C}}
\newcommand{\R}{\mathbb{R}}
\newcommand{\iu}{{j\mkern1mu}}
\newcommand{\F}{\mathcal{F} }
\newcommand{\La}{\mathcal{L} }
\newcommand{\Lap}[1]{\mathcal{L}\Big\{#1\Big\} }
\newcommand{\pd}{\partial }
\newcommand*{\ddo}[2]{\frac{d{#1}}{d{#2}}}
\newcommand*{\dt}[2]{\frac{d^2{#1}}{d{#2}^2}}
\newcommand*{\pdo}[2]{\frac{\pd{#1}}{\pd{#2}}}
\newcommand*{\pdt}[2]{\frac{\pd^2{#1}}{\pd{#2}^2}}
\newcommand*{\Co}[2]{\{#1\}\choose\{#2\}}
\newcommand*{\nbt}{\nabla^2}


## Laplace

### Final Value Theorem
$$
\lim_{s\to 0}sY(s) = \lim_{t\to \infty}y(t)
$$

### Laplace of Differentials

$$
\Lap{\dt{y}{t}} = s^2Y(s) - sy'(0^-)- y''(0^-)
$$

### $e^{At}$ converges

if all roots have negative real parts 


## 2nd Order

### Poles
$$s = -\zeta \omega_n \pm \omega_n \sqrt{\zeta^2 - 1} = \omega_n\left(-\zeta \pm \sqrt{\zeta^2 - 1}\right)$$

### Settling time for Critically damped system

$$
T_s \approx \frac{5.8}{\omega_n}
$$

### Frequency of second order system
The frequency of the oscillatory response equals the imaginary part of the complex conjugate poles in the tranfer function
$$
\omega_n \sqrt{(1 - \zeta^2)} = \frac{2\pi}{T_{pp}} = f_{oscillation}
$$

### Region of convergence
$$
\{s\; \epsilon\; \C : Re (s) > a\}
$$

where $a$ is the real part of the rightmost pole


### BIBO stable



## Summary

Course is about classical control; most prevalent, assumes linear and time invariant plant

- it requires that we have a transfer function

- when you use feedback, you need to consider the possibility of a system not converging


##### Chapter 1 review

- Complex Numbers
  - Euler's Identity: $e^{j\theta} = \cos(\theta) + j\sin(\theta)$ gives us a way to think about complex numbers in terms of angles
  - Polar form makes it easy to multiply/divide: $|z| = ℝ$ and $arg(z) = \theta$
    - arg is the principle argument (angle when in polar form)
  - Complex conjugate, $\bar{z}$ of the denominator for turning division into multiplication
    - $z\bar{z} = |z|^2$

Block Diagrams are the basis of control engineering. Each block represents a function (not like free body diagrams)

Review of Equations:

- Newton's equations are useful for mechanical/physical systems
  - translation and rotation
  - rotational inertia formula: $\tau = I a$, I = moment of inertia

- Hooke's Law says restoring force from stretch is linearly proportional to the amount stretched 
- for circuit systems, there KVL and KCL
  - $v = L \frac{di}{dt}$ for inductors
  - $i = C \frac{dv}{dt}$ for capacitors

- eigenvectors are vectors whose directions do not change after having a matrix (as a linear mapping) applied to them 

##### Chapter 2 Modelling
**State-space models** are mathematical expressions of systems

- state variables (a vector called `x`) are the full set of variables that dictate change in a system

- we have a vector of inputs `u`

- composed of state equation + output equation
  - $\dot{x} = f(x, u) = Ax + Bu$
    - another equivalent way to write this is as a vector of functions
  - $y = h(x) = Cx + Du$

One key property of linearity is the **superposition principle**: the net responses caused by multiple stimuli is the sum of the responses caused by each stimuli individually

**Linearization** is approximating a nonlinear system, by looking at the system's behaviour near an equilibrium configuration (physical state is at rest). We then calculate the four jacobians, A, B, C and D.

**Transfer functions** exist only for LTI systems, and are expressed in the frequency domain. They tell us how the system responds at different frequencies (which is only possible because we assume time invarance and so the response does not depend on the current time)

- to find the TF from state space, $\frac{Y(s)}{U(s)} = C(sI - A)^{-1}B + D$
- $\frac{X(s)}{U(s)} = (sI - A)^{-1}B$
- we only look at one sided laplace transforms here (Re(s) > 0)
- the region of convergence is always in the open right half plane

##### Chapter 3 Linear System Theory

- matrix exponential describes how we can raise scalars to the the exponent of a matrix, generalizing the taylor series expansion of $e^t$
  - it is a requirement in order for a time domain response calculation to work out

- there are tricks to finding eigenvalues by inspection, which may prove useful in the exam

- $\dot{x} = Ax, x(0)=x_0$ has the unique solution $x(t) = e^{At}x_0$
  - we also get that $e^{At} = L^{-1}\{(sI - A)^{-1}\}$
- we are given a full solution in the time domain for a state equation and an initial value (equation 3.5), but are only used through simulation

**Stability**

- **asymptotic stability** is when state x goes to zero as t approaches infinity forall initial conditions x(0), or the matrix exponential $e^{At} \rightarrow 0$ as $t \rightarrow \inf$
  - it actually only depends on eigenvalues: if all eigenvalues of A have a negative real part

- **bounded input** is when $u(t) \leq b$ forall t, b is finite

- **BIBO stable** if BI => BO
  - for strictly proper rational transfer functions, BIBO stable iff every pole has negative real value iff the integral of the impulse response is finite, iff the integral of the impulse response over 0 to infinity is finite
  - if G(s) is improper, G(s) is not BIBO stable
  - recall that in the time domain, we can use convolution to calculate response in time domain of applying a transfer function to some input
  - a sinusoidal input to a BIBO function produces a sinusoidal output
  - the integral $\int_0^\infty |g(t)| dt$ where $g(t)$ is the impulse response, upper bounds the gain of a BIBO stable system.

- **final value theorem** gives us that **stead-state gain** ratio is reached when a non-varying input is given, and further says that the magnitude of the input does not affect the ratio
  - 4 cases
  - all poles Re < 0 implies f(t) -> 0
  - one pole at 0 => $\lim_{t \rightarrow \inf} f(t) = \lim_{s \rightarrow 0} sF(s)$, r
  - multiple poles at 0 => diverges
  - any poles with Re > 0 => diverges

- the **steady-state gain** is G(0)
- the **frequency response** is $G(j\omega)$, used for determining the steady state output given a sinusoidal input (see Theorem 3.7.1)
  - when input $u(t) = cos(\omega t)$ $$y_ss = |G(\iu \omega)|cos(\omega t + \angle (G(\iu \omega)))$$

For sketching bode plots, the magnitude plot is on a scale of dB, so $20 \log|G(s)|$ for transfer function G(s). The phase plot is on a scale of degrees. The x axis is on a logarithmic scale. The sketch is called an asymptotic bode plot. We use straight line approximations to draw the plot.
- for magnitude, taking the log of a fractional expression allows us to rewrite it as a sum of logs (with negatives for denominator terms)
- use zeroes and poles to determine where the plot changes, and its coefficient is the slope of the linear approximation

- bandwidth of the transfer function can be determined by calculating at what frequency (x-axis) the dB drops by 3 from it's initial value
  - $20 log|G(s)| = K-3$, for some gain of $K$ *(K might be the wrong variable to use here)*

##### Chapter 4 Prototypes
**Prototype first order system** equation lets us compare transfer functions to a parametric form, allowing us to easily derive properties: everything depends on time constant $\tau$

- $G(s) = \frac{K}{\tau s + 1}$
- pole at $s = -\tau$, bandwidth = $\frac{1}{\tau}$, non oscillatory, gain of K, settling time of $4\tau$

Prototype second order system is $G(s) = \frac{K \omega_n}{s^2 + 2 \zeta \omega_n s + \omega_n^2}$

- introduces concept of damping ratio, which dictates its response graph and whether it is oscillatory or not

##### Chapter 5 Feedback control theory

We get:

$\underbrace{\begin{bmatrix}\dot{x_p}\\\dot{x_c}\end{bmatrix}}_{x_{cl}} = \underbrace{\begin{bmatrix}A_p-B_pD_cC_p&B_pC_c\\-B_cC_p&A_c\end{bmatrix}}_{A_{cl}}\begin{bmatrix}X_p\\x_c\end{bmatrix}$

The closed-loop system is internally stable if $\dot{x_{cl}}=A_{cl}x_{cl}$ is asymptotically stable.


analyzing existing controllers

In lab 2, we looked at a second order circuit system.

- we can have second order LTI systems, it just means that the output signal depends on the input y(t) and both the first and second derivative of y(t)
- feeding the output back as input (closing the loop) decreases steady state gain of the system and damping ratio, and increases the bandwidth frequency and natural frequency

- closed-loop systems can handle disturbance signals while open-loop cannot

Pole-zero cancellation is if some pole in either the controller C or plant P gets cancelled by the numerator 

- unstable if Re($\lambda \geq 0$), implying that the feedback system isn't I.O. stable (root always shows up in the characteristic polynomial since $\pi(\lambda) = N_pN_c + D_pD_c = 0 + 0 = 0$) 
  - by contrapositive, we know that unstable pole-zero cancellation implies no internally stable
  - **it's the naive thing to do, it doesn't work**
- roots of $\pi(s) \subseteq$ eigenvalues of $A_{closed}$
  - **internal stability** is achieved when the state model for $\dot{x}_{cl} = A_{cl}x_{cl}$ is asymptotically stable
<img height=50 src="img/52Acl.png"/>
- **IO Stable** if all combinations of transfer functions are BIBO stable
  - if some coefficient of the char poly is non-positive, it is not hurwitz => not IO stable

- internal stability => I.O. stability

- $\pi(s)$ is **Hurwitz** if all roots have Re(s) < 0
  - Routh-Hurwitz criterion is an algebraic test for the characteristic polynomial to be Hurwitz, for the purpose of checking stability without finding its roots
  - if all real roots have negative real value, then all coefficients of the polynomial must be positive
  - for complex conjugate roots, expanding (and intuitively) we know that each multiplied together will be a quadratic with all positive coefficients

- hurwitz huristic tells us quickly whether its not hurwitz (check all coefficients for positivity)
- routh-hurwitz is stronger, follow table algorithm with a figure-8 pattern drawing and terminate if any first column value is zero
  - the array is the leftmost column, we know the number of roots in the right-half plane by the number of sign switches

- characteristic polynomial is hurwitz iff all elements in 1st column have same sign
  - if no zeroes in first column, # of sign changes = # of bad roots
