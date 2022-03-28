/* The Instructions and Registers Header for RAM-VM */
/* Copyright (c) 2022 Harish Kumar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef VM_H
#define VM_H

#include <instr.h>

/* The RAM-VM Stack */
#define STACK_SIZE 512

int stack[STACK_SIZE];

/* Registers Set for VM */
typedef enum {
    RA, RB, RC, RD, RE, RF, // General Registers
    IP,                     // Instruction Pointer
    SP,                     // Stack Pointer
    REG_SIZE
} Registers;

int registers[REG_SIZE];

/* Pointers */
#define SP (registers[SP])
#define IP (registers[IP])
#define FETCH (program[IP])

/* Important Flags and Variables */
bool running = true;
bool is_jmp = false;
int instruction_space = 4;
int instruction_count = 0;

#endif