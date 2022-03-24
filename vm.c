/* The RAM-VM Stack Based Virtual Machine */

/* Includes */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* VM Includes */
#include <vm.h>
#include <eval.h>

/* Sample Program
int program[] = {
    PUSH, 5,
    PUSH, 6,
    ADD,
    PUSH, 10,
    MUL,
    POP,
    SET, RA, 99,
    SET, RB, 9,
    LDR, RA,
    LDR, RB,
    DIV,
    POP,
    PUSH, 78,
    PSR, RC,
    POP,
    LDR, RC,
    POP,
    MOV, RA, RB,
    LDR, RB,
    POP,
    HALT
};
*/

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
        IP++;
    }

    free(program);
    
    return 0;
}