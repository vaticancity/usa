#include <stdio.h>

int main() {
    int memory[1000] = {0};
    int accumulator = 0;
    int instructionCounter = 0;

    while (1) {
        int instruction;
        printf("Enter instruction (0 for GD, 1 for PD, 2 for H): ");
        scanf("%d", &instruction);

        if (instruction == 0) {  // GD - Get Data
        int data;
        printf("Enter data value: ");
        scanf("%d", &data);
        instructionCounter++;  // Increment the counter before storing the data
        memory[instructionCounter] = data;  // Store the data
        }
        else if (instruction == 1) {  // PD - Print Data
            if (instructionCounter < 1000) {
                printf("Data at address %d: %d\n", instructionCounter, memory[instructionCounter]);
                instructionCounter++;
            } else {
                printf("Invalid memory address.\n");
            }
        } else if (instruction == 2) {  // H - Halt
            printf("Program halted.\n");
            break;
        } else {
            printf("Invalid instruction. Please enter 0 (GD), 1 (PD), or 2 (H).\n");
        }
    }

    return 0;
}