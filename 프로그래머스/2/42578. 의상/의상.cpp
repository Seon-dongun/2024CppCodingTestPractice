#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> m;
    int answer = 1;
    for(int i=0;i<clothes.size();i++)
        m[clothes[i][1]]++;
    
    for(auto p:m)
        answer*=(p.second+1);
    
    return answer-1;
}