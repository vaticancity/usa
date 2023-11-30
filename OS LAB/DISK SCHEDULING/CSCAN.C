#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sort(int req[], int no_req) {
    for(int i = 0; i < no_req-1; i++) {
        for(int j = 0; j < no_req-i-1; j++) {
            if (req[j] > req[j+1]) {
                int temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }
}

void cscan(int req[], int no_req, int head, int tracks) {
    int distarray[100], s = 0, c = 0, index = -1;

    sort(req, no_req);

    // Find the index where the head is located in the request array
    for (index = 0; index < no_req; index++) {
        if (head < req[index]) {
            break;
        }
    }

    // Handle the requests from head to the end of the disk
    for (int i = index; i < no_req; i++) {
        distarray[c] = abs(head - req[i]);
        s += distarray[c];
        head = req[i];
        c++;
    }

    // Move the head to the beginning of the disk
    distarray[c] = abs(head - 0);
    s += distarray[c];
    head = 0;
    c++;

    // Handle the requests from the beginning of the disk to the head
    for (int i = 0; i < index; i++) {
        distarray[c] = abs(head - req[i]);
        s += distarray[c];
        head = req[i];
        c++;
    }

    printf("\nThe sequence is: ");
    for (int i = 0; i < c; i++) {
        printf("%d ", req[i]);
    }

    printf("\nDIST: ");
    for (int i = 0; i < c; i++) {
        printf("%d ", distarray[i]);
    }

    printf("\nThe total seek time is: %d\n", s);
    printf("The avg seek time is: %.2f\n", (float)s / no_req);
}

int main() {
    int tracks;
    printf("Enter the number of tracks: ");
    scanf("%d", &tracks);

    int no_req;
    printf("Enter the number of requests: ");
    scanf("%d", &no_req);

    int req[no_req];
    printf("Enter the requests:\n");
    for(int i = 0; i < no_req; i++) {
        printf("Request %d: ", i+1);
        scanf("%d", &req[i]);
    }

    int head;
    printf("Enter the current head: ");
    scanf("%d", &head);

    cscan(req, no_req, head, tracks);

    return 0;
}
