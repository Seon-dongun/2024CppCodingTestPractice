#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
vector<pair<int, int>> v;

void bfs(int x, int y, int(&area)[8][8]) {
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int visited[8][8] = { 0, };
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = nx + dx[i];
            int ty = ny + dy[i];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && area[tx][ty] == 0 && visited[tx][ty] == 0) {
                area[tx][ty] = 2;
                q.push({ tx,ty });
            }
        }
    }
}

int check(int a, int b, int c, int area[8][8]) {
    int tempArea[8][8];
    memcpy(tempArea, area, sizeof(int)*8*8);
    tempArea[v[a].first][v[a].second] = 1;
    tempArea[v[b].first][v[b].second] = 1;
    tempArea[v[c].first][v[c].second] = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tempArea[i][j] == 2)
                bfs(i, j, tempArea);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tempArea[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

int main() {
    int area[8][8];
    int answer = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> area[i][j];
            if (area[i][j] == 0)
                v.push_back({ i,j });
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) {
            for (int k = j+1; k < v.size(); k++)
                answer = max(answer, check(i, j, k, area));
        }
    }
    cout << answer << endl;
    return 0;
}