#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dfs(int i,int j,vector<vector<int>>& land,vector<vector<int>>& visited,int& maxIdx,int& minIdx){
    if(i<0 || i>=land.size() || j<0 || j>=land[0].size()||land[i][j]==0||visited[i][j]==1)
        return 0;
    
    visited[i][j]=1;
    
    if(maxIdx<j)
        maxIdx = j;
    if(minIdx>j)
        minIdx = j;

    
    return 1 + dfs(i-1,j,land,visited,maxIdx,minIdx) + dfs(i+1,j,land,visited,maxIdx,minIdx) + dfs(i,j-1,land,visited,maxIdx,minIdx) + dfs(i,j+1,land,visited,maxIdx,minIdx);
}

int solution(vector<vector<int>> land) {
    int answer = 0,oilSize;
    
    vector<int> locationValue(land[0].size(),0);
    vector<vector<int>> visited(land.size(),vector<int>(land[0].size(),0));    

    for(int i=0;i<land[0].size();i++){
        for(int j=0;j<land.size();j++){
            if(land[j][i]==0||visited[j][i]==1){
                continue;
            }
            
            int maxIdx=-1,minIdx=1000;
            
            
            oilSize = dfs(j,i,land,visited,maxIdx,minIdx);

            
            for(int i=minIdx;i<=maxIdx;i++){
                locationValue[i]+=oilSize;
            }

        }
    } 
    
    answer = *max_element(locationValue.begin(),locationValue.end()); 
    return answer;
}