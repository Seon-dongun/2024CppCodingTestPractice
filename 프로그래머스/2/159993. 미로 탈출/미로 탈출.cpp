#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct Node{
    int x,y,time;
}Node;

int m,n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int x,int y, vector<string>&maps,char ch){
    vector<vector<int>> visited(m,vector<int>(n,0));
    queue<Node> q;
    
    visited[x][y] = 1;
    q.push({x,y,0});
    
    while(!q.empty()){
        int u = q.front().x;
        int v = q.front().y;
        int t = q.front().time;
        q.pop();
        
        if(maps[u][v]==ch)
            return t;
             
        for(int i=0;i<4;i++){
            int tx = u+dx[i];
            int ty = v+dy[i];
            
            if((0<=tx&&tx<m) && (0<=ty&&ty<n) && visited[tx][ty]==0&&maps[tx][ty]!='X'){
                visited[tx][ty]=1;
                q.push({tx,ty,t+1});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int startX,startY,leverX,leverY;
    m = maps.size();
    n = maps[0].length();
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(maps[i][j]=='S'){
                startX = i;
                startY = j;
            }
            
            if(maps[i][j]=='L'){
                leverX = i;
                leverY = j;
            }
        }
    }
    
    int leverTime = bfs(startX,startY,maps,'L');
    if(leverTime == -1)
        return -1;
    
    int exitTime = bfs(leverX,leverY,maps,'E');    
    if(exitTime == -1)
        return -1;
    
    return leverTime+exitTime;
}