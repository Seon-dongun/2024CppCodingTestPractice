#include <iostream>
using namespace std;

int box[1001];
int dp[1001];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> box[i];
    
    int answer = 0;
    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(box[i]>box[j])
                dp[i] = max(dp[i],dp[j]+1);
        }
        answer = max(answer,dp[i]);
    }
    cout << answer;
    return 0;
}