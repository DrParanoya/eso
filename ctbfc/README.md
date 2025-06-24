# ctbfc
Compile time "Brainfuck" compiler  
Usage:
1. Convert your brainfuck file with convert.py
2. Compile your generated c source file with the c compiler of your choice.

On my machine, mandelbrot.bf runs in 1.3 seconds after compiling it with gcc and O3
mandelbrot.bf.c is the generated C source file