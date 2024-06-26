#include <iostream>
#include <string>
using namespace std;
int map[1000][1000]={0,};
int mine[1000][1000]={0,};
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};
int main(){
    int n;
    string str;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> str;
        for(int j=0;j<str.length();j++){
            if(str[j]=='.')
                map[i][j] = 0;

            else{
                map[i][j] = str[j] - '0';
                mine[i][j] = -1;
                
                for(int k=0;k<8;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(0<=nx&&nx<n && 0<=ny&&ny<n && mine[nx][ny]!=-1)
                        mine[nx][ny]+=map[i][j];
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mine[i][j]==-1)
                cout << "*";
            else if(mine[i][j]>=10)
                cout << "M";
            else
                cout << mine[i][j];
        }
        cout << endl;
    }
    
    return 0;
}