#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> cnt(1001,0);
    
    for(int i=0;i<weights.size();i++)
         cnt[weights[i]]++;// 무게의 갯수를 구해둔 다음, weight의 2:3,2:4,3:4 비율을 만족하는 base값을 찾아 해당 base값의 cnt값을 찾으면 weight의 비율에 따른 시소쌍의 갯수를 구할 수 있음. 또한 같은 무게가 여러 개인 경우는 조합을 추가적으로 활용하여 여러 개의 같은 무게로 만들 수 있는 시소 쌍을 구할 수 있음
    
    for(int i=0;i<weights.size();i++){
        if(weights[i]%2==0){ // weights와 쌍이 되는 base가 2:3인 경우
            long long base = weights[i]*3/2;
            if(base<=1000)
                answer += cnt[base];
            
            
        }
        
        if(weights[i]%3==0){// weights와 쌍이 되는 base가 3:4인 경우
            long long base = weights[i]*4/3;
            if(base<=1000)
                answer += cnt[base];
        }        
        int base = weights[i]*2;// weights와 쌍이 되는 base가 2:4(=1:2)인 경우
        if(base<=1000)
            answer+=cnt[base];
    }
    
    for(int i=100; i<=1000; i++) {//여러 개의 같은 수로 만들 수 있는 시소 쌍 구하기. n개 중에 2개 뽑는 경우의 수 : n(n-1) / 2
        if(cnt[i] >= 2)
            answer += (long long)(cnt[i] * (cnt[i]-1)) / 2; 
    }
    return answer;
}
