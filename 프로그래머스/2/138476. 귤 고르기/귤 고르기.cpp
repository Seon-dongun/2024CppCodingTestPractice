#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    multiset<int> m;
    vector<int> cnt(10000001,0);
    
    for(int i=0;i<tangerine.size();i++)
        cnt[tangerine[i]]++;
       
    
    for(int i=1;i<=10000000;i++){
        if(cnt[i]!=0){
            m.insert(cnt[i]);
        }
    }
    
    int a = 0;
    for(auto it=m.rbegin();it!=m.rend();it++){
        
        if(a>=k)
            break;
        answer++;
        a+=*it;
    }

    return answer;
}