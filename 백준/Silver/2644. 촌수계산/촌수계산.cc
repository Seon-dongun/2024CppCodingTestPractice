#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<pair<int,int>> graph[101];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int value[101];
void dijkstra(int s,int e){
    value[s] = 0;
    pq.push({0,s});
    
    while(!pq.empty()){
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i].first;
            int cost = graph[u][i].second;
            
            if(w+cost < value[v]){
                value[v] = w+cost;
                pq.push({value[v],v});
            }
        }
    }
    return;  
}

int main(){
    int n,m,s,e,u,v;
    cin >>n;
    cin >> s >> e;
    cin >> m;
    
    for(int i=1;i<=n;i++)
        value[i] = INF;
    
    for(int i=0;i<m;i++){
        cin >> u >> v;
        graph[u].push_back({v,1});
        graph[v].push_back({u,1});
    }
    
    dijkstra(s,e);
    
    if(value[e]==INF)
        cout << -1;
    else
        cout << value[e];
    return 0;
}