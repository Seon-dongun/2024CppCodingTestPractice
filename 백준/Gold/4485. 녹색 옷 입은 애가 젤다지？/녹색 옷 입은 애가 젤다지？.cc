#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(vector<vector<int>>& num, vector<vector<int>>& cost) {
    queue<pair<int, int>> q;
    cost[0][0] = num[0][0];
    q.push({ 0,0 });

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (cost[nx][ny] > cost[cx][cy] + num[nx][ny]) {
                    cost[nx][ny] = cost[cx][cy] + num[nx][ny];
                    q.push({ nx,ny });
                }
            }
        }
    }
}

int main() {
    int k = 1;
    while (1) {
        cin >> n;
        if (n==0) 
            break;

        vector<vector<int>> num(n, vector<int>(n, 0));
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> num[i][j];
        }

        bfs(num, cost);
        cout << "Problem " << k<< ": " << cost[n - 1][n - 1] << endl;
        k++;
    }
}