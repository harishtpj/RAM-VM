/* The RAM-VM Stack Based Virtual Machine */

/* Includes */
#include <stdio.h>
#include <stdbool.h>

/* VM Includes */
#include <vm.h>
#include <eval.h>

// Sample Program
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
    HALT
};

int main() {
    IP = 0;
    SP = -1;
    
    while (running) {
        eval(program);
        IP++;
    }
    
    return 0;
}