/* The Instructions and Registers Header for RAM-VM */

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
    HALT  // Stops Execution
} InstructionSet;

#endif