#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int map[50][50];
int visited[50][50] = { 0, };
int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
int dy[8] = { 1,-1,0,0,-1,1,1,-1 };

void bfs(int w, int h, int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (0 <= nx && nx < h && 0 <= ny && ny < w && map[nx][ny] == 1 && visited[nx][ny] == 0) {
                q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {

    while (1) {
        int w, h, land = 0;
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;


        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j]==1 && visited[i][j] == 0) {
                    bfs(w, h, i, j);
                    land++;;
                }
            }
        }
        cout << land << endl;
    }
}