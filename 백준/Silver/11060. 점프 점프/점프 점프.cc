#include <iostream>
#define INF 987654321
using namespace std;

int maze[1001];
int dp[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> maze[i];
        dp[i] = INF;
    }

    dp[1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= maze[i]; j++) {
            dp[i + j] = min(dp[i] + 1, dp[i + j]);
        }
    }

    if (dp[n] == INF) cout << -1;
    else cout << dp[n];

    return 0;
}