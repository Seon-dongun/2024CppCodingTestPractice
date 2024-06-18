#include <iostream>
using namespace std;
int dp[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for(int i=0; i<=n; i++) 
        dp[i] = i;
    
    for(int i=1; i<=n; i++){
        for(int j = 1; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
            // dp[i-j*j]+1에서 +1은 j*j로 만들어지는 제곱수는 무조건 1개의 항이기 때문에 1임.
        }
    }

    cout << dp[n];
    return 0;
}
