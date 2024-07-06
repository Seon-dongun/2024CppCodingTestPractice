#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    int n, s, t;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    vector<pair<int, int>> classes;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        classes.push_back({ s,t });
    }
    sort(classes.begin(), classes.end());

    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            answer++;
            q.push(classes[i]);
            continue;
        }

        if (classes[i].first < q.top().second) {
            q.push(classes[i]);
        }
        else {
            q.pop();
            q.push(classes[i]);
        }
    }
    cout << q.size() << endl;
    return 0;
}