#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool check(unordered_map<string,int>& m, vector<string>& want,vector<int>& number){
    for(int i=0;i<want.size();i++){
        if(m[want[i]]!=number[i])
            return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string,int> m;
    int cnt=0;
    
    for(int i=0;i<want.size();i++)
        m.insert({want[i],0});

    for(int i=0;i<10;i++)
        m[discount[i]]++;
    
    if(check(m,want,number))
        cnt++;

    for(int i=0;i<discount.size()-10;i++){
        if(m.find(discount[i])!=m.end())
            m[discount[i]]--;
        
        if(m.find(discount[i+10])!=m.end())
            m[discount[i+10]]++;   
        
        if(check(m,want,number))
            cnt++;
    }
    
    return cnt;
}