#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999
#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n = 0;
int minDest = INF; 
int cost_4Dir[25][25][4];

void DFS(vector<vector<int>>& board, int y, int x, int curCost, int dir) {
    if (minDest < curCost)
        return;

    if (y == n - 1 && x == n - 1) {
        minDest = min(curCost, minDest);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || board[nextY][nextX] == 1)
            continue;

        int nextCost = curCost + 100;
        if (dir == UP || dir == DOWN)
            if (i == LEFT || i == RIGHT)
                nextCost += 500;
        if (dir == LEFT || dir == RIGHT)
            if (i == UP || i == DOWN)
                nextCost += 500;

        if (cost_4Dir[nextY][nextX][i] > nextCost) {
            cost_4Dir[nextY][nextX][i] = nextCost;
            DFS(board, nextY, nextX, nextCost, i);  // 바로 방문하러 ㄱㄱ
        }  
    }
}

int solution(vector<vector<int>> board) {
    n = board.size();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 4; ++k)
                cost_4Dir[i][j][k] = INF;

    DFS(board, 0, 0, 0, -1);

    return minDest;
}