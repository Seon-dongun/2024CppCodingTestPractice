#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int map[100][100];
int visited[100][100] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> lands[10001];

bool isSide(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && map[nx][ny] == 0)
            return true;
    }
    return false;
}

void bfs(int x, int y, int landNum) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;
    if(isSide(x,y))
        lands[landNum].push_back({ x,y });

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && map[nx][ny] >= 1 && visited[nx][ny] == 0) {
                q.push({ nx,ny });
                visited[nx][ny] = 1;

                if(isSide(nx,ny))
                    lands[landNum].push_back({ nx,ny });
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int landNum = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0)
                bfs(i, j, landNum++);
        }
    }
   

    int minDist = 999999999;
    for (int i = 1; i < landNum; i++) {
        for (int j = 1; j < landNum; j++) {
            if (i == j)
                continue;

            for (int k = 0; k < lands[i].size(); k++) {
                for (int l = 0; l < lands[j].size(); l++) {
                    minDist = min(minDist, abs(lands[i][k].first - lands[j][l].first) + abs(lands[i][k].second - lands[j][l].second));
                }
            }
        }
    }
    
    cout << minDist-1;
}