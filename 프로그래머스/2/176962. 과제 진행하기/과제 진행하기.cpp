#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;

string change(string a){
    stringstream ss(a);
    int hour,min;
    char colon;
    ss >> hour >> colon >> min;
    return to_string((hour*60)+min);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(),plans.end(), [&](vector<string>& a, vector<string>& b){
        return a[1] < b[1];
    }); 
    
    for(int i=0;i<plans.size();i++)
        plans[i][1] = change(plans[i][1]);
    
        
    int time = stoi(plans[0][1]);
    stack<pair<int,int>> stop;
    
    for(int i=0;i<plans.size()-1;i++){
        int tmp = stoi(plans[i][1])+stoi(plans[i][2]);
        
        if(tmp >stoi(plans[i+1][1])){
            stop.push({i,stoi(plans[i][2])-(stoi(plans[i+1][1])-stoi(plans[i][1]))});
            time = stoi(plans[i+1][1]);
        }
        else{
            answer.push_back(plans[i][0]);
            time = stoi(plans[i][1])+stoi(plans[i][2]);
            
            while(time<stoi(plans[i+1][1])&&!stop.empty()){
                pair<int,int> s = stop.top();

                if(time+s.second>stoi(plans[i+1][1])){
                    stop.pop();
                    stop.push({s.first, s.second - (stoi(plans[i+1][1]) - time)});
                    time = stoi(plans[i+1][1]);                    
                    break;
                }
                else{
                    time += s.second;
                    stop.pop();
                    answer.push_back(plans[s.first][0]);
                }
            }
        } 
    } 
    
    answer.push_back(plans[plans.size()-1][0]);
    time += stoi(plans[plans.size()-1][2]);

    while(!stop.empty()){
        answer.push_back(plans[stop.top().first][0]);
        stop.pop();
    }                   
    
    return answer;
}
