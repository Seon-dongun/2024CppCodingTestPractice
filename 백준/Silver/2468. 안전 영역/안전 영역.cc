#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
int height[100][100];
int answer = 0;

void bfs(int n, int x, int y, int (&visited)[100][100]) {
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    queue<pair<int, int>> q;

    q.push({ x,y });
    visited[x][y] = 1;
    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = tmp.first + dx[i];
            int ny = tmp.second + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < n && visited[nx][ny] == 0) {
                q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    int n;
    unordered_set<int> s;
    cin >> n;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> height[i][j];
            s.insert(height[i][j]);
        }
    }

    for (auto i : s) {
        int cnt = 0;
        int visited[100][100] = { 0, };
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (height[j][k] <= i)
                    visited[j][k] = 1;
            }
        }
 
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (visited[j][k] == 0) {
                    bfs(n, j, k, visited);
                    cnt++;
                }
            }         
        }
        answer = max(answer, cnt);
    }

    cout << answer << endl;
    return 0;
}