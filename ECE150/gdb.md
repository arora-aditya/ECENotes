## GDB (Command Line Debugger)

**GDB commands**

`gdb <args to gdb> program`

- `run <args to prog> < infile > outfile` / `r`
    - Run the program 
    - shortform r
- `backtrace` / `bt`
    - Stack trace
    - similar to where
- `print <any C expression` / `p`
    - Print the value of expression
    - Print value of expression EXP. Variables accessible are those of the lexical environment of the selected
      stack frame, plus all those whose scope is global or an entire file.
      $NUM gets previous value number NUM.  $ and $$ are the last two values.
      $$NUM refers to NUM'th value back from the last one.
      Names starting with $ refer to registers (with the values they would have
      if the program were to return to the stack frame now selected, restoring
      all registers saved by frames farther in) or else to debugger
      "convenience" variables (any such name not a known register).
      Use assignment expressions to give values to convenience variables.
- `up`
    - Goes to the next function in the stack trace
- `down`
    - Goes the opposite direction of up
- `break <function name OR file:line>` / `b`
    - Pause everytime we reach the breakpoint
- `continue` / `c`
    - Start running again
- `next` / `n` 
    - Move forward one line
- `step` / `s`
    - Move forward one line and step into function calls
- `watch`
    - A watchpoint stops execution of your program whenever the value of
      an expression changes.
    - If -l or -location is given, this evaluates EXPRESSION and watches
      the memory to which it refers.
- `list` / `l`
    - List specified function or line.
    - With no argument, lists ten more lines after or around previous listing.
    - "list -" lists the ten lines before a previous ten-line listing
