#include <stdio.h>
#include <stdbool.h>
#include <string.h>  // Include the string.h header for strcmp function

int R0 = 0;
int R1 = 0;
int memory[1024] = {0};

void load_register(int reg[2], int mem_address) {
    reg[0] = memory[mem_address];
    printf("Loaded %d into R%d\n", reg[0], reg[1]);
}

void store_register(int reg[2], int mem_address) {
    memory[mem_address] = reg[0];
    printf("Stored %d from R%d to memory address %d\n", reg[0], reg[1], mem_address);
}

bool compare_registers(int reg1[2], int reg2[2]) {
    return reg1[0] == reg2[0];
}

int main() {
    printf("Welcome to the Simple Processor Emulator!\n");

    while (1) {
        char instruction[3];
        printf("Enter instruction (LR, SR, CR, BT, or QUIT): ");
        scanf("%s", instruction);

        if (strcmp(instruction, "LR") == 0) {
            int reg_num;
            int mem_address;
            printf("Enter register number (0 or 1): ");
            scanf("%d", &reg_num);
            printf("Enter memory address: ");
            scanf("%d", &mem_address);

            if (reg_num == 0) {
                int reg[2] = {R0, reg_num};
                load_register(reg, mem_address);
            } else if (reg_num == 1) {
                int reg[2] = {R1, reg_num};
                load_register(reg, mem_address);
            } else {
                printf("Invalid register number.\n");
            }
        } 
        else if (strcmp(instruction, "SR") == 0) {
            int reg_num;
            int mem_address;
            printf("Enter register number (0 or 1): ");
            scanf("%d", &reg_num);
            printf("Enter memory address: ");
            scanf("%d", &mem_address);

            if (reg_num == 0) {
                int reg[2] = {R0, reg_num};
                store_register(reg, mem_address);
            } else if (reg_num == 1) {
                int reg[2] = {R1, reg_num};
                store_register(reg, mem_address);
            } else {
                printf("Invalid register number.\n");
            }
        } 
        else if (strcmp(instruction, "CR") == 0) {
            int reg1[2] = {R0, 0};
            int reg2[2] = {R1, 1};

            if (compare_registers(reg1, reg2)) {
                printf("Registers R0 and R1 are equal.\n");
            } else {
                printf("Registers R0 and R1 are not equal.\n");
            }
        } 
        else if (strcmp(instruction, "BT") == 0) {
            int reg1[2] = {R0, 0};
            int reg2[2] = {R1, 1};

            if (compare_registers(reg1, reg2)) {
                printf("Branching condition is true. Executing branch.\n");
            } else {
                printf("Branching condition is false. Not branching.\n");
            }
        } 
        else if (strcmp(instruction, "QUIT") == 0) {
            printf("Exiting the emulator.\n");
            break;
        } 
        else {
            printf("Invalid instruction. Please enter LR, SR, CR, BT, or QUIT.\n");
        }
    }

    return 0;
}
