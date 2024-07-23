#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
vector<int> graph[2000];
int visited[2000] = { 0, };
bool flag=false;
void dfs(int id,int cnt) {
    if (flag == true)
        return;

    if (cnt == 4) {
        flag = true;
        return;
    }

    for (int i = 0; i < graph[id].size(); i++) {
        if (visited[graph[id][i]] == 1)
            continue;
        visited[graph[id][i]] = 1;
        dfs(graph[id][i], cnt + 1);
        visited[graph[id][i]] = 0;
    }
    

}

int main() {
    int a, b;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if (m < 4) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        dfs(i,0);
    }

    if (flag)
        cout << 1;
    else
        cout << 0;
}