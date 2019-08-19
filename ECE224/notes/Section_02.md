---
title: 'Section 2 - Embedded Systems<br />'
created: '2019-05-19T03:11:40.921Z'
modified: '2019-05-19T03:11:45.921Z'
author: 'Aditya Arora'
tags: [Notebooks/ECE224]
---

<!-- TODO: Definitions? If yes, to what level of completeness? Paraphrasing?
  - terms like Microcontrollers, SOPC, SOC
I can describe them better than define them
-->
### Embedded System
A special-purpose computer system designed to perform a task without the user’s knowledge of its existence. The user may provide input to the embedded system via controls and sensors but the user need not be aware of the presence of the embedded system. Applications include consumer electronics, household appliances, automotive and telecommunications devices

### Hardware / Software Codesign
Hardware/software codesign is the term given to the task of simultaneously designing hardware and software components of a combined hardware/software system.

### Definitions
- *Hardware*: 3. the mechanical or electronic components of a computer, etc.
- *Software*: 1. the programs or other operating information used by a computer. 2. storage media such as video cassettes, audio tapes, etc. requiring playback on electronic equipment

### Microprocessors
A microprocessor (eg:Intel Core i9) consists of a processor only (no main memory and no built-in support for input / output devices). The microprocessor term commonly refers to a general-purpose Central Processing Unit (CPU):

- deliver high performance
- the CPU may include more than one processor core
- suitable for all types of computations
- require off-chip memory and input / output devices to implement a complete computer

### Micro-controller
A complete computer on a single chip (eg:Intel Quark D2000) consisting of a processor, memory and some input / output devices. These devices are usually specified in a fairly general manner to permit reuse of the same micro-controller component in many applications. <br> This term commonly refers to a Central Processing Unit (CPU) that has been specialized to control the operation of a mechanical or electronic system:

- Small and cost-effective
- Built-in storage
- Specialized built-in interface support for some of the following:
  - High-speed communication
  - Parallel devices
  - Serial devices
  - Analog devices

### System-on-a-Chip (SoC)
A user-designed fully-functional system implemented on a single chip. This may include processing, memory, input / output devices and other digital logic. A SoC can be used to implement an embedded system or a part of it.

- Typically, a System-on-a-Chip (SoC) incorporates the following hardware components (depending on the application):
  - Functionality similar to the microprocessor or a micro-controller defined previously. The implementation may be as either hardware or software.
  - Communication port(s)
  - Storage:
    - Volatile storage (e.g., Random Access Memory $\implies$ RAM )
    - Non-volatile storage (e.g., Read-Only Memory $\implies$ ROM )
  - Other components could include: timers, parallel interfaces, analog to digital converters and pulse width modulators.

### Programmable Logic Device
A digital logic chip that permits configuration and interconnection of internal logic blocks. Often this term refers to a computer chip that can be “rewired” to implement a custom digital circuit using primitive building blocks.

- Several types of PLD technologies exist:
    - SRAM (Static Random Access Memory)
    - EEPROM (Electronically-Erasable Programmable Read-Only Memory)
    - NOR Flash
    - Antifuse
- Primitive building blocks include flip-flops, multiplexers, lookup tables (LUTs), adders, multipliers, and RAM blocks.
- Not all PLDs are created equally:
    - In-system programmability vs. external programming hardware
    - One-time programmable vs. reconfigurable

### System-on-a-Programmable-Chip (SoPC)
A System-on-a-Programmable Chip is an SoC that is implemented using a high-density, reconfigurable PLD.

- *Advantages wrt SOC*:
    1. Flexible
    2. Upgradable
- *Disadvantages wrt SOC*:
    1. Potentially slower
    2. More expensive
