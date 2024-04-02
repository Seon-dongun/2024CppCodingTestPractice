#include <vector>
using namespace std;

long long solution(int n) {
    vector<long long> dp(n + 1, 0);
    
    dp[1] = 1; // 1 way to reach 1 square
    dp[2] = 2; // 2 ways to reach 2 squares
    
    for (int i = 3; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    
    return dp[n];
}


