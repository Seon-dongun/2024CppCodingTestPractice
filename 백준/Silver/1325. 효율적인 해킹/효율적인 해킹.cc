#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

vector<int> graph[10001];
int visited[10001] = { 0, };

set<int> answer;

int maxCnt = -1;
void check(int id){     
    int cnt = 1;
    queue<int> q;
    visited[id] = 1;
    q.push(id);

    while (!q.empty()) {
        int cid = q.front();
        q.pop();

        for (int i = 0; i < graph[cid].size(); i++) {
            int nid = graph[cid][i];
            if (visited[nid] == 0) {
                visited[nid] = 1;
                q.push(nid);
                cnt++;
            }
        }
    }

    if (cnt > maxCnt) {
        maxCnt = cnt;
        answer.clear();
    }

    if(cnt==maxCnt)
        answer.insert(id);
}


int main() {
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        check(i);
    }

    for (auto& tmp : answer)
        cout << tmp << " ";
    return 0;
}
