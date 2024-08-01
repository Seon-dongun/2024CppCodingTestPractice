#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char map[1000][1000];
int firemap[1000][1000];
int visited[1000][1000] = { 0, };
int r, c;
pair<int, int> jloc;
queue<pair<int, int>> fireQ;

void movePerson() {
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0,{jloc.first,jloc.second} });
    visited[jloc.first][jloc.second] = 1;

    while (!q.empty()) {
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        int dist = q.front().first;
        q.pop();

        if (cx == r - 1 || cy == c - 1 || cx==0 || cy==0) {
            cout << dist+1 << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            
            if (0 <= nx && nx < r && 0 <= ny && ny < c) {
                if (map[nx][ny] != '#' && visited[nx][ny] == 0) {
                    if (firemap[nx][ny] > dist + 1) {
                        visited[nx][ny] = 1;
                        q.push({ dist + 1,{nx,ny} });
                    }
                }
            }
        }       
    }

    cout << "IMPOSSIBLE" << endl;
    return;
}

void makeFireMap() {
    while (!fireQ.empty()) {
        int cir = fireQ.size();
        for(int s=0;s<cir;s++){
            int x = fireQ.front().first;
            int y = fireQ.front().second;
            fireQ.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx && nx < r && 0 <= ny && ny < c) {
                    if (map[nx][ny] != '#') {
                        if (firemap[nx][ny] > firemap[x][y] + 1) {
                            firemap[nx][ny] = firemap[x][y] + 1;
                            fireQ.push({ nx,ny });
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            bool fire = false;
            cin >> map[i][j];
            if (map[i][j] == 'J')
                jloc = { i,j };

            else if (map[i][j] == 'F') {
                fireQ.push({ i,j });
                firemap[i][j] = 0;
                fire = true;
            }

            if (fire == false)
                firemap[i][j] = INF;
        }
    }

    makeFireMap();
    movePerson();
    return 0;
}