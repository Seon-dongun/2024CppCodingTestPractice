#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n;
char map[100][100];
int visited[100][100] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs(int x, int y,char ch) {
    queue<pair<int, int>> q;
    q.push({ x,y });

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && map[nx][ny] == ch && visited[nx][ny] == 0) {
                q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    int color, cnt=0;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++)
            map[i][j] = str[j];
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0) {
                bfs(i, j,map[i][j]);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
    memset(visited, 0, sizeof(visited));
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'R' || map[i][j] == 'G')
                map[i][j] = 'A';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0) {
                bfs(i, j,map[i][j]);
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}