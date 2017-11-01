#gdb:

### list:
List specified function or line.
With no argument, lists ten more lines after or around previous listing.
"list -" lists the ten lines before a previous ten-line listing.
shortform l;

### run:
just runs the program; shortform r;

### break 7:
break at line 7; creates a break point; shortform: b;

### step:
Step program until it reaches a different source line; shortform: s;

### print:
Print value of expression EXP. Variables accessible are those of the lexical environment of the selected
stack frame, plus all those whose scope is global or an entire file.
$NUM gets previous value number NUM.  $ and $$ are the last two values.
$$NUM refers to NUM'th value back from the last one.
Names starting with $ refer to registers (with the values they would have
if the program were to return to the stack frame now selected, restoring
all registers saved by frames farther in) or else to debugger
"convenience" variables (any such name not a known register).
Use assignment expressions to give values to convenience variables.
shortform p;

### where
Print backtrace of all stack frames

###watch
A watchpoint stops execution of your program whenever the value of
an expression changes.
If -l or -location is given, this evaluates EXPRESSION and watches
the memory to which it refers.
