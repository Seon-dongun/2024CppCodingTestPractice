#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int find(int x,int y, int n){
    queue<pair<int,int>> q;
    vector<int> visited(y+1,0);
    
    q.push({x,0});
    while(!q.empty()){
        int tx = q.front().first;
        int cnt = q.front().second;
        visited[tx] = 1;
        q.pop();  
        
        if(tx==y)
            return cnt;
        
        if(tx>y)
            continue;
    
        if(tx+n<=y && visited[tx+n]!=1)          
            q.push({tx+n,cnt+1});
        if(tx*2<=y&& visited[tx*2]!=1)
            q.push({tx*2,cnt+1});
        if(tx*3<=y&& visited[tx*3]!=1)
            q.push({tx*3,cnt+1});

    }   
    return -1;
}


int solution(int x, int y, int n) {
    return find(x,y,n);
}
