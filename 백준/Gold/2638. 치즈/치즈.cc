#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int map[100][100];
int visited[100][100] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<pair<int, int>> meltLocation;

bool isMelt(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny]==2)
            cnt++;
    }
    if (cnt >= 2)
        return true;
    else
        return false;
}

void melt() {
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visited[0][0] = 1;
    map[0][0] = 2;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (map[nx][ny] == 0 && visited[nx][ny] == 0) {
                    q.push({ nx,ny });
                    visited[nx][ny] = 1;
                    map[nx][ny] = 2;
                }
                else if (map[nx][ny] == 2 && visited[nx][ny] == 0) {
                    q.push({ nx,ny });
                    visited[nx][ny] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                if (isMelt(i, j)) {
                    meltLocation.push_back({ i,j });
                    visited[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < meltLocation.size(); i++)
        map[meltLocation[i].first][meltLocation[i].second] = 2;
}

bool isAllMelt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1)
                return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    int t = 0;
    while (1) {
        if (isAllMelt() == true) {
            cout << t;
            break;
        }

        memset(visited, 0, sizeof(visited));
        melt();
        t++;
    }
}