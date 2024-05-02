#include <iostream>
using namespace std;

int dp[1001]={0,};
int find(int n){
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3;i<=n;i++)
        dp[i] = (dp[i-1] + dp[i-2])%10007;

    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << find(n) << endl;
    return 0;
}