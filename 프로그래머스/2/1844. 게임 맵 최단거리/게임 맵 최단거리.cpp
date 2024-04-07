#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef struct location{
    int x,y,dist;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visited[100][100];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<location> q;
    
    int n = maps.size();
    int m = maps[0].size();
    
    q.push({0,0,1});
    visited[0][0] = 1;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        
        if(x==n-1 && y==m-1)
            return dist;
        
        for(int i=0;i<4;i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            if((0<=tx&&tx<n) && (0<=ty&&ty<m) && maps[tx][ty] && !visited[tx][ty]){
                visited[tx][ty] = 1;
                q.push({tx,ty,dist+1});
            }
        }
    }
    
    return -1;
}