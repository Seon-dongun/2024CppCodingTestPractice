#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef struct Node{
    int u,v,w;
}Node;

struct cmp {
	bool operator()(Node& a, Node& b) {
		if (a.w > b.w)
			return true;
		else
			return false;
	}
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0,cnt=0;
    int visited[101]={0};
    vector<pair<int, int>> graph[101];
    priority_queue<Node,vector<Node>,cmp> pq;
    
    for(int i=0;i<costs.size();i++){
        graph[costs[i][0]].push_back({costs[i][1],costs[i][2]});
        graph[costs[i][1]].push_back({costs[i][0],costs[i][2]});
    }
    
    for(int i=0;i<graph[0].size();i++)
        pq.push({0,graph[0][i].first,graph[0][i].second});
    
    visited[0] = 1;
    
    while(!pq.empty()){
        if(n-1==cnt)
            break;
        
        int v = pq.top().v;
        int cost = pq.top().w;
        pq.pop();
        
        if(visited[v]==0){
            answer+=cost;
            cnt++;
            visited[v] = 1;
            
            for(int i=0;i<graph[v].size();i++)
                pq.push({v,graph[v][i].first,graph[v][i].second});
        }        
    }
    
    return answer;
}

