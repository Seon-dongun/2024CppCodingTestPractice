#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> answer;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int m,int n,int x, int y, vector<vector<int>>& board) {
    int value = 0;
    board[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({ x,y });


    while (!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        value++;

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if ((0 <= nx && nx < m) && (0 <= ny && ny < n) && board[nx][ny] == 0) {
                q.push({ nx,ny });
                board[nx][ny] = 1;
            }
        }
    }
    answer.push_back(value);

}

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> board(m, vector<int>(n, 0));


    for (int i = 0; i < k; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for (int a = lx; a < rx; a++) {
            for (int b = ly; b < ry; b++)
                board[b][a] = 1;
        }
    }


    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0)
                bfs(m,n,i, j,board);
        }
    }

    cout << answer.size() << endl;
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    return 0;
}