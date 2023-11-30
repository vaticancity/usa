#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

int main() {
    int n, no_of_frames, page_faults = 0;
    bool isPagePresent = false;
    int current_frame = 0;

    printf("**** WELCOME TO THE FIFO Page Replacement Algorithm ****\n\n");

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int reference_string[n];
    printf("Enter the reference string (different page numbers):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &reference_string[i]);
    }

    printf("Enter the number of frames available for the process: ");
    scanf("%d", &no_of_frames);

    int frames[MAX_FRAMES];
    for (int i = 0; i < no_of_frames; i++) {
        frames[i] = -1; // Initialize frames as empty (-1)
    }

    printf("\n*** The Contents inside the Frame array at Different Times ***\n");

    for (int i = 0; i < n; i++) {
        isPagePresent = false;

        // Check if the page is already in a frame
        for (int j = 0; j < no_of_frames; j++) {
            if (frames[j] == reference_string[i]) {
                isPagePresent = true;
                break;
            }
        }

        if (!isPagePresent) {
            // Page fault, replace the oldest page
            page_faults++;
            frames[current_frame] = reference_string[i];

            // Print the contents of the frames
            for (int j = 0; j < no_of_frames; j++) {
                printf("%d ", frames[j]);
            }
            printf("\n");

            // Update the current_frame
            current_frame = (current_frame + 1) % no_of_frames;
        }
    }

    printf("\nTotal number of Page Faults = %d\n", page_faults);
    printf("Page Fault Ratio = %.2f\n", (float)page_faults / n);
    printf("Page Hit Ratio = %.2f\n", 1 - (float)page_faults / n);

    return 0;
}