#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second>b.second;
}

void count(string s, vector<pair<int,int>>& mapSorting){
    int k=0;
    int flag=0;
    string str = "";
    map<int,int> m;
    
    for(int i=1;i<s.length()-1;i++){
        if(s[i]=='{'){
            flag=1;
        }
        
        else if(s[i]=='}'){
            int result = stoi(str);
            flag=0;
            if(m.find(result)==m.end())
                m.insert({result,1});
            else
                m[result]++;
            str="";
        }
        
        else if(flag==1 && s[i]==','){
            int result = stoi(str);
            
            if(m.find(result)==m.end())
                m.insert({result,1});
            else
                m[result]++;
            str="";
        }   
        
        else if('0'<=s[i]&&s[i]<='9')
            str+=s[i];
    }
    
    for(auto& tmp : m)
        mapSorting.push_back(tmp);
    
    sort(mapSorting.begin(),mapSorting.end(),cmp);
    
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int,int>> mapSorting;

    count(s,mapSorting);
       
    for(int i=0;i<mapSorting.size();i++)
        answer.push_back(mapSorting[i].first);
    
    return answer;
}
