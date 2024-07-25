#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int r, c;
char map[50][50];
int visited[50][50] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> water;
queue<pair<pair<int,int>, int>> sss;
bool flag = false;

bool bfs() {
    visited[sss.front().first.first][sss.front().first.second] = 1;

    while (!sss.empty()) {

        int ws = water.size();
        for (int i = 0; i < ws; i++) {
            int cx = water.front().first;
            int cy = water.front().second;
            water.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] == '.') {
                    map[nx][ny] = '*';
                    water.push({ nx,ny });
                }
            }
        }

        int ss = sss.size();
        for (int i = 0; i < ss; i++) {
            int cx = sss.front().first.first;
            int cy = sss.front().first.second;
            int dist = sss.front().second;
            sss.pop();

            if (map[cx][cy] == 'D') {
                cout << dist;
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != '*' && map[nx][ny]!='X' && visited[nx][ny] == 0) {
                    sss.push({ {nx,ny},dist + 1 });
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> r >> c;
    string str;
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < c; j++) {
            map[i][j] = str[j];
            if (str[j] == 'S')
                sss.push({ {i,j},0});
            else if (str[j] == '*')
                water.push({ i,j });
        }
    }

    if (bfs() == false)
        cout << "KAKTUS";
}