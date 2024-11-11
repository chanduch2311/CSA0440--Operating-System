#include <stdio.h>
#include <stdlib.h>

void SCAN(int requests[], int n, int head, int direction) {
    int seekCount = 0;
    int distance;
    int maxTrack = 200;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    printf("Seek sequence: ");
    if (direction == 1) {
   
        for (int i = 0; i < n; i++) {
            if (requests[i] > head) {
                distance = abs(requests[i] - head);
                seekCount += distance;
                head = requests[i];
                printf("%d -> ", head);
            }
        }
        printf("%d -> ", maxTrack);
    } else {

        for (int i = n - 1; i >= 0; i--) {
            if (requests[i] < head) {
                distance = abs(requests[i] - head);
                seekCount += distance;
                head = requests[i];
                printf("%d -> ", head);
            }
        }
        printf("0 -> ");
    }

    printf("\nTotal seek operations: %d\n", seekCount);
}

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50;
    int n = sizeof(requests) / sizeof(requests[0]);
    int direction = 1;  

    SCAN(requests, n, head, direction);

    return 0;
}

