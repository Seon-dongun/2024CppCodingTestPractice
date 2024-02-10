#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct Node{
    int x,y,depth;
}Node;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n, m;
int startX, startY;
int visited[100][100];

int bfs(int x, int y, vector<string>& board){
    queue<Node> q;
    visited[x][y] = 1;
    q.push({x,y,1});
    
    while(!q.empty()){
        Node node = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int tx = node.x;
            int ty = node.y;
         
            while(1){             
                if(tx+dx[i]<0 || tx+dx[i]>=n ||ty+dy[i]<0||ty+dy[i]>=m || board[tx+dx[i]][ty+dy[i]]=='D')
                    break;
                else{
                    tx +=dx[i];
                    ty +=dy[i];
                }
            }
            
            if(visited[tx][ty]==0){
                visited[tx][ty] = 1;
                q.push({tx,ty,node.depth+1});              
                
                if(board[tx][ty]=='G')
                    return node.depth;
            }         
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    int answer = 0; 
    
    n = board.size();
    m = board[0].length();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'R'){
                startX = i; startY = j;
            }
        }
    }
        
    return bfs(startX, startY, board);
}