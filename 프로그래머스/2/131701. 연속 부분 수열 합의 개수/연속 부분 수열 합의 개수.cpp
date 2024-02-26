#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> s;
    int div = elements.size();
    vector<vector<int>> dp(elements.size(),vector<int>(elements.size(),0));
    
    for(int i=0;i<elements.size();i++){
        dp[i][i] = elements[i];
        s.insert(dp[i][i]);
    }
       
    for(int i=0;i<elements.size();i++){ 
        for(int j=i;j<i+div;j++){
            dp[i][j%div] = dp[i][(j-1)%div] + elements[j%div];
            s.insert(dp[i][j%div]);
        }        
    }
    
    return s.size(); 
}