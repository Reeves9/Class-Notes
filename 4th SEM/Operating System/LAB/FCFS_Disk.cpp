#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fcfsDiskScheduling(int initialHead, vector<int>& requests) {
    int totalHeadMovement = 0;
    int n = requests.size();
    vector<int> sequence;

    sort(requests.begin(), requests.end());

    int headPosition = 0;
    for (int i = 0; i < n; i++) {
        if (requests[i] >= initialHead) {
            headPosition = i;
            break;
        }
    }

    sequence.push_back(initialHead);

    for (int i = headPosition; i < n; i++) {
        totalHeadMovement += abs(requests[i] - initialHead);
        initialHead = requests[i];
        sequence.push_back(initialHead);
    }

    for (int i = 0; i < headPosition; i++) {
        totalHeadMovement += abs(requests[i] - initialHead);
        initialHead = requests[i];
        sequence.push_back(initialHead);
    }

    cout << "Sequence of head movements: ";
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
    cout << endl;

    cout << "Total head movement: " << totalHeadMovement << endl;
}

int main() {
    int initialHead, n;
    cout << "Enter the initial head position: ";
    cin >> initialHead;

    cout << "Enter the number of disk requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the disk requests: ";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    fcfsDiskScheduling(initialHead, requests);

    return 0;
}
