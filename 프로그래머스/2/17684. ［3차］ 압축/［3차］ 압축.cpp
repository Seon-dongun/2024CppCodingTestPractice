#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string,int> m;
    
    for(int i=1;i<=26;i++){
        string tmp = "";
        tmp+='A'+i-1;
        m[tmp] = i;
    }
    
    int i=0,j=0;
    string str = "";
    int lastIndex;
    while(i<msg.length()){
        str+=msg[j];
        if(m.find(str)!=m.end()){ 
            lastIndex = m[str];
            j++;
        }
        else{
            m[str] = m.size()+1;
            answer.push_back(lastIndex);
            i+=(j-i);
            j=i;
            str="";
        }
    }
    
    return answer;
}