#include <stdio.h>
#include <stdlib.h>

#define MAX 30

void initializeFrames(int frames[], int m) {
    for (int i = 0; i < m; i++) {
        frames[i] = -1;
    }
}

int findOptimal(int pages[], int frames[], int m, int n) {
    int fault = 0;
    int i, j, k, pos, max, flag;
    int temp[MAX];

    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if the page is already in a frame
        for (j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                flag = 1; // Page is already in a frame
                break;
            }
        }

        if (flag == 0) {
            fault++;

            // Find a frame to replace
            if (i < m) {
                frames[i] = pages[i];
            } 
            else 
            {
                for (j = 0; j < m; j++) {
                    temp[j] = -1;

                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            temp[j] = k;
                            break;
                        }
                    }
                }

                flag = 0;
                for (j = 0; j < m; j++) {
                    if (temp[j] == -1) {
                        pos = j;
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    max = temp[0];
                    pos = 0;

                    for (j = 1; j < m; j++) {
                        if (temp[j] > max) {
                            max = temp[j];
                            pos = j;
                        }
                    }
                }

                frames[pos] = pages[i];
            }
            // Print the contents of the frames
            printf("Frame Array after page %d: ", i + 1);
            for (j = 0; j < m; j++) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }

    return fault;
}

int main() {
    int pages[MAX], frames[MAX], m, n, i, faults;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the number of frames: ");
    scanf("%d", &m);

    initializeFrames(frames, m);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    faults = findOptimal(pages, frames, m, n);

    printf("\nNumber of page faults: %d\n", faults);
    printf("Page Fault Ratio = %.2f\n", (float)faults / n);
    printf("Page Hit Ratio = %.2f\n", 1 - (float)faults / n);

    return 0;
}