---
title: 'Midterm<br />'
created: '2019-05-18T21:57:37.028Z'
modified: '2019-05-18T22:20:55.054Z'
author: 'Aditya Arora'
tags: [Notebooks/208]
---
## Definitions

### Predicate Logic
**Logic**: A precise language, with clear syntax and well-defined semantics, for mathematics and computation\
**Interpretation**: An interpretation $I$ for a formula $F$ in propositional logic is a mapping from each propositional variables in $F$ to exactly one truth value\
$I \models F$ if $F$ evaluates to $\top$ under $I$\
$I \not\models F$ if $F$ evaluates to $\bot$ under $I$\

**Soundness**: We say a proof system $P$ is sound for logic (or theory) $L$, if whenever $P$ returns  "theorem" for any $L$-formula $F$, then $F$ is indeed valid.\
**Completeness**: We say a proof system $P$ is complete for logic (or theory) $L$, if for any valid $L$-formula $F$, $P$ returns "theorem".\
**Termination**: We say a proof system $P$ is terminating, if for any $L$-formula $F$ (valid or otherwise), $P$ returns after finite number of steps.\
**Equisatsfiability**: We say two formulas $P$ and $Q$ are equisatisfiable if $P$ is satisfiable iff $Q$ is also satisfiable. This notion is much weaker than logical equivalence. I.e., if $P$ and $Q$ are logically equivalent, then it implies that they are equisatisfiable. However, the converse does not always hold.\
**Normal Forms**

1. Negation Normal Form: $\neg, \lor, \land$ and $\neg$ only appear in literals
2. Disjunctive Normal Form: $\lor_i \land_j l_{i,j} \text{ for literals } l_{i,j}$ and $\neg$ only appear in literals
3. Conjunctive Normal Form: $\land_i \lor_j l_{i,j} \text{ for literals } l_{i,j}$ and $\neg$ only appear in literals

**Tseitin**’s transformation converts formula $F$ to equisatisfiable formula $F'$ in CNF with only a linear increase in size (upper bound $30n+2$).\

### First Order
**Object constants** refer to objects in a universe of discourse\
**Function constants** refer to functions, and **arity** refers to the number of arguments each of them takes\
**Relation constants** refer to relations between or properties of objects\
A set of object, function, and relation constants $C, F, R$ specifies a *first-order language*, written $L(C,F,R)$ and $C , F , R$ form the signature of the language.\
**Structure** A structure $S = \langle U , I \rangle$ for a first order language consists of a universe of discourse of $U$ and an interpretation $I$\
**Assignment**: A variable assignment $\sigma$ (or assignment) to a FOL formula $\varphi$ in a structure
$S = \langle U , I \rangle$ is a mapping from variables in $\varphi$ to an element of $U$.\
**Satisfiable**: An FOL formula $F$ is said to be satisfiable if there exists a structure $S$ and an assignment $\sigma$ such that $S, \sigma \models F$.\
**Valid**: An FOL formula $F$ is said to be valid, written as $\models F$ if for all structures $S$ and all variable assignments $\sigma$, we have $S, \sigma \models F$.\
A formula with no free variables is called a **closed** formula.\
A **closed** formula is also called a sentence.\
A formula containing free variables is said to be **open**.\
A formula is said to be **ground** if it contains no variables.\

### Second Order?
**Second Order**: The "pair" makes it second order\
_Every pair of friends has something in common_ $\equiv$ $\forall x , y .friend (x , y ) \implies \exists p .p (x ) \land p (y )$
\
\
\

\
\
$F$ is **satisfiable** iff there exists an interpretation I such that $I \models F$\
$F$ **valid** iff for all interpretations $I$ , $I \models F$\
$F$ is **contingent** if it is satisfiable but not valid\
$F$ is **valid** iff $\neg F$ is **unsatisfiable**\



Proof systems are defined as a collection of proof rules, take as input formulas and determine whether they are theorem.
