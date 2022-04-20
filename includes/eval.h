/* The Instructions Evaluator Header for RAM-VM */
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

#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <string.h>
#include <vm.h>

void eval(int program[]) {
    int instr = FETCH;
    is_jmp = false;

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
        SP--;
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

    case PREG: {
        printf("%d", registers[program[IP + 1]]);
        IP = IP + 1;
        break;
    }

    case IF: {
        int reg = registers[program[IP + 1]];
        int val = program[IP + 2];
        
        if (reg == val) {
            IP = program[IP + 3];
            is_jmp = true;
        } else {
            IP = IP + 3;
        }
        break;
    }

    case IFN: {
        int reg = registers[program[IP + 1]];
        int val = program[IP + 2];
        
        if (reg != val) {
            IP = program[IP + 3];
            is_jmp = true;
        } else {
            IP = IP + 3;
        }
        break;
    }

    case PUTS: {
        int slen = program[IP + 1];
        for (int i = 0; i <= slen; i++) {
            putchar(program[IP + 1 + i]);
        }
        IP = IP + slen + 1;
        break;
    }

    case NL: {
        putchar('\n');
        break;
    }

    case GETC: {
        registers[RC] = getc(stdin);
        break;
    }

    case PUTC: {
        char ch = stack[SP--];
        putchar(ch);
        break;
    }

    case CATC: {
        char tmp[2] = {registers[RC], 0};
        strcat(str, tmp);
        break;
    }

    case PSTR: {
        printf("%s", str);
        break;
    }

    case GETS: {
        scanf("%100[^\n]%*c", str);
        break;
    }

    case AND: {
        int reg_a = program[IP + 1];
        int reg_b = program[IP + 2];
        registers[reg_a] &= registers[reg_b];
        IP = IP + 2;
        break;
    }

    case OR: {
        int reg_a = program[IP + 1];
        int reg_b = program[IP + 2];
        registers[reg_a] |= registers[reg_b];
        IP = IP + 2;
        break;
    }

    case XOR: {
        int reg_a = program[IP + 1];
        int reg_b = program[IP + 2];
        registers[reg_a] ^= registers[reg_b];
        IP = IP + 2;
        break;
    }

    case NOT: {
        int reg_a = program[IP + 1];
        registers[reg_a] = ~registers[reg_a];
        IP = IP + 1;
        break;
    }
    
    default:
        printf("Unknown Instruction %d\n", instr);
        break;
    }
}

#endif