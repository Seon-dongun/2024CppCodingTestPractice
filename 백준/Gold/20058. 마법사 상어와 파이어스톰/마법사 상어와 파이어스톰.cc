#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int map[64][64];
int minimap[64][64];
int visited[64][64] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, Q, mapSize;
vector<int> infoL;

void init() {
    cin >> N >> Q;
    mapSize = pow(2, N);
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < Q; i++) {
        int l;
        cin >> l;
        infoL.push_back(l);
    }
}

int remainIceTotal() {
    int total = 0;
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++)
            total += map[i][j];
    }
    return total;
}

int bfs(int x, int y) {
    int iceSize = 1;
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= mapSize || ny >= mapSize || nx < 0 || ny < 0 || map[nx][ny]==0 || visited[nx][ny])
                continue;

            visited[nx][ny] = 1;
            q.push({ nx,ny });
            iceSize++;
        }
    }
    return iceSize;
}

int findLargeIce() {
    int maxIceSize = 0;

    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            if (map[i][j] == 0) 
                continue;
            
            if (!visited[i][j])
                maxIceSize = max(maxIceSize, bfs(i, j));
        }
    }
    return maxIceSize;
}

void roundMinimap(int x, int y,int minimapSize) {
    for (int i = 0; i < minimapSize; i++) {
        for (int j = 0; j < minimapSize; j++)
            minimap[j][minimapSize - 1 - i] = map[x+i][y+j];
    }

    for (int i = x; i < x + minimapSize; i++) {
        for (int j = y; j < y + minimapSize; j++)
            map[i][j] = minimap[i-x][j-y];
    }
}

void moveMap(int l) {
    int minimapSize = pow(2,l)  ;
    for (int i = 0; i < mapSize; i+=minimapSize) {
        for (int j = 0; j < mapSize; j+=minimapSize)
            roundMinimap(i, j, minimapSize);
    }
}

void reduceIce() {
    vector<pair<int, int>> v;
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            
            if (map[i][j] == 0)
                continue;

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= mapSize || ny >= mapSize || nx < 0 || ny < 0)
                    continue;

                if (map[nx][ny] != 0)
                    cnt++;
            }

            if (cnt < 3)
                v.push_back({ i,j });
        }
    }

    for (int i = 0; i < v.size(); i++)
        map[v[i].first][v[i].second]--;
}

int main() {
    init();
    for (int i = 0; i < infoL.size(); i++) {
        moveMap(infoL[i]);
        reduceIce();
    }

    cout << remainIceTotal() << endl;
    cout << findLargeIce() << endl;
    return 0;
}