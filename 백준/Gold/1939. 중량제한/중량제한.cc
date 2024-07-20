#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int>> graph[100001];
int visited[100001];
bool bfs(int curCost,int s,int e) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == e)
            return true;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int cost = graph[u][i].second;

            if (visited[v] == 0 && curCost <= cost) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    return false;
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    int maxCost = -1;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
        maxCost = max(maxCost, c);
    }
    int fac1, fac2;
    cin >> fac1 >> fac2;

    int low = 0, high = maxCost;
    while (low <= high) {
        memset(visited, 0, sizeof(visited));
        int mid = (low + high) / 2;
        if (bfs(mid,fac1,fac2))
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << high;    
}