#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int no_of_processes, no_of_resources;
int available[MAX_RESOURCES];
int max_need[MAX_PROCESSES][MAX_RESOURCES];
int allocated[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finish[MAX_PROCESSES];

// Function to check if a process can be safely executed
bool isSafe(int process) {
    for (int i = 0; i < no_of_resources; i++) {
        if (need[process][i] > available[i])
            return false;
    }
    return true;
}

int main() {
    printf("**** BANKER'S ALGORITHM ****\n\n");

    // Input the number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &no_of_processes);
    printf("Enter the number of resources: ");
    scanf("%d", &no_of_resources);

    // Input the maximum resource needs for each process
    printf("Enter the maximum resource needs for each process:\n");
    for (int i = 0; i < no_of_processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < no_of_resources; j++) {
            scanf("%d", &max_need[i][j]);
        }
        finish[i] = false;
    }

    // Input the allocated resources for each process
    printf("Enter the allocated resources for each process:\n");
    for (int i = 0; i < no_of_processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < no_of_resources; j++) {
            scanf("%d", &allocated[i][j]);
            need[i][j] = max_need[i][j] - allocated[i][j];
        }
    }

    // Input the available resources
    printf("Enter the available resources: ");
    for (int i = 0; i < no_of_resources; i++) {
        scanf("%d", &available[i]);
    }

    // Display the contents of maximum needs, allocated resources, and needed resources in a tabular format
    printf("\nResource Allocation Table:\n");
    printf("Process |Maximum|Allocated|Needed|\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < no_of_processes; i++) {
        printf("P%d      | ", i);
        for (int j = 0; j < no_of_resources; j++) {
            printf("%d ", max_need[i][j]);
        }
        printf("| ");
        for (int j = 0; j < no_of_resources; j++) {
            printf("%d ", allocated[i][j]);
        }
        printf("| ");
        for (int j = 0; j < no_of_resources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Check for a safe sequence
    bool safe = false;
    int safe_sequence[MAX_PROCESSES];
    int sequence_index = 0;

    for (int count = 0; count < no_of_processes; count++) {
        bool current_safe = false;  // Variable to track the safety of the current iteration

        for (int i = 0; i < no_of_processes; i++) {
            if (!finish[i] && isSafe(i)) {
                // Print the safe sequence during execution
                printf("Executing P%d -> ", i);

                for (int j = 0; j < no_of_resources; j++) {
                    available[j] += allocated[i][j];
                }
                safe_sequence[sequence_index] = i;
                sequence_index++;
                finish[i] = true;
                current_safe = true;
            }
        }

        // Check if the system is still safe after the current iteration
        if (!current_safe) {
            // The system becomes unsafe during this iteration
            printf("\nSystem becomes unsafe after executing the processes. Deadlock detected.\n");

            // Print the processes involved in the deadlock
            printf("Processes involved in the deadlock: ");
            for (int i = 0; i < no_of_processes; i++) {
                if (!finish[i]) {
                    printf("P%d ", i);
                }
            }
            printf("\n");

            break;
        }
    }

    if (sequence_index == no_of_processes) {
        // If the safe sequence is complete, print it
        printf("\nSystem is in a safe state.\n");
        printf("Safe sequence: ");
        for (int i = 0; i < no_of_processes; i++) {
            printf("P%d ", safe_sequence[i]);
        }
        printf("\n");
    }

    return 0;
}