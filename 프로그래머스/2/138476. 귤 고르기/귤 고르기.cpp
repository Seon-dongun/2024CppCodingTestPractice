#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> m;
    vector<int> cnt;
    
    for(int i=0;i<tangerine.size();i++)
        m[tangerine[i]]++;
       
    
    for(auto it : m)
        cnt.push_back(it.second);
    
    sort(cnt.begin(),cnt.end(),greater<int>());
    
    for(int i=0;i<cnt.size();i++){
        
        answer++;
        k-=cnt[i];
        if(k<=0)
            break;
    }

    return answer;
}