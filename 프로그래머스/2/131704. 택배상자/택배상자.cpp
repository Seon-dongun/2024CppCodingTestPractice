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
                int front = mc.front();
                mc.pop();
                
                if(front==order[i]){
                    answer++;
                    break;
                }       
                sub.push(front);  
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

--------------------------------------------------------------------------------------------------
// 또 다른 좋은 풀이
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    
    for (int i=1; i<=order.size(); i++) {
        s.push(i);
        
        while (!s.empty() && s.top() == order[answer]) {
            s.pop();
            answer++;
        }
    }  
    return answer;
}
