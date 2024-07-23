#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int f, s, g, u, d;
int visited[1000001] = { 0, };

void moveU(queue<pair<int, int>>& q, int cur, int cnt) {
    if (cur + u <= f&& visited[cur + u] == 0) {
        visited[cur + u] = 1;
        q.push({ cur + u,cnt + 1 });
    }
}

void moveD(queue<pair<int, int>>& q, int cur, int cnt) {
    if (cur - d >= 1 && visited[cur - d] == 0) {
        visited[cur - d] = 1;
        q.push({ cur - d,cnt + 1 });
    }
}

void start() {
    queue<pair<int, int>> q;
    q.push({ s,0 });
    visited[s] = 1;
    while (!q.empty()) {
        int curLoc = q.front().first;
        int curCnt = q.front().second;
        q.pop();

        if (curLoc == g) {
            cout << curCnt;
            return;
        }

        moveU(q, curLoc, curCnt);
        moveD(q, curLoc, curCnt);
    }

    cout << "use the stairs";
}
int main() {
    cin >> f >> s >> g >> u >> d;

    start();

    return 0;
}