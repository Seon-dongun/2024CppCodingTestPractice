#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> info(n);
    int arr[1001];
    int linfo[1001] = { 0, }, rinfo[1001] = { 0, };
    int maxX = -1;
    int minX = 2000;
    for (int i = 0; i < n; i++) {
        cin >> info[i].first >> info[i].second;
        if (maxX <= info[i].first)
            maxX = info[i].first;
        if (minX > info[i].first)
            minX = info[i].first;

        arr[info[i].first] = info[i].second;
    }

    linfo[minX] = arr[minX];
    for (int i = minX + 1; i <= maxX; i++)
        linfo[i] = max(linfo[i - 1], arr[i]);

    for (int i = maxX; i >= minX; i--) 
        rinfo[i] = max(rinfo[i + 1], arr[i]);

    int answer = 0;
    for (int i = minX; i <= maxX; i++)
        answer += min(linfo[i], rinfo[i]);

    cout << answer << endl;
    return 0;
}