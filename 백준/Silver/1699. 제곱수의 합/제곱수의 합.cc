#include <iostream>
using namespace std;
int dp[100001];
int main() {
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        int minV = 987654321;
        for (int j = 1; j < i && j*j<=100000; j++) {
            if (j * j == i) {
                minV = 1;
                break;
            }

            if(j * j <i)
                minV = min(minV,dp[i - j * j] + dp[j * j]);
        }
        dp[i] = minV;
    }

    cout << dp[n];
    return 0;
}