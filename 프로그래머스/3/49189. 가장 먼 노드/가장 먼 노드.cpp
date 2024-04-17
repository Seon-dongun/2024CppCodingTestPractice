#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int value[20001];
    vector<int> graph[20001];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    for(int i=0;i<edge.size();i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    for(int i=1;i<=n;i++)
        value[i] = 999999999;
    
    value[1] = 0;
    
    pq.push({0,1});
    int max = -1;
        
    while(!pq.empty()){
        int u = pq.top().second;
        int curW = pq.top().first;
        pq.pop();
        
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            
            if(curW+1 < value[v]){
                value[v] = curW+1;
                pq.push({curW+1,v});
            }

            if(max<value[v])
                max = value[v];
        }  
    }
    
    cout << max << endl;
    for(int i=1;i<=n;i++){
        if(max == value[i])
            answer++;
    }
    
    return answer;
}