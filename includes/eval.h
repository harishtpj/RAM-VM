/* The Instructions Evaluator Header for RAM-VM */

#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <vm.h>

void eval(int program[]) {
    int instr = FETCH;

    switch (instr) {
    case HALT: {
        running = 0;
        break;
    }
    
    case PUSH: {
        SP++;
        stack[SP] = program[++IP];
        break;
    }

    case POP: {
        int popped_val = stack[SP--];
        printf("Popped: %d\n", popped_val);
        break;
    }

    case FREE: {
        int popped_val = stack[SP--];
        break;
    }

    case ADD: {
        int a = stack[SP--];
        int b = stack[SP--];
        SP++;
        stack[SP] = a + b;
        break;
    }

    case SUB: {
        int a = stack[SP--];
        int b = stack[SP--];
        SP++;
        stack[SP] = b - a;
        break;
    }

    case MUL: {
        int a = stack[SP--];
        int b = stack[SP--];
        SP++;
        stack[SP] = a * b;
        break;
    }

    case DIV: {
        int a = stack[SP--];
        int b = stack[SP--];
        SP++;
        stack[SP] = b / a;
        break;
    }

    case SET: {
        int reg = program[IP + 1];
        int val = program[IP + 2];
        registers[reg] = val;
        IP = IP + 2;
        break;
    }

    case MOV: {
        int reg_a = program[IP + 1];
        int reg_b = program[IP + 2];
        registers[reg_b] = registers[reg_a];
        IP = IP + 2;
        break;
    }

    case LDR: {
        SP = SP + 1;
        IP = IP + 1;
        stack[SP] = registers[program[IP]];
        break;
    }

    case PSR: {
        int reg = program[IP + 1];
        registers[reg] = stack[SP];
        IP = IP + 1;
        break;
    }
    
    default:
        printf("Unknown Instruction %d\n", instr);
        break;
    }
}

#endif