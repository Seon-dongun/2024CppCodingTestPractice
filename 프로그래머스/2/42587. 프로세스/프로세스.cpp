#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;  // {우선순위, 인덱스}
    priority_queue<int> pq(priorities.begin(), priorities.end());
    
    for(int i = 0; i < priorities.size(); i++)
        q.push({priorities[i], i});
    
    while(!q.empty()){
        int curPriority = q.front().first;
        int curIndex = q.front().second;
        q.pop();
        
        if(curPriority < pq.top())
            q.push({curPriority, curIndex});
        else{
            pq.pop();
            answer++;
            if(curIndex == location)
                break;
        }
    }    
    return answer;
}
