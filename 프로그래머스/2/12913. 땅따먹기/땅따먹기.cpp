#include <iostream>
#include <vector>
using namespace std;

int dp[100000][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();

    for(int i=0;i<4;i++)
        dp[0][i] = land[0][i];
    
    for(int i=1;i<n;i++){
        for(int j=0;j<4;j++){
            int max = 0;
            for(int k=0;k<4;k++){
                if(j==k)
                    continue;
                
                if(max < land[i][j] + dp[i-1][k])
                    max = land[i][j] + dp[i-1][k];             
            }
            dp[i][j] = max;
        }
    }
    
    for(int i=0;i<4;i++){
        if(answer<dp[n-1][i])
            answer = dp[n-1][i];
    }

    return answer;
}