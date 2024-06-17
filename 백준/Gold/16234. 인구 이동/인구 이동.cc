#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int answer = 0;
int N, L, R;
int map[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool flag = true;

void bfs(int i, int j,vector<vector<int>>& visited) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.push({ i,j });
    v.push_back({ i,j });
    visited[i][j] = 1;

    int sum = map[i][j];
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int gap = abs(map[cx][cy] - map[nx][ny]);
            if (0 <= nx && nx < N && 0 <= ny && ny < N && L <= gap && gap <= R && !visited[nx][ny]) {
                sum += map[nx][ny];
                visited[nx][ny] = 1;
                v.push_back({ nx,ny });
                q.push({ nx,ny });
            }
        }
    }

    if (v.size() >= 2) {
        flag = true;
        int unionDiv = sum / v.size();

        for (int i = 0; i < v.size(); i++)
            map[v[i].first][v[i].second] = unionDiv;     
    }
}

int main() {
    int r, c;
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    }

    while (flag) {
        flag = false;
        vector<vector<int>> visited(51,vector<int>(51,0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j])
                    continue;

                bfs(i, j, visited);
            }
        }

        if (flag)
            answer++;
    }
    
    cout << answer;
    return 0;
}