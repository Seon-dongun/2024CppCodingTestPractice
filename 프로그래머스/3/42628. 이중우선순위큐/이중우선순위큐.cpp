#include <string>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int>> minpq;
    int cnt=0;
    string order, num;
    for(int i=0;i<operations.size();i++){
        stringstream ss(operations[i]);
        ss >> order;
        ss >> num;
        
        if(cnt==0){
            while(!maxpq.empty()) maxpq.pop();
            while(!minpq.empty()) minpq.pop();
        }
        
        if(order=="I"){
            maxpq.push(stoi(num));
            minpq.push(stoi(num));
            cnt++;
        }
        else {
            if(cnt>0){
                if(!maxpq.empty() && num=="1"){
                    maxpq.pop();
                    cnt--;
                }
                else if(!minpq.empty() && num=="-1"){
                    minpq.pop();
                    cnt--;
                }
            }
        }    
    }
    
    if(cnt>=2){
        answer[0] = maxpq.top();
        answer[1] = minpq.top();
    }
    else if(cnt==1){
        answer[0] = maxpq.top();
        answer[1] = maxpq.top();
    }

    return answer;
}