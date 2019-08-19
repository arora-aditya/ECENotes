---
title: 'NFA DFA'
author: 'Aditya Arora'
tags: [Notebooks/208]
---

## Deterministic Finite Automaton (DFA)
They accept a finite string as input, and output "Accept" or "Reject"

#### Formal Definition
$$M = (Q, \Sigma, \delta, q_0, F)$$

$Q$ : set of states\
$\Sigma$ : input alphabet  $\;\;\lambda \not\epsilon\; \Sigma$\
$\delta$ : transition function\
$q_0$ : initial state\
$F$ : set of accepting states\

## Transition Function
$$\delta(q_0 , x) = q'$$
Describes the result of a transition from state $q$ with symbol $x$

### Extended Transition Function
$$\delta^\ast: Q\times \Sigma^\ast \rightarrow Q$$
$$\delta^\ast(q,w) = q'$$

Describes the resulting state after scanning string $w$ from state $q$

#### Special Case

For any state $q$
$$q^\ast(q, \lambda) = q$$

In general $q^\ast$ implies that there is a walk of transitions where states may repeat

## Transition Table

Table of all transitions, with the following format

| $\delta$ | $a$ | $b$ |
|----------|-------|-------|
| $q_0$ | $q_1$ | $q_0$ |
| $q_1$ | $q_2$ | $q_0$ |

All the symbols are shown at the top, while all the states are shown on the left.

## Language Accepted
Language accepted by DFA $M$ are denoted as $L(M)$ and contains all the strings accepted by $M$\
We also say that $M$ recognizes $L(M)$

## Regular Languages
A language $L$ is regular if there is a DFA $M$ that accepts it ($L(M)=L$)

The languages accepted by all DFAs form the family of regular languages

### Properties of Regular Languages

For regular languages $L_1$ and $L_2$, the results of these functions are all regular OR Regular languages are closed under:

Union: $L_1 \cup L_2$\
Intersection: $L_1 \cap L_2$\
Concatenation: $L_1 L_2$\
Star: $L_1^\ast$\
Reversal: $L_1^R$\
Complement: $\overline{L_1}$

## Regular Expressions
Regular expressions describe regular languages

### Recursive Definition
Primitive Regular Expressions: $\Phi, \lambda, \alpha$

Given regular expressions $r_1$ and $r_2$, the results of these functions are all regular expression

$r_1+r_2$\
$r_1\cdot r_2$\
$r_1^\ast$\
$(r_1)$\

### Languages of Regular Expressions
$L(r)$: language of regular expression $r$

#### For primitive regular expressions:
$$L(\Phi) = \Phi$$
$$L(\lambda) = \{\lambda\}$$
$$L(a) = \{a\}$$

For regular expressions $r_1$ and $r_2$
$$L(r_1+r_2) = L(r_1)\cup L(r_2)$$
$$L(r_1\cdot r_2) = L(r_1)L(r_2)$$
$$L(r_1^\ast) = (L(r_1))^\ast$$
$$L((r_1)) = L(r_1)$$

### Equivalent Regular Expressions
Regular expressions $r_1$ and $r_2$ are equivalent if $L(r_1)=L(r_2)$

## Non Deterministic Finite Automaton (DFA)
An NFA accepts a string: if there is a computation of the NFA that accepts the string\
i.e., all the input string is processed and the automaton is in an accepting state\

An NFA rejects a string:
if there is no computation of the NFA that accepts the string.
For each computation:

- All the input is consumed and the automaton is in a non final state\
  **OR**
- The input cannot be consumed

### Formal Definition
$$M = (Q, \Sigma, \delta, q_0, F)$$

$Q$ : set of states\
$\Sigma$ : input alphabet  $\;\;\lambda \not\epsilon\; \Sigma$\
$\delta$ : transition function\

1. transition to multiple states on the same letter
2. transition on empty string

$q_0$ : initial state\
$F$ : set of accepting states\

An NFA's transition function can lead to multiple states or no states.

The language accepted by an NFA then changes to one where, once you've processed the entire string, you get a set of states, and there exists at least one accepting state in that set/
