#include <iostream>
using namespace std;

int main() {
    int dp[1001], num[1001];
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> num[i];
    
    int answer = 0;
    for(int i = 1; i<= n; i++) {
        dp[i] = num[i];
        for(int j = 1; j <i;j++) {
            if(num[i] > num[j] && dp[i] < dp[j] +num[i])
                dp[i] = dp[j] + num[i];
        }
        answer = max(answer,dp[i]);
    }
    cout << answer << endl;
    return 0;
}