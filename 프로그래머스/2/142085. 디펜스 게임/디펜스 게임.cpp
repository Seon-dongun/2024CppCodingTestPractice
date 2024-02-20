#include <string>
#include <vector>
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
        
        if(k==0 && sum>n) // 무적권을 모두 소모한 상태에서 막을 수 있는 한도를 넘었을 때
          break;

        while(!pq.empty() && k!=0 && sum>n){ // 무적권이 남은 상태에서 막을 수 있는 한도를 넘었을 때. 한도 이내로 들어올 때까지 무적권을 최대한 소모하여 처리한다.
            k--;
            sum-=pq.top();
            pq.pop();
        }          
        answer++;      
    }     
    
    return answer;
}
