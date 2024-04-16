#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findClosestRequest(int headPosition, vector<int>& requests, vector<bool>& served) {
    int closestRequest = INT_MAX;
    int minDistance = INT_MAX;

    for (int i = 0; i < requests.size(); i++) {
        if (!served[i]) {
            int distance = abs(requests[i] - headPosition);
            if (distance < minDistance) {
                minDistance = distance;
                closestRequest = requests[i];
            } else if (distance == minDistance) {
                // If distances are equal, prefer the smaller request
                closestRequest = min(closestRequest, requests[i]);
            }
        }
    }

    return closestRequest;
}

void sstfDiskScheduling(int initialHead, vector<int>& requests) {
    int n = requests.size();
    vector<bool> served(n, false);
    int totalHeadMovement = 0;
    int currentHead = initialHead;
    vector<int> sequence;

    sequence.push_back(currentHead);

    for (int i = 0; i < n; i++) {
        int closestRequest = findClosestRequest(currentHead, requests, served);
        if (closestRequest == INT_MAX)
            break;

        for (int j = 0; j < n; j++) {
            if (requests[j] == closestRequest) {
                served[j] = true;
                break;
            }
        }

        totalHeadMovement += abs(closestRequest - currentHead);
        currentHead = closestRequest;
        sequence.push_back(currentHead);
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

    sstfDiskScheduling(initialHead, requests);

    return 0;
}