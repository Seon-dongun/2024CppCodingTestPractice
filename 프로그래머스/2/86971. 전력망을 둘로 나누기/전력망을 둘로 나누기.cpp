#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> graph[101];

int bfs(int s,int visited[]){
    queue<int> q;
    int cnt=1;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(int i=0;i<graph[u].size();i++){
            int t = graph[u][i];
            if(visited[t]==0){
                visited[t] = 1;
                cnt++;
                q.push(t);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    for(int i=0;i<wires.size();i++){
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }
    
    int answer=INT_MAX;
    for(int i=0;i<wires.size();i++){
        int visited[101]={0};
        vector<int> result;
        
        int u = wires[i][0];
        int v = wires[i][1];
        
        graph[u].erase(graph[u].begin());
        graph[v].erase(graph[v].begin());
   
        for(int j=1;j<=n;j++){
            if(visited[j]==0)
                result.push_back(bfs(j,visited));
        }  

        answer = min(answer,abs(result[0]-result[1]));
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return answer;
}