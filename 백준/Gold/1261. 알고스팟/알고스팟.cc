#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define INF 987654321
using namespace std;

int maze[101][101];
int breakCnt[101][101];
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs() {
    queue<pair<int, int>> q;
    q.push({ 1,1 });
    breakCnt[1][1] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {            
                if (maze[nx][ny] == 1) {
                    if (breakCnt[nx][ny] > breakCnt[x][y] + 1) {
                        breakCnt[nx][ny] = breakCnt[x][y] + 1;
                        q.push({ nx,ny });
                    }
                }
                
                else if (maze[nx][ny] == 0) {
                    if (breakCnt[nx][ny] > breakCnt[x][y]) {
                        breakCnt[nx][ny] = breakCnt[x][y];
                        q.push({ nx,ny });
                    }
                }               
            }
        }
    }
}

int main() {
    cin >> m >> n;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 1; j <= m; j++) {
            maze[i][j] = str[j-1] - '0';
            breakCnt[i][j] = INF;
        }
    }

    bfs();

    cout << breakCnt[n][m];
    return 0;
}