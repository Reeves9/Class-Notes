#include <stdio.h>
#include <stdlib.h>

void fifoPageReplacement(int* pages, int numPages, int frameSize) {
    int* frames = (int*)malloc(frameSize * sizeof(int));
    int front = 0, rear = 0;
    int pageFaults = 0, pageHits = 0;

    printf("Page Reference Sequence\tHit/Fault Frames\n");
    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        printf("%d\t\t\t", page);

        int isPresent = 0;
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == page) {
                isPresent = 1;
                pageHits++;
                printf("Hit\t");
                break;
            }
        }

        if (!isPresent) {
            frames[rear] = page;
            rear = (rear + 1) % frameSize;
            if (rear == front) {
                front = (front + 1) % frameSize;
            }
            pageFaults++;
            printf("Fault\t");
        }

        printf("[ ");
        for (int j = 0; j < frameSize; j++) {
            printf("%d ", frames[j]);
        }
        printf("]\n");
    }

    printf("\nTotal page faults: %d\n", pageFaults);
    printf("Total page hits: %d\n", pageHits);
    free(frames);
}

int main() {
    int frameSize, numPages;
    printf("Enter the number of frames: ");
    scanf("%d", &frameSize);
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    int* pages = (int*)malloc(numPages * sizeof(int));
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    fifoPageReplacement(pages, numPages, frameSize);
    free(pages);
    return 0;
}