#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int>> jewel;
vector<int> bagLimit;
priority_queue<int,vector<int>,less<int>> pq;
int main() {
    int n, k, m, v, c, weight;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        jewel.push_back({ m,v });
    }

    for (int i = 0; i < k; i++) {
        cin >> weight;
        bagLimit.push_back(weight);
    }

    sort(jewel.begin(), jewel.end());
    sort(bagLimit.begin(), bagLimit.end());

    int idx = 0;
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        while (idx < n && bagLimit[i] >= jewel[idx].first) {
            pq.push(jewel[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << endl;
    return 0;
}
