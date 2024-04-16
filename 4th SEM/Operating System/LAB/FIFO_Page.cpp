#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void fifoPageReplacement(vector<int>& pages, int frameSize) {
    int pageFaults = 0;
    int pageHits = 0;
    queue<int> frameQueue;
    unordered_set<int> frameSet;

    cout << "Page Reference Sequence\tFrames\t\tHit/Fault\n";

    for (int page : pages) {
        cout << page << "\t\t\t";

        if (frameSet.size() < frameSize) {
            if (frameSet.find(page) == frameSet.end()) {
                frameSet.insert(page);
                frameQueue.push(page);
                pageFaults++;
                cout << "Fault\t";
            } else {
                pageHits++;
                cout << "Hit\t";
            }
        } else {
            if (frameSet.find(page) == frameSet.end()) {
                int oldestPage = frameQueue.front();
                frameQueue.pop();
                frameSet.erase(oldestPage);
                frameSet.insert(page);
                frameQueue.push(page);
                pageFaults++;
                cout << "Fault\t";
            } else {
                pageHits++;
                cout << "Hit\t";
            }
        }

        cout << "[ ";
        for (int frame : frameSet) {
            cout << frame << " ";
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

    fifoPageReplacement(pages, frameSize);

    return 0;
}