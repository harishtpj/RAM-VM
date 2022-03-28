/* The RAM-VM Stack Based Virtual Machine */
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

/* Includes */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* VM Includes */
#include <vm.h>
#include <eval.h>

/* Main Function */
int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("error: no input files\n");
        return -1;
    }

    char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("error: could not read file `%s`\n", filename);
        return -1;
    }

    int *program = malloc(sizeof(*program) * instruction_space); // 4 instructions

    int num;
    int i = 0;
    while (fscanf(file, "%d", &num) > 0) {
        program[i] = num;
        i++;
        if (i >= instruction_space) {
            instruction_space *= 2;
            program = realloc(program, sizeof(*program) * instruction_space); // double size
        }
    }

    instruction_count = i;

    // close the file
    fclose(file);

    IP = 0;
    SP = -1;
    
    while (running && IP < instruction_count) {
        eval(program);
        if(!is_jmp){
            IP = IP + 1;
        }
    }

    free(program);
    
    return 0;
}