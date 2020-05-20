---
title: 'Learn VHDL'
created: '2019-01-19T16:18:00.000Z'
author: 'Aditya Arora'
---
\

## Basics
```VHDL
-- every VHDL file that you write should
-- begin with this line
-- and the next line
library ieee;

-- defines 9 different values for signals
use ieee.std_logic_1164.all;
```

#### 9 different values for signals

| Signal 	| Stands for     	|
|--------	|----------------	|
| 'U'    	| uninitialized  	|
| 'X'    	| strong unknown 	|
| '0'    	| strong 0       	|
| '1'    	| strong 1       	|
| 'Z'    	| high impedance 	|
| 'W'    	| weak unknown   	|
| 'L'    	| weak 0         	|
| 'H'    	| weak 1         	|
| '--'   	| don't care     	|

##### `std_logic` vs `boolean`:
The `std_logic` values `'1'` and `'0'` are not the same as the boolean values true and false.


### Arithmetic
```VHDL
-- defines arithmetic over std_logic vectors
use ieee.numeric_std.all;
```


```VHDL
-- defines arithmetic over bit 
-- vectors and integeres
use ieee.numeric_bit.all;
```

### Entities

- `<=` Signal assignment 
- `:=` Variable assignment
- `=` Equality test

```VHDL
-- entities are used to
-- define the interface to circuit
-- i.e. inputs and outputs
entity and_or is port (
  a, b, c : in std_logic ;
  z : out std_logic 
);
end entity;
```

### Architecture

Architecture is used to define the internal signals and  gates of the circuit i.e. it defines what the circuit's internals are


```VHDL
architecture main of and_or is 
  signal x : std_logic;
begin
  x <= a and b; 
  z <= x or (a and c);
end;
```

#### Concurrent Statements

All statements in an architecture are concurrent i.e. they execute in parallel

All orders of executing concurrent statements must
produce the same waveforms

At each infinitesimally small moment of time, in parallel, every gate:

1. samples its inputs
2. computes the value of its output 
3. drives the output 

##### Conditional Assignment

If-then-else style (uses `when`)

```VHDL
c <= a+b when sel='1' else a+c when sel='0' else "0000";
```

##### Selected Assignment

Case-switch style assignment

```VHDL
with color select d <= "00" when red , "01" when ...;
```

##### Component Instantiation

Use an existing circuit

```VHDL
add1: adder port map (a=>f, b=>g, s=>h, co=>i);
```

#### Generate Statements
note: conditions should be static

- must be able to be evaluated at elaboration
- must not depend upon the value of any signal
- every generate statement must be preceded with a label

##### For-generate

replicate some hardware

```VHDL
bgen: for i in 1 to 7 generate 
        b(i) <= a(7-i); 
      end generate;
```

##### if-generate
Conditionally create some hardware
```VHDL
okgen : if optgoal /= fast then generate 
  result <= ((a and b) or (d and not e)) or g;
end generate;
fastgen : if optgoal = fast then generate
  result <= ’1’;
end generate;
```

### Process

The body of a process is executed sequentially but a process is a concurrent statement

- Processes must have either a sensitivity list (sensitivity list contains the signals that are read in the process) or at least one wait statement on each execution path through the process.
- Processes cannot have both a sensitivity list and a wait statement.
- Within a process, statements are executed almost sequentially 
- Among processes, execution is done in parallel
- Remember: a process is a concurrent statement!

```VHDL
process
begin
  wait until rising_edge(clk); 
  if (a = ’1’) then
    z <= ’1’;
    y <= ’0’; 
  else
    y <= a or b; 
  end if;
end process;
```

#### Sequential Statements

##### `wait`

`wait until rising_edge(clk);`

##### signal assignment
`a <= b`

##### `if-then-else`

```VHDL
if a = '1' then
  b <= c;
elseif a = 'U' then
  b <= d;
end if;
```

##### `case`

```VHDL
case a is 
when '1' => b <= c;
when 'U' => b <= d;
end case;
```

##### `loop`

```VHDL
loop ... end loop;
```

##### `while loop`

```VHDL
while ... loop ... end loop;
```

##### `for loop`

```VHDL
for ... in ... loop ... end loop;
```
##### `next`
The `next` statement is used to prematurely terminate the current iteration of a `while`, `for` or infinite `loop`:

```VHDL
next ...;
```

## Other useful features

- `report` : print a message on stderr while simulating
- `assert` : assertions about behaviour of signals, very useful with report statements. 
- `generics` : parameters to an entity that are defined at elaboration time.
- `attributes`: predefined functions for different datatypes. For example: high and low indices of a vector


## Synthesizable vs Non-Synthesizable Code

For us to consider a VHDL progam synthesizable, all of the conditions below must be satisfied:
- the program must be theoretically implementable in hardware
- the hardware that is produced must be consistent with the structure of the source code
- the source code must be portable across a wide range of synthesis tools, in that the synthesis tools all produce correct hardware

### Wait - For
```VHDL
wait for 10 ns;
```

**Reason**: Delays through circuits are dependent upon both the circuit and its operating environment, particularly supply voltage and temperature.
`

### Initial Values

```VHDL
signal bad_signal : std_logic := ’0’;
```

**Reason**: Values on boot up are completely random 

### Assignments before Wait Statement

If a synthesizable clocked process has a `wait` statement, then the process must begin with a `wait` statement.

```VHDL
process
  c <= a;
  d <= b;
  wait until rising edge(clk); -- should be at the start of the process instead
end process;
```

**Reason**: hardware is unsynth

### "if rising edge" and "wait" in Same Process

```VHDL
process
begin
  if rising_edge(clk) then 
    q0 <= d0;
  end if;
  wait until rising_edge(clk); q0 <= d1;
end process;
```

**Reason**: synthesis tools generally expect just a single type of flop-generating statement in each process.

### "if rising edge" with "else" Clause

```
process (clk)
begin
  if rising_edge(clk) then 
    q0 <= d0;
  else
    q0 <= d1;
  end if;
end process;
```

**Reason**: synthesis tools expect a signal to be either registered or combinational, not both.

### While Loop with Dynamic Condition and Combinational Body

```VHDL
process (a,b,c) 
begin 
  while a = ’1’ loop
    z <= b and c; 
  end loop;
end process;
```

A for-loop with a combinational body is synthesizable, because the loop condition can be evaluated statically (at compile/elaboration time). The loop below is synthesizable:

```VHDL

process ( b, c ) begin
  for i in 0 to 3 loop
    z(i) <= b(i) and c(i); end loop;
end process;
```

While loops with dynamic conditions and clocked bodies are synthesizable, but are an example of an implicit state machine and are an advanced topic.

## Undesirable hardware features

Our list of undesirable hardware features is: 

#### Latches

- Latch: Combinational if-then without else
- Signals Missing from Sensitivity List
  - A synthesis tool that adheres to the standard will either generate an error or will
create hardware with latches or flops clocked by data sigansl if not all signals that are read
from are included in the sensitivity list.\
  **exception** In a clocked process using an if rising edge, it is acceptable to have only the
clock in the sensitivity list

#### Combinational loops
  - **note** Registered loops are fine.

#### Multiple drivers for a signal

  - **reason** This can cause contention, tri-state values, and other bad things

#### Asynchronous resets

- **reason**  If a reset occurs very close to a clock edge, some parts of the circuit might be reset in
one clock cycle and some in the subsequent clock cycle, which can cause the circuit to go out of sync

#### Using a data signal as a clock 

- **reason** All data assignments should be synchronized to a clock. This ensures that the timing
analysis tool can determine the maximum clock speed accurately.

#### Using a clock signal as data

- **reason** Clock signals have two defined values in a clock cycle and transition in the middle of
the clock cycle. At the register-transfer level, each signal has exactly one value in a clock cycle and signals transition between values only at the boundary between clock cycles.



