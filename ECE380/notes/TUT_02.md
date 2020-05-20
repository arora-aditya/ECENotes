---
title: 'Tutorial 2 - Problem Set 1<br />'
created: '2020-01-16T08:30:00.000Z'
author: 'Aditya Arora'
---
\newcommand{\N}{\mathbb{N}}
\newcommand{\Z}{\mathbb{Z}}
\newcommand{\C}{\mathbb{C}}
\newcommand{\R}{\mathbb{R}}
\newcommand{\iu}{{j\mkern1mu}}
\newcommand{\F}{\mathcal{F} }
\newcommand{\La}{\mathcal{L} }
\newcommand{\pd}{\partial }
\newcommand*{\ddo}[2]{\frac{d{#1}}{d{#2}}}
\newcommand*{\dt}[2]{\frac{d^2{#1}}{d{#2}^2}}
\newcommand*{\pdo}[2]{\frac{\pd{#1}}{\pd{#2}}}
\newcommand*{\pdt}[2]{\frac{\pd^2{#1}}{\pd{#2}^2}}
\newcommand*{\Co}[2]{\{#1\}\choose\{#2\}}
\newcommand*{\nbt}{\nabla^2}

## Problem 3

Room Temp Model

$$\begin{aligned}
\ddo{v}{t}(t) &= -3y(t) + u(t) & \\
u(t) &= K_p(r(t) - y(t))
\end{aligned}
$$

Question: For a given $r(t) = r_0$,  is there a $K_p \epsilon \R$ so that $y(t) \to r_0$ as $t \to \infty$


Assuming $r(t) = r_0 I(t)$,

$$
\begin{aligned}
\ddo{y}{t}(t) &= -(3 + K_p)y(t) + K_pr_0I(t)\\
(s + 3 + K_p)Y(s) &= \frac{1}{s}K_pr_0 + y(0)\\
Y(s) &= \frac{K_pr_0}{(s)(s+3+K_p)} + \frac{y(0)}{s + 3 + K_p}
\end{aligned}
$$  


Assuming $\lim_{t\to\infty}y(t)$ exists, then:

$$
\begin{aligned}
\lim_{t \to \infty}y(t) &= \lim_{s \to 0} sY(s)\\
&= lim_{s \to 0} [\frac{K_pr_0}{s + 3 + K_p} + \frac{s}{s + 3 + K_p}y(0)]\\
&= \frac{K_pr_0}{3 + K_p}\\
&= \frac{K_p}{3 + K_p}r_0
\end{aligned}
$$

Thus there is no solution

## Problem 6

![problem 6](../../attachments/tut_02_p6.png)

![problem 6 fbd](../../attachments/tut_02_p6_fbd.png)

$$
\begin{aligned}
M_1q_1'' &= -bq_1' + bq_2' + u(t)\\
M_2q_2'' &= bq_1' - bq_2'
\end{aligned}
$$

## Problem 10
![problem 10](../../attachments/tut_01_p10.png)

From similar triangles we know: 

$$\frac{r(t)}{h(t)} = \frac{1}{4}$$

and volume of a cone is:
$$\begin{aligned}
V(t) &= \frac{1}{3}\pi r(t)^2h(t)\\
\implies V(t) &= \frac{1}{48}\pi(h(t))^3\\
\end{aligned}$$

We know
$$\begin{aligned}
V(t)' &= f_i(t) - f_o(t)\\
\implies \frac{1}{16}\pi(h(t))^2h(t)' &= f_i(t) - f_o(t)\\
\implies \frac{1}{16}\pi(h(t))^2h(t)' &= - \sqrt{(3h(t))} + f_i(t)
\end{aligned}$$

## Problem 8

![problem 8](../../attachments/tut_02_p8.png)

![fbd](../../attachments/tut_02_p8_fbd.png)


Newton's Law for a rotating body

$$
\begin{aligned}
I\theta'' &= \sum \tau &\\
I_b &= M_b\frac{l^2}{12} &\\
I_m &= M_l\frac{l^2}{4} & \text{ (Assuming that the box is a point mass)}\\
I_t &= I_b + I_m\\
\sum \tau &= f(t)cos(\theta)\frac{l}{2} - Mgcos(\theta)\frac{l}{2}\\
\implies f(t)cos(\theta(t))\frac{l}{2} - Mgcos(\theta(t))\frac{l}{2} &= (I_b + I_m)\theta''
\end{aligned}
$$


![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)
![](../../attachments/.png)

