#include <iostream>
using namespace std;

int map[100][100];
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};
int main(){
    int n,answer = 0;
    char ch;
    cin>> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> ch;
            if(ch=='#')
                map[i][j] = -1;
            else
                map[i][j] = ch-'0';
        }
    }
    
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            int flag=0;
            for(int k=0;k<8;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(map[nx][ny]==0){
                    map[i][j] = -2;
                    flag = 1;
                    break;
                }
            }
            
            if(flag==0){
                for(int k=0;k<8;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(map[nx][ny]>0)
                        map[nx][ny]--;
                }
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}