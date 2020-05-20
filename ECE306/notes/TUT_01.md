---
title: 'Tutorial 1<br />'
created: '2019-01-06T17:05:37.028Z'
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

## Question 1

How many different sets of solutions are there for the following equations?

1. $x + y + z = 100$, $x, y, z$ are all integers, and $x > 0, y > 0, z > 0$\
  ANS: $\Co{99}{2}$
2. $a + b + c = 97$, $a, b, c$ are all integers, and $a \ge 0, b \ge 0, c \ge 0$\
  ANS: $\Co{98}{2}$ is incorrect because only $a, b$ can be zero.\
  **SOLUTION 1**\
  Proper Way:
    1. $a > 0, b > 0, c > 0$: $\Co{96}{2}$
    2. one of $a, b, c = 0$: $\Co{3}{1}\times\Co{96}{1}$
    3. 2 of $a, b, c = 0$: $\Co{3}{2}$\
  Sum: $\Co{96}{2} + \Co{3}{1}\times\Co{96}{1} + \Co{3}{2}$\
  
    **SOLUTION 2**\
    97 ones and 2 places = 99 items\
    so permutations: $\frac{99!}{97!2!}$, we divide because there are 2 identical plates, and 97 identical ones\
    
    **SOLUTION 3**\
    $x = a + 1$\
    $y = b + 1$\
    $z = c + 1$\
    $x + y + z = 100 \equiv a + b + c = 97$\
    
    Thus, they have the same answer
3. $N_1 + N_2 + N_3 \dots + N_m = n$, $N_1\ge 0,\;N_2\ge 0,\;\dots N_m\ge 0$\
  ANS: $\Co{n + m - 1}{m - 1}$ 
4. There are $m$ distinct baskets and $n$ identical oranges. 
(Each basket can contain as many baskets as you want - can be empty)
How many different ways are there to put all the oranges into baskets?\
  ANS: $\Co{n + m - 1}{m - 1}$ 
  4. There are $m$ distinct baskets and $n$ **DISTINCT** oranges. 
  (Each basket can contain as many baskets as you want)
  How many different ways are there to put all the oranges into baskets?\
    ANS: $m^n$ 
    
## Question 3 i.e. P21 from HW 1_1
An ant is going from A to B along the edge of the grid.\
Only up and right steps are allowed, how many different paths are allowed?

ANS: $\frac{7!}{3!4!}$

## Question 4, similar to P30 from HW 1_2

9 students are to be seated in a row. Students A, B, C must be seated together, and D, E not together.
How many different arrangements are there?

ANS: \

**SOLUTION 1**\
  1. group A, B, C: $3!5!\Co{6}{2}2!$\
  2. let alone D, E: 5 groups left
  3. 6 intervals, insert D, E
  4. Permutate D, E

**SOLUTION 2**\
  1. D can be E together and group A, B, C: $3!7!$\
  2. subtract the cases where only D, E together: $3!2!6!$
  3. Permutate D, E
  
## Question 5

1. n students are to be seated in a round table. How many arrangements?\
  ANS: $(n - 1)!$

2. Use n different pearls to make necklace. How many different necklaces\
  ANS: $\frac{n!}{n\times 2}$, but if $n = 1, 2$ then ans is $1$\
  because necklaces are mirror images

\
\
\
\
\
\
\
\
  
  
  
  
  
  
  
  
  