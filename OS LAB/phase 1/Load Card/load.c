#include <stdio.h>
#include <string.h>

int main() {
    int m = 0;
    char memory[100][4][256]; // Initialize memory as a 3D array of strings
    
    FILE *file = fopen("f1.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    
    int next_line = 0;
    
    FILE *file_output = fopen("output.txt", "w");
    
    if (file_output == NULL) {
        printf("Failed to open output.txt for writing.\n");
        fclose(file);
        return 1;
    }
    
    char line[256]; // Assume lines are no longer than 255 characters
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; // Remove the newline character
        
        char card_type[5];
        strncpy(card_type, line, 4);
        card_type[4] = '\0';
        
        if (strcmp(card_type, "$AMJ") == 0) {
            printf("%s\n", line);
        } else if (strcmp(card_type, "$DTA") == 0) {
            printf("%s\n", line);
            next_line = 1;
            continue;
        } else if (strcmp(card_type, "$END") == 0) {
            printf("%s\n", line);
            break;
        } else if (next_line) {
            fprintf(file_output, "%s\n", line);
            next_line = 0;
        } else {
            if (m >= 100) {
                printf("External Memory out of space.\n");
                break;
            }
            
            char content[256];
            strcpy(content, line);
            
            char *token = strtok(content, " ");
            int i = 0;
            while (token != NULL && i < 4) {
                strcpy(memory[m][i], token);
                i++;
                token = strtok(NULL, " ");
            }
            
            char *instruction = memory[m][0];
            printf("%s ", instruction);
            
            if (strcmp(instruction, "GD") == 0 || strcmp(instruction, "PD") == 0 || strcmp(instruction, "H") == 0) {
                printf("%d ", m + 10);
            } else {
                printf("%d ", m);
            }
            
            if (token != NULL) {
                if (strcmp(instruction, "GD") == 0) {
                    printf("IN %s ST LINE\n", memory[m][1]);
                    scanf("%s", memory[m][1]);
                } else if (strcmp(instruction, "PD") == 0) {
                    printf("IN %s ST LINE\n", memory[m][1]);
                    fprintf(file_output, "%s\n", memory[m][1]);
                } else if (strcmp(instruction, "H") == 0) {
                    break;
                }
            }
            m++;
        }
    }
    
    fclose(file);
      
    printf("Contents of B0 B1:\n");
    for (int i = 0; i < m; i++) {
        printf("%s %s %s %s\n", memory[i][0], memory[i][1], memory[i][2], memory[i][3]);
    }
    
    FILE *file_output_file = fopen("output.txt", "r");
    if (file_output_file == NULL) {
        printf("Failed to open output.txt for reading.\n");
        return 1;
    }
    
    printf("Contents of output.txt:\n");
    char output_line[256];
    while (fgets(output_line, sizeof(output_line), file_output_file)) {
        output_line[strcspn(output_line, "\n")] = '\0'; // Remove the newline character
        printf("%s\n", output_line);
    }
    
    fclose(file_output_file);
    return 0;
}