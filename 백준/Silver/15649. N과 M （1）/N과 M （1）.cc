#include <iostream>
using namespace std;
int n,m;
int arr[9];
bool visited[9];

void bfs(int depth){
    if(depth==m){
        for(int i=0;i<m;i++)
            cout << arr[i] <<" ";
        cout <<"\n";
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            arr[depth] = i;
            visited[i] = true;
            bfs(depth+1);
            visited[i] = false;
        }
    }
}


int main(){
    cin >> n >> m;
    bfs(0);
}