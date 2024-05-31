#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

vector<int> graph[20001];
int dist[20001];
priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;

int checkDist() {
    pq.push({0, 1});
    dist[1] = 0;
    int maxDist = 0;
    
    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if(d > maxDist)
            maxDist = d;
        
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
    
    return maxDist;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    
    int maxDist = checkDist();
    
    for(int i = 1; i <= n; i++) {
        if(dist[i] == maxDist)
            answer++;
    }
    
    return answer;
}