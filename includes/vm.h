/* The Instructions and Registers Header for RAM-VM */

#ifndef VM_H
#define VM_H

#include <instr.h>

/* The RAM-VM Stack */
#define STACK_SIZE 256

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
int instruction_space = 4;
int instruction_count = 0;

#endif