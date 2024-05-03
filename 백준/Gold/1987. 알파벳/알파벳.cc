#include <iostream>
#include <queue>
using namespace std;

char table[20][20];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int alpha[26] = { 0, };
int visited[20][20] = { 0, };
int maxV = -1;
void dfs(int n, int m, int x, int y, int dist) {
    visited[x][y] = 1;
    alpha[table[x][y] - 'A'] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && visited[nx][ny] == 0 && alpha[table[nx][ny] - 'A'] == 0) {
            dfs(n, m, nx, ny, dist + 1);
            visited[nx][ny] = 0;
            alpha[table[nx][ny] - 'A'] = 0;
        }
    }

    maxV = max(maxV, dist);
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> table[i][j];
    }
    
    dfs(n, m, 0, 0, 1);

    cout << maxV << endl;
    return 0;
}