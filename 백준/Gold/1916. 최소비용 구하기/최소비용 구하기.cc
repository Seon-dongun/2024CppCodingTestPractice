#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int value[1001];
vector<pair<int,int>> graph[1001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void djstra(int s,int e){
    value[s] = 0;
    pq.push({0,s});
    
    while(!pq.empty()){
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        if(u==e)
            break;
        
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i].first;
            int cost = graph[u][i].second;
            
            if(value[u]+cost < value[v]){
                value[v] = value[u]+cost;
                pq.push({value[v],v});
            }
            
        }     
    }
    return;
}

int main(){
    int n,m,u,v,w,s,e;
    cin >> n;
    cin >> m;
    
    for(int i=1;i<=n;i++)
        value[i] = INF;
    
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    
    cin >> s >> e;
    djstra(s,e);
    
    cout << value[e];
    return 0;
}