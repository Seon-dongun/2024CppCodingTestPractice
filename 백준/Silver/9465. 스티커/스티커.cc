#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[3][100001];
int dp[3][100001];

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= n; j++)
                cin >> map[i][j];
        }

        dp[1][1] = map[1][1];
        dp[2][1] = map[2][1];
        dp[1][2] = map[1][2] + dp[2][1];
        dp[2][2] = map[2][2] + dp[1][1];

        for (int j = 3; j <= n; j++) {
            dp[1][j] = map[1][j] + max(dp[2][j - 1], dp[2][j - 2]);
            dp[2][j] = map[2][j] + max(dp[1][j - 2], dp[1][j - 1]);
        }

        cout << max(dp[1][n], dp[2][n]) << endl;
    }
}
