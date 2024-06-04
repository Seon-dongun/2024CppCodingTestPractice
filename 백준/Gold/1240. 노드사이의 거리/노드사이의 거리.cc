#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int value[1001];
int n, m;
vector<pair<int, int>> graph[1001];

int calDist(int s, int e) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
        value[i] = 987654321;

    pq.push({ 0,s });
    value[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (value[u] + w < value[v]) {
                value[v] = value[u] + w;
                pq.push({ value[v],v });
            }
        }
    }

    return value[e];
}

int main() {
    int u, v, dist, s, e;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> dist;
        graph[u].push_back({ v,dist });
        graph[v].push_back({ u,dist });
    }

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << calDist(s, e) << endl;
    }
}