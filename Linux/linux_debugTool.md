### what are the other gdb tools to debug your code in linux

In addition to the core GDB tool, there are several other tools and utilities that can be used to debug code in Linux. Some of these tools complement GDB and provide additional capabilities for debugging and analyzing programs. Here are a few notable ones:

### Valgrind:

Valgrind is a powerful tool for 
- memory debugging, 
- memory leak detection, 
- and profiling. 

It can detect memory errors such as 
- invalid memory access, 
- use of uninitialized memory, 
- and memory leaks. 

Valgrind runs the program in a virtual environment and instruments the code to perform detailed analysis.
Example usage: valgrind --leak-check=full ./my_program

### AddressSanitizer (ASan):

AddressSanitizer is a runtime memory error detector built into GCC and Clang compilers. 
It detects various types of memory errors, including 
- out-of-bounds accesses, 
- use-after-free errors, and 
- heap buffer overflows. 
ASan instruments the code during compilation to perform runtime checks.
- Example usage: gcc -fsanitize=address -g my_program.c

### GDB Dashboard:

GDB Dashboard is a GDB add-on that provides a more visually appealing and informative interface for debugging. It displays information such as 
- stack frames, 
-  variables, and registers in a structured layout, making it easier to navigate and understand the program's state.
Installation instructions and usage can be found on the GitHub repository: GDB Dashboard

### rr (Record and Replay):

rr is a tool for recording and replaying program executions. It allows you to record the execution of a program and replay it deterministically, making it useful for debugging non-deterministic bugs or investigating the behavior of complex programs.
- Example usage: rr record ./my_program

### Strace:

Strace is a diagnostic tool that intercepts and records system calls made by a program. 
It can be used to trace 
- system calls, 
- signals, and other interactions between the program and the operating system, 
helping to diagnose issues related to 
- file I/O, 
- networking, and 
- process management.
- Example usage: strace ./my_program

### Ltrace:

Ltrace is similar to Strace but focuses on intercepting and recording library calls (dynamic linker calls) made by a program. It can be used to trace library function calls and diagnose issues related to dynamic linking and library dependencies.
- Example usage: ltrace ./my_program
These are just a few examples of tools commonly used alongside GDB for debugging in Linux. Depending on the nature of the problem and the specific requirements, different tools may be more suitable for debugging different types of issues.

### GDB Debugging tips
- 1. Breakpoints:
    - break or b: Set breakpoints at specific lines of code or functions.
    - delete: Delete breakpoints.
- 2. Running and Stopping:
    - run or r: Start the program execution.
    - continue or c: Continue execution until the next breakpoint or program termination.
    - step or s: Execute the next line of code and step into function calls.
    - next or n: Execute the next line of code but step over function calls.
- 3. Examining Variables:
    - print or p: Print the value of a variable.
    - display: Print the value of a variable every time the program stops.
    - info locals: Display local variables in the current scope.
    - info args: Display function arguments in the current scope.
- 4. Stack and Backtrace:
    - bt or backtrace: Display a backtrace of the call stack.
    - frame: Select a specific stack frame for inspection.
    - up and down: Move up and down the call stack.
- 5. Memory Inspection:
    - x: Examine memory content at a specific address.
    - info proc mappings: Display memory mappings of the process.
    - info registers: Display contents of CPU registers.
- 6. Breakpoint Commands:
    - commands: Specify commands to execute when a breakpoint is hit.
    - enable and disable: Enable or disable breakpoints.
- 7. Disassembling:
    - disassemble or disas: Disassemble a function or a range of memory addresses.
- 8. Stepping Out:
    - finish: Execute until the current function returns.
- 9. Signal Handling:
    - handle: Configure how GDB handles specific signals.
- 10. File and Function Information:
    - info files: Display information about the executable file being debugged.
    - info functions: List all functions in the current executable.

These are just a subset of the many commands available in GDB. GDB offers extensive functionality for debugging, including support for multi-threaded programs, remote debugging, scriptability, and more. You can find more details about these commands and additional commands in the GDB documentation or by using the help command within GDB itself.