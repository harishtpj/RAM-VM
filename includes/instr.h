/* The Instructions List Header for RAM-VM */
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

#ifndef INSTR_H
#define INSTR_H

/* Instruction Set for VM */
typedef enum {
    PUSH, // Push Value
    POP,  // Pop Value
    FREE, // Silent POP
    ADD,  // Add Values in stack
    SUB,  // Subtract Values in stack
    MUL,  // Multiply Values in stack
    DIV,  // Divide Values in stack
    SET,  // Sets registry value to given value
    MOV,  // Moves registry value
    LDR,  // Loads Registry into Stack
    PSR,  // Loads Registry into Stack
    PREG, // Print Specified Registry
    IF,   // if reg == val jumps to IP
    IFN,  // if reg != val jumps to IP
    PUTS, // Puts String 
    NL,   // Puts New line 
    HALT  // Stops Execution
} InstructionSet;

#endif