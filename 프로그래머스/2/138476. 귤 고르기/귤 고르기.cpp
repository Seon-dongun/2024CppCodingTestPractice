#include <string>
#include <vector>
#include <map>
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
    
    int a=0;
    for(int i=0;i<cnt.size();i++){       
        a+=cnt[i];
        answer++;
        if(a>=k)
            break;
    }

    return answer;
}
