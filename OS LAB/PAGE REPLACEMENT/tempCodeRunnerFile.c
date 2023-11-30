#include <stdio.h>
#include <stdlib.h>

void reframe(int *frame, int frames, int index) {
    int temp = frame[index];
    for (int k = index; k > 0; k--) {
        frame[k] = frame[k - 1];
    }
    frame[0] = temp;
}

int lru(int csno, int *controlstring, int frames) {
    int pf = 0, *frame, i, k, avail, index;
    frame = (int *)calloc(frames, sizeof(int));

    for (i = 0; i < csno; i++) {
        avail = 0;

        for (k = 0; k < frames; k++) {
            if (frame[k] == controlstring[i]) {
                avail = 1;
                index = k;
                break;
            }
        }

        printf("After reference %d: ", controlstring[i]);
        for (int j = 0; j < frames; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");

        if (avail == 1) {
            reframe(frame, frames, index);
        } else {
            if (i < frames) {
                frame[i] = controlstring[i];
                reframe(frame, i, i);
            } else {
                frame[frames - 1] = controlstring[i];
                reframe(frame, frames - 1, frames - 1);
            }
            pf++;
        }
    }
    free(frame);
    return pf;
}

int main() {
    int csno, *controlstring, frames, pf;
    printf("Enter the number of pages: ");
    scanf("%d", &csno);

    controlstring = (int *)malloc(sizeof(int) * csno);

    printf("Enter the reference string: ");
    for (int i = 0; i < csno; i++) {
        scanf("%d", &controlstring[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    pf = lru(csno, controlstring, frames);

    printf("\nNumber of page faults is %d\n", pf);
    free(controlstring);
    return 0;
}
