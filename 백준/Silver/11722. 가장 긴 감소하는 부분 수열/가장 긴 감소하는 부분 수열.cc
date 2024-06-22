#include <iostream>
using namespace std;
int num[1000];
int dp[1000];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> num[i];
    
    int answer = 0;
    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(num[i]<num[j])
                dp[i] = max(dp[j]+1,dp[i]);
        }
        answer = max(answer,dp[i]);
    }
    cout << answer;
    return 0;
}