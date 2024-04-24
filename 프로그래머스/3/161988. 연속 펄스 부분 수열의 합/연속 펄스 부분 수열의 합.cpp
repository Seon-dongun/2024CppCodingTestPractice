#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long maxV1, maxV2;
    long long dp[500001];
    for(int i=0;i<sequence.size();i++){
        if(i%2==1)
            sequence[i]*=-1;
    }
    
    dp[0] = sequence[0];
    maxV1 = dp[0];
    for(int i=1;i<sequence.size();i++){
        dp[i] = max((long long)sequence[i],dp[i-1] + (long long)sequence[i]);
        if(maxV1<dp[i])
            maxV1= dp[i];
    }
    

    for(int i=0;i<sequence.size();i++)
        sequence[i]*=-1;

    dp[0]  = sequence[0];
    maxV2 = dp[0];
    for(int i=1;i<sequence.size();i++){
        dp[i] = max((long long)sequence[i],dp[i-1] + (long long)sequence[i]);
        if(maxV2<dp[i])
            maxV2 = dp[i];
    }
    
    return max(maxV1,maxV2);
}