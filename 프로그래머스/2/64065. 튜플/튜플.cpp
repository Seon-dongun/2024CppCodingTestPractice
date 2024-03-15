#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size()<b.size();
}

void changeToUnion(string s, vector<vector<int>>& list){
    int k=0;
    int flag=0;
    string str = "";
    
    for(int i=1;i<s.length()-1;i++){
        if(s[i]=='{'){
            vector<int> tmp;
            list.push_back(tmp);
            flag=1;
        }
        
        else if(s[i]=='}'){
            flag=0;
            list[k].push_back(stoi(str));
            str="";
            k++;
        }
        
        else if(flag==1 && s[i]==','){
            list[k].push_back(stoi(str));
            str="";
        }   
        
        else if('0'<=s[i]&&s[i]<='9')
            str+=s[i];
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> list;
    
    changeToUnion(s,list);
    
    sort(list.begin(),list.end(),cmp);
       
    for(int i=0;i<list.size();i++){
        for(int j=0;j<list[i].size();j++){
            if(find(answer.begin(),answer.end(),list[i][j]) == answer.end())
                answer.push_back(list[i][j]);
        }     
    }
    
    return answer;
}