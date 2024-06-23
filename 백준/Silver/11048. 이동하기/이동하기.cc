#include <iostream>
using namespace std;

int n,m;
int maze[1000][1000];
int dp[1000][1000];
int dx[3] = {1,0,1};
int dy[3] = {0,1,1};
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> maze[i][j];
    }
    
    dp[0][0] = maze[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){         
            for(int k=0;k<3;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx<n && ny < m)
                    dp[nx][ny] = max(dp[nx][ny],dp[i][j]+maze[nx][ny]);
            }          
        }
    }
    
    cout << dp[n-1][m-1];
}