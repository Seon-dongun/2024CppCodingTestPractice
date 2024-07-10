#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, t = 0;
int map[300][300];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool allMelt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != 0)
                return false;
        }
    }
    return true;
}


void bfs(int x, int y, vector<vector<int>>& visited) {
    if (visited[x][y] == 1)
        return;
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push({ x,y });

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny]!= 0 && visited[nx][ny] == 0) {
                q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    vector<pair<pair<int, int>, int>> check;
    while (1) {
        t++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0)
                    continue;
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m && map[ni][nj] == 0)
                        cnt++;
                }
                check.push_back({ {i,j},cnt });
            }
        }

        for (int i = 0; i < check.size(); i++) {
            int ci = check[i].first.first;
            int cj = check[i].first.second;
            int cnt = check[i].second;
            map[ci][cj] -= cnt;
            if (map[ci][cj] < 0)
                map[ci][cj] = 0;
        }




        int iceCnt = 0;
        vector<vector<int>> visited(300, vector<int>(300, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0 || visited[i][j]==1)
                    continue;
                bfs(i, j, visited);
                iceCnt++;
            }
        }
        if (iceCnt >= 2) {
            cout << t;
            break;
        }

        if (allMelt()) {
            cout << 0;
            break;
        }

        check.clear();
    }

}