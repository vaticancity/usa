#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int wt;
    int bt;
    int at;
    int tat;
    int start_time;
    int completion_time;
};

int main() {
    int n;

    float avg_tat = 0;
    float avg_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int is_completed[n]; // Initialize is_completed array
    int execution_sequence[n]; // Array to store the execution sequence
    struct process p[n]; // An array of structures, not pointers

    for (int j = 0; j < n; j++) {
        is_completed[j] = 0;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the Pid, Arrival Time, Burst Time for process %d: ", i + 1);
        scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
    }

    int current_time = 0;
    int completed = 0;
    int sequence_index = 0; // Index for execution_sequence array

    while (completed != n) {
        int index = -1, min = 999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && is_completed[i] == 0) {
                if (p[i].bt < min) {
                    min = p[i].bt;
                    index = i;
                }
                if (p[i].bt == min) {
                    if (p[i].at < p[index].at) {
                        min = p[i].bt;
                        index = i;
                    }
                }
            }
        }
        if (index != -1) {
            p[index].start_time = current_time;
            p[index].completion_time = p[index].start_time + p[index].bt;
            p[index].tat = p[index].completion_time - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            completed++;
            is_completed[index] = 1;
            current_time = p[index].completion_time;

            // Store the executed process in the sequence array
            execution_sequence[sequence_index++] = p[index].pid;
        } else {
            current_time++;
        }
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\tST\n");
    for (int k = 0; k < n; k++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[k].pid, p[k].at, p[k].bt, p[k].completion_time, p[k].tat, p[k].wt, p[k].start_time);
    }

    // Corrected calculation of averages after all processes complete
    for (int i = 0; i < n; i++) {
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nAVG TAT:%f", avg_tat);
    printf("\nAVG WT:%f\n", avg_wt);

    // Display the sequence of processes executed
    printf("Execution Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", execution_sequence[i]);
    }

    return 0;
}