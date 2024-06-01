#include <iostream>
using namespace std;

int main() {
    int n, num;
    int dp[1001] = { 0, };
    int card[1001];
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> card[i];
        dp[i] = card[i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++)
            dp[i] = max(dp[i], dp[i - j] + dp[j]);
    }

    cout << dp[n];
    return 0;
}