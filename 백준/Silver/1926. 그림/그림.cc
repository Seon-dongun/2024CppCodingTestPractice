#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int maxVol=0;
int board[500][500];
int visited[500][500]={0,};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void check(int i,int j){
    queue<pair<int,int>> q;
    int vol = 1;
    q.push({i,j});
    visited[i][j] = 1;

    while(!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ni = ci + dx[i];
            int nj = cj + dy[i];
            if(ni<0 || ni>=500 || nj<0 || nj>=500 || !board[ni][nj] || visited[ni][nj])
                continue;
            
            q.push({ni,nj});
            visited[ni][nj] = 1;
            vol++;
        }   
    }
    if(maxVol < vol)
        maxVol = vol;
    
    return;
}

int main(){
    int n,m,cnt=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> board[i][j];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1 && visited[i][j]==0){
                check(i,j);
                cnt++;
            }
        }
    }
    
    cout << cnt << endl;
    cout << maxVol << endl;
    
    return 0;
}