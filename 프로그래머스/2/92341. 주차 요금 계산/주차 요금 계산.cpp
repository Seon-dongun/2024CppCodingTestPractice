#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <sstream>
#include <iostream>
using namespace std;

int timeCal(string inTime, string outTime){
    int inH = stoi(inTime.substr(0,2));
    int inM = stoi(inTime.substr(3));
    int outH = stoi(outTime.substr(0,2));
    int outM = stoi(outTime.substr(3));
    if(outM-inM<0){
        outH--;
        outM+=60;
    }
    
    return (outH-inH) * 60 + outM-inM;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, stack<string>> m;
    map<string, int> charge;
    
    for(int i=0;i<records.size();i++){
        stringstream ss(records[i]);
        string timeLog, num, inout;
        ss>>timeLog;
        ss>>num;
        ss>>inout;

        if(m.find(num)==m.end()){
            stack<string> tmp;
            m.insert({num,tmp});
            m[num].push(timeLog);
        }
        else if(m[num].empty())
            m[num].push(timeLog);
        else{
            string outTime = timeLog;
            string inTime = m[num].top();
            m[num].pop();
            charge[num]+=timeCal(inTime,outTime);        
        }
    }
    for(auto &tmp : m){
        if(!tmp.second.empty())
          charge[tmp.first]+=timeCal(tmp.second.top(),"23:59");
    }
    
    for(auto &tmp : charge){
        if(tmp.second<=fees[0])
            answer.push_back(fees[1]);
        else
            answer.push_back(fees[1]+ceil((float)(tmp.second - fees[0])/fees[2])*fees[3]);
    }
    
    return answer;
}