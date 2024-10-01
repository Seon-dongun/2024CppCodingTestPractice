#include <string>
#include <vector>

using namespace std;

int dp[1000010];
int dp2[1000010];

int solution(vector<int> money) {
    int n = money.size()-1;
    
    // 0번 집을 터는 경우
    dp[0] = money[0];
    dp[1] = dp[0];
    for(int i=2;i<n;i++)
        dp[i] = max(dp[i-2] + money[i], dp[i-1]);
    
    // 0번 집을 안터는 경우
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i=2;i<=n;i++)
        dp2[i] = max(dp2[i-2] + money[i],dp2[i-1]);
     
    return max(dp[n-1],dp2[n]);
}