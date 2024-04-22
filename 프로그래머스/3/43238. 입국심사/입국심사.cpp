#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long s = 1, e = (*max_element(times.begin(),times.end()))*(long long)n;
    long long answer = e;
    
    while(s<=e){
        long long mid = (s+e)/2;
        long long cnt = 0;
        for(int i=0;i<times.size();i++)
            cnt += mid/times[i];
        
        if(cnt>=n){
            e = mid -1;
            answer = min(answer,mid);
        }
        else
            s = mid+1;
    }
    
    return answer;
}