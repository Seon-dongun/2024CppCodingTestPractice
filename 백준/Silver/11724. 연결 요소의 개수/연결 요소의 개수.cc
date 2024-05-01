#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[1000];

void dfs(int idx, vector<int>& visited) {
    if (visited[idx])
        return;

    visited[idx] = 1;
    for (int i = 0; i < graph[idx].size(); i++) {
        if (!visited[graph[idx][i]]) {
            dfs(graph[idx][i], visited);
        }
    }
}

bool check(vector<int>& visited) {
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v, cnt = 1;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        dfs(i, visited);

        if (check(visited))
            break;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}