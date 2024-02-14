#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int find(int x,int y, int n){
    queue<int> q;
    vector<int> visited(y+1,0);
    
    q.push(x);
    while(!q.empty()){
        int tx = q.front();
        q.pop();  
        
        if(tx==y)
            return visited[tx];
        
        int dx[3] = {tx+n,tx*2,tx*3};
        for(int i=0;i<3;i++){
            if(dx[i]>y || visited[dx[i]] != 0)
                continue;
            visited[dx[i]] = visited[tx] +1;
            q.push(dx[i]);
        }    
    }   
    return -1;
}


int solution(int x, int y, int n) {
    return find(x,y,n);
}
