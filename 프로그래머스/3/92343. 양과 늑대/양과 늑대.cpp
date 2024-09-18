#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> graph[17];
vector<int> sw;
int answer = 0;

void DFS(int cur, int sheep, int wolf, queue<int> q) {
    
    if (sw[cur] == 0)
        sheep++;
    else 
        wolf++;    
    
    if (wolf >= sheep) 
        return;
    if (answer < sheep) 
        answer = sheep;
    
    for (int i = 0; i < graph[cur].size(); i++)
        q.push(graph[cur][i]);
    
    for (int i = 0; i < q.size(); i++) {
        int next = q.front();
        q.pop();
        DFS(next, sheep, wolf, q);
        q.push(next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {    
    sw = info;

    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];     
        graph[u].push_back(v);
    }
    
    queue<int> q;
    DFS(0, 0, 0, q);
    
    return answer;
}

