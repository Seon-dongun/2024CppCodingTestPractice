#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int totalLength = 0;
vector<int> graph[500001];
int visited[500001] = { 0, };
void bfs() {
    queue<pair<int,int>> q;
    q.push({ 1,0 });
    visited[1] = 1;

    while (!q.empty()) {
        int num = q.front().first;
        int length = q.front().second;
        q.pop();

        for (int i = 0; i < graph[num].size(); i++) {
            int child = graph[num][i];

            if (visited[child] == 0) {
                visited[child] = 1;

                if (graph[child].size() == 1) {
                    totalLength += (length+1);
                    continue;
                }

                q.push({ child,length + 1 });
            }
        }
    }
}

int main() {
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    if (totalLength % 2 == 0)
        cout << "No";
    else
        cout << "Yes";
}