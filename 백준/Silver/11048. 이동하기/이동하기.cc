#include <iostream>
using namespace std;

int n, m;
int maze[1001][1001];
int dp[1001][1001] = { 0, };

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> maze[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int maxV = max(dp[i-1][j], max(dp[i][j-1],dp[i-1][j-1]));
            dp[i][j] = maxV + maze[i][j];
        }
    }

    cout << dp[n][m];
}