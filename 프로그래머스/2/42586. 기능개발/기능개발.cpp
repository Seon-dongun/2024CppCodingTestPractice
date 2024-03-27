#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> finished;
    
    for(int i=0;i<progresses.size();i++){     
        finished.push(ceil((100 - progresses[i]) / (float)(speeds[i])));
    }
    
    int start = finished.front();
    int cnt = 1;
    finished.pop();
    while(!finished.empty()){
        if(start>=finished.front())
            cnt++;
        else{
            answer.push_back(cnt);
            start = finished.front();
            cnt = 1;        
        }
        finished.pop();
    }
    answer.push_back(cnt);
    
    return answer;
}
