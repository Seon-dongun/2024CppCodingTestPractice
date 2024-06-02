#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[502][502];
int visited[502][502];
int answer = 0;
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x, int y, int cnt, int sum) {
    if (cnt == 4) {
        answer = max(answer, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m && visited[nx][ny]==0) {
            visited[nx][ny] = 1;
            dfs(x + dx[i], y + dy[i], cnt + 1, sum + board[nx][ny]);
            visited[nx][ny] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = 1;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tmp = board[i][j] + board[i - 1][j] + board[i + 1][j] + board[i][j - 1] + board[i][j + 1];
            tmp -= min({ board[i - 1][j],board[i + 1][j],board[i][j - 1],board[i][j + 1] });
            answer = max(answer, tmp);
        }
    }

    cout << answer;
    return 0;
}