#include <stdio.h>

void firstFit(int blockSizes[], int numBlocks, int processSizes[], int numProcesses) {
    int allocation[numProcesses];

  
    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1;
    }

  
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numBlocks; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                allocation[i] = j;               
                blockSizes[j] -= processSizes[i]; 
                break;
            }
        }
    }

    
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSizes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockSizes[] = {100, 500, 200, 300, 600};
    int processSizes[] = {212, 417, 112, 426};
    int numBlocks = sizeof(blockSizes) / sizeof(blockSizes[0]);
    int numProcesses = sizeof(processSizes) / sizeof(processSizes[0]);

    firstFit(blockSizes, numBlocks, processSizes, numProcesses);

    return 0;
}

