#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void SCAN(vector<int> requests, int start, int end) {
    int head_position = start;
    int total_movement = 0;

    sort(requests.begin(), requests.end());

    auto it = lower_bound(requests.begin(), requests.end(), head_position);
    int index = it - requests.begin();

    cout << "Moving towards the end: ";
    for (int i = index; i < requests.size(); ++i) {
        cout << requests[i] << " ";
        total_movement += abs(head_position - requests[i]);
        head_position = requests[i];
    }

    cout << "0 ";
    total_movement += head_position;
    head_position = 0;

    for (int i = index - 1; i >= 0; --i) {
        cout << requests[i] << " ";
        total_movement += abs(head_position - requests[i]);
        head_position = requests[i];
    }

    cout << endl;

    cout << "Total head movement: " << total_movement << endl;
}

int main() {
    cout << "Enter the range of disk: ";
    int start, end, n;
    cin >> start >> end;
    cout << "Enter the number of requests: ";
    cin >> n;
    vector<int> requests(n);
    cout << "Enter the requests: ";
    for (int i = 0; i < n; ++i) {
        cin >> requests[i];
    }
    cout << "Enter the starting head position: ";
    cin >> start;

    SCAN(requests, start, end);

    return 0;
}
