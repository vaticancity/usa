#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int arrival;
    int burst;
    int completion;
    int remaining;
    int waiting;
    int turnaround;
    int response;
    int inreadyQ;
    int completed;
};

void round_robin(struct Process processes[], int n) {
    int time_quantum;
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    int currenttime = 0;
    int completedproc = 0;
    struct Process *currentprocess = NULL;

    // Initialize inreadyQ for all processes
    for (int i = 0; i < n; i++) {
        processes[i].inreadyQ = 0;
    }

    // Ready queue
    struct Process *readyQ[n];
    int front = -1, rear = -1;

    // Enqueue process in ready queue
    void enqueue(struct Process *process) {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % n;
        readyQ[rear] = process;
    }

    // Dequeue process from ready queue
    struct Process *dequeue() {
        struct Process *process = readyQ[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % n;
        }
        return process;
    }

    // Check if ready queue is empty
    int isReadyQEmpty() {
        return front == -1;
    }

    // Enqueue processes in ready queue based on arrival time
    for (int i = 0; i < n; i++) {
        if (!processes[i].completed && currenttime >= processes[i].arrival && !processes[i].inreadyQ) {
            enqueue(&processes[i]);
            processes[i].inreadyQ = 1;
        }
    }

    while (completedproc < n) {
        currentprocess = dequeue();

        if (currentprocess->response == -1) {
            currentprocess->response = currenttime - currentprocess->arrival;
        }

        int time_taken;
        if (currentprocess->remaining < time_quantum) {
            time_taken = currentprocess->remaining;
        } else {
            time_taken = time_quantum;
        }

        currenttime += time_taken;
        currentprocess->remaining -= time_taken;

        // Enqueue processes in ready queue based on arrival time
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && currenttime >= processes[i].arrival && !processes[i].inreadyQ) {
                enqueue(&processes[i]);
                processes[i].inreadyQ = 1;
            }
        }

        if (currentprocess->remaining > 0) {
            enqueue(currentprocess);
        } else {
            completedproc++;
            currentprocess->completion = currenttime;
            currentprocess->turnaround = currenttime - currentprocess->arrival;
            currentprocess->waiting = currentprocess->turnaround - currentprocess->burst;
            currentprocess->completed = 1;
        }
    }

    printf("Id\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrival, processes[i].burst,
               processes[i].completion, processes[i].turnaround, processes[i].waiting, processes[i].response);
    }
}

int main() {
    int n;
    printf("Number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival and burst for process %d : ", i);
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
        processes[i].id = i;
        processes[i].remaining = processes[i].burst;
        processes[i].completed = 0;
    }

    round_robin(processes, n);

    return 0;
}