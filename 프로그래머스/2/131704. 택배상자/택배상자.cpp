#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> sub;
    queue<int> mc;

    for(int i=1;i<=order.size();i++)
        mc.push(i);
 
    for(int i=0;i<order.size();i++){ 
        if(!mc.empty() && mc.front()<=order[i]){         
            while(1){
                if(mc.front()==order[i]){
                    answer++;
                    mc.pop();
                    break;
                }       
                sub.push(mc.front());
                mc.pop();    
            }
        }
        
        else if(!sub.empty() && sub.top()==order[i]){
            sub.pop();
            answer++;
        }
        else
            break;
    }
    
    return answer;
}