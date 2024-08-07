#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct info {
    int x, y, kcnt, mcnt;
};

int k, w, h;
int map[200][200];
int visited[200][200][30] = {0,};
int dx1[8] = { 1,2,-1,-2,1,2,-1,-2};
int dy1[8] = { 2,1,2,1,-2,-1,-2,-1};
int dx2[4] = { 0,0,-1,1 };
int dy2[4] = { -1,1,0,0 };

void bfs() {
    queue<info> q;
    q.push({ 0,0,0,0 });
    visited[0][0][0] = 1;

    while (!q.empty()) {
        info cur = q.front();
        q.pop();

        if (cur.x == h - 1 && cur.y == w - 1) {
            cout << cur.mcnt << endl;
            return;
        }

        if (cur.kcnt < k) {
            for (int i = 0; i < 8; i++) {
                int nx = cur.x + dx1[i];
                int ny = cur.y + dy1[i];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                    continue;

                if (map[nx][ny] == 0 && visited[nx][ny][cur.kcnt + 1] == 0) {
                    q.push({ nx,ny,cur.kcnt + 1,cur.mcnt + 1 });
                    visited[nx][ny][cur.kcnt + 1] = 1;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx2[i];
            int ny = cur.y + dy2[i];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                continue;

            if (map[nx][ny] == 0 && visited[nx][ny][cur.kcnt] == 0) {
                q.push({ nx,ny,cur.kcnt,cur.mcnt + 1 });
                visited[nx][ny][cur.kcnt] = 1;
            }
        }       
    }

    cout << -1 << endl;
}

int main() {
    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }

    bfs();

    return 0;
}