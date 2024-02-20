#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    
    if(enemy.size()==k)
        return k;
    
    int sum=0;
    for(int i=0;i<enemy.size();i++){    
        sum+=enemy[i];
        pq.push(enemy[i]);
        
        if(k==0 && sum>n)
          break;

        while(!pq.empty() && k!=0 && sum>n){
            k--;
            sum-=pq.top();
            pq.pop();
        }
        
        
        answer++;      
    }  
    
    return answer;
}