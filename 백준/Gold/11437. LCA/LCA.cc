#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[50001];
int parent[50001];
int visited[50001] = { 0, };
int depth[50001];

void checkParent() {
    queue<int> q;
    visited[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for (int i = 0; i < graph[n].size(); i++) {
            if (!visited[graph[n][i]]) {
                visited[graph[n][i]] = 1;
                parent[graph[n][i]] = n;
                depth[graph[n][i]] = depth[n] + 1;
                q.push(graph[n][i]);
            }
        }
    }
}

void LCA(int a, int b) {
    while (depth[a] != depth[b]){
        if (depth[a] > depth[b])
            a = parent[a];
        else
            b = parent[b];
    }

    while (a != b){
        a = parent[a];
        b = parent[b];
    }

    cout << a << endl;
}

int main() {
    int n, m, u, v, a, b;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    parent[1] = -1;
    checkParent();

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        LCA(a, b);
    }

    return 0;
}