---
title: 'Final<br />'
author: 'Aditya Arora'
tags: [Notebooks/ECE224]
header-includes: |
  \usepackage{mathtools}
---

## Prof Bishop's notes

5 questions - past exam average 60%\
EACH QUESTION IS WORTH 20%

1. Serial Interfacing
    - refer to midterms for more information
    - dumb errors on calculations
2. Analog Interfacing
    - sometimes people forget things, and people forget things
    - some things can be hard eg: dual slope
3. Buses - Data Transfer
    - gets people, positioning of edges gets people
    - lots of precision required
4. Buses - Arbitration
    - not going to be detailed question on 4 wire
    - or non daisy chain
    - **people do well here** - 70% average
5. Design
    - often things can be answered 2 different ways
      - often a lot of things as long as you give context
    - statistically speaking is not the hardest exam


The word DMA controller appears on the exam, but its in the DESIGN question.\

First 3 pages of the exam are going to be on the exam, which will show you the breakdown of each of the parts\
Its safe to assume, that there is going to both software and hardware, it may be given or asked.\
**Number of pages:** Physically 24 sides, last page is blank, first 3 sides are front matter. 20 PAGES NET\

**Could the labs show up:** Never anything specific about the NIOS system show it. Lab like content COULD show up ("yeah sure")\

**Difficult to previous exam**: No more difficult than the previous exam, is it easier, probably not

Average is going to be between: $65-70\%$\

**Course averages to about** 80% \
**IDEAL** THERE ARE SOME CASES WHERE WE WOULD ASK FOR IDEAL EDGES ESPECIALLY IN ARBITRATION\
BUT DATA TRANSFER COULD ASK FOR NON IDEAL EDGES

---

- Even parity is XOR
- Binary ramp biases high - increase voltage until greater
- Successive approximation biases low - find greatest non-exceeding voltage
- Clock for Binary ramp ADC should not exceed the settling of the internal DAC
- $t_{aperture} = \frac{\text{max change in }V}{\text{sampling rate}}$


Help Session:

1. What's the case for a start bit error: Line goes down for less than a complete cycle
