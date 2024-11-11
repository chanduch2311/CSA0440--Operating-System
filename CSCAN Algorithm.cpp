#include <stdio.h>
#include <stdlib.h>

void CSCAN(int requests[], int n, int head) {
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
    for (int i = 0; i < n; i++) {
        if (requests[i] > head) {
            distance = abs(requests[i] - head);
            seekCount += distance;
            head = requests[i];
            printf("%d -> ", head);
        }
    }

    seekCount += abs(maxTrack - head);
    printf("%d -> 0 -> ", maxTrack);

    head = 0;
    for (int i = 0; i < n && requests[i] < maxTrack; i++) {
        distance = abs(requests[i] - head);
        seekCount += distance;
        head = requests[i];
        printf("%d -> ", head);
    }

    printf("\nTotal seek operations: %d\n", seekCount);
}

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50;
    int n = sizeof(requests) / sizeof(requests[0]);

    CSCAN(requests, n, head);

    return 0;
}

