#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    vector<int> visited(cards.size(),0);
    vector<int> g1,ans;
    
    for(int i=0;i<cards.size();i++){
        if(visited[i]==1)
            continue;
        
        int idx = i;
        while(visited[idx]!=1){
            visited[idx] = 1;
            g1.push_back(cards[idx]-1);
            idx = cards[idx]-1;
        }
        
        ans.push_back(g1.size());
        g1.clear();
    }
    
    sort(ans.begin(),ans.end(),greater());
    return ans[0]*ans[1];
}