#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

string solution(string s) {
    string answer = "";
    priority_queue<int,vector<int>,greater<int>> pq;
    stringstream ss(s);
    
    string num;
    while(ss>>num)
        pq.push(stoi(num));
    
    answer+=to_string(pq.top());
    answer+=" ";
    
    int tmp = 0;
    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
    }
    answer+=to_string(tmp);
    
    return answer;
}
