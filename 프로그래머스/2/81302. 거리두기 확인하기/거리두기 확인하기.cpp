#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int dx[12] = {-1,1,0,0,-1,1,-1,1,-2,2,0,0};
int dy[12] = {0,0,-1,1,1,-1,-1,1,0,0,-2,2};
int dx2[4] = {-1,1,0,0};
int dy2[4] = {0,0,-1,1};

bool bfs(vector<string>& table, int r1,int c1, int r2, int c2){
    queue<pair<int,pair<int,int>>> q;
    int visited[5][5] = {0,};
    q.push({r1,{c1,0}});
    visited[r1][c1] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int d = q.front().second.second;
        q.pop();
        
        if(d>2)
            return false;
        
        if(x==r2 && y==c2)
            return true;
        
        for(int i=0;i<4;i++){
            int u = x + dx2[i];
            int v = y + dy2[i];
            if((0<=u&&u<=4) && (0<=v&&v<=4) && visited[u][v]==0 && table[u][v]!='X'){
                q.push({u,{v,d+1}});
                visited[u][v] = 1;
            }
        }    
    }
    
    return false;
}

int check(vector<string>& table){
    for(int i=0;i<table.size();i++){
        for(int j=0;j<table[i].length();j++){
            if(table[i][j]=='P'){
                
                for(int k=0;k<12;k++){
                    int r2 = i+dx[k];
                    int c2 = j+dy[k];
                    if((0<=r2&&r2<=4) && (0<=c2&&c2<=4) && table[r2][c2]=='P' && bfs(table,i,j,r2,c2))
                        return 0;
                }
                
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<places.size();i++)
        answer.push_back(check(places[i]));
    return answer;
}