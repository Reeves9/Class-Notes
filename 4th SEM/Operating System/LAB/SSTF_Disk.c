#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findClosestRequest(int headPosition, int* requests, int n, int* served) {
    int closestRequest = INT_MAX;
    int minDistance = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (!served[i]) {
            int distance = abs(requests[i] - headPosition);
            if (distance < minDistance) {
                minDistance = distance;
                closestRequest = requests[i];
            } else if (distance == minDistance) {
                closestRequest = (closestRequest > requests[i]) ? requests[i] : closestRequest;
            }
        }
    }

    return closestRequest;
}

void sstfDiskScheduling(int initialHead, int* requests, int n) {
    int* served = (int*)calloc(n, sizeof(int));
    int totalHeadMovement = 0;
    int currentHead = initialHead;
    int sequence[n + 1];
    int sequenceIndex = 0;

    sequence[sequenceIndex++] = currentHead;

    for (int i = 0; i < n; i++) {
        int closestRequest = findClosestRequest(currentHead, requests, n, served);
        if (closestRequest == INT_MAX)
            break;

        for (int j = 0; j < n; j++) {
            if (requests[j] == closestRequest) {
                served[j] = 1;
                break;
            }
        }

        totalHeadMovement += abs(closestRequest - currentHead);
        currentHead = closestRequest;
        sequence[sequenceIndex++] = currentHead;
    }

    printf("Sequence of head movements: ");
    for (int i = 0; i < sequenceIndex; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    printf("Total head movement: %d\n", totalHeadMovement);
    free(served);
}

int main() {
    int initialHead, n;
    printf("Enter the initial head position: ");
    scanf("%d", &initialHead);
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int* requests = (int*)malloc(n * sizeof(int));
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    sstfDiskScheduling(initialHead, requests, n);
    free(requests);
    return 0;
}