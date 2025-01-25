#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

int findDistance(vector<int>& pages, int start, int value) {
    for (int i = start; i < pages.size(); i++) {
        if (pages[i] == value) {
            return i - start;
        }
    }
    return INT_MAX;
}

void optimalPageReplacement(vector<int>& pages, int frameSize) {
    int pageFaults = 0;
    int pageHits = 0;
    unordered_set<int> frameSet;
    vector<int> frames(frameSize, -1);

    cout << "Page Reference Sequence\tFrames\t\tHit/Fault\n";

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
        cout << page << "\t\t\t";

        auto it = frameSet.find(page);
        if (it != frameSet.end()) {
            pageHits++;
            cout << "Hit\t";
        } else {
            if (frameSet.size() < frameSize) {
                frameSet.insert(page);
                int freeFrameIndex = -1;
                for (int j = 0; j < frameSize; j++) {
                    if (frames[j] == -1) {
                        freeFrameIndex = j;
                        break;
                    }
                }
                frames[freeFrameIndex] = page;
            } else {
                int maxIndexFound = -1;
                int maxDistance = INT_MIN;
                for (int j = 0; j < frameSize; j++) {
                    int distance = findDistance(pages, i + 1, frames[j]);
                    if (distance > maxDistance) {
                        maxDistance = distance;
                        maxIndexFound = j;
                    }
                }
                frameSet.erase(frames[maxIndexFound]);
                frameSet.insert(page);
                frames[maxIndexFound] = page;
            }
            pageFaults++;
            cout << "Fault\t";
        }

        cout << "[ ";
        for (int frame : frames) {
            if (frame != -1) {
                cout << frame << " ";
            }
        }
        cout << "]\n";
    }

    cout << "\nTotal page faults: " << pageFaults << endl;
    cout << "Total page hits: " << pageHits << endl;
}

int main() {
    int frameSize;
    cout << "Enter the number of frames: ";
    cin >> frameSize;

    int numPages;
    cout << "Enter the number of pages: ";
    cin >> numPages;

    vector<int> pages(numPages);
    cout << "Enter the page reference sequence: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }

    optimalPageReplacement(pages, frameSize);

    return 0;
}