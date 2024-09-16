#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define INF 999999999
using namespace std;

 int floyd[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                floyd[i][j] = 0;
            else
                floyd[i][j] = INF;             
        }
    }
    
    for(int i=0;i<fares.size();i++){
        int u = fares[i][0];
        int v = fares[i][1];
        int w = fares[i][2];
        
        floyd[u][v] = w;
        floyd[v][u] = w;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                floyd[i][j] = min(floyd[i][j], floyd[i][k]+floyd[k][j]);
            }
        }
    }

    
    answer = floyd[s][a] + floyd[s][b];
    for(int i=1;i<=n;i++){
        if(i==s)
            continue;
        
        if(floyd[s][i] == INF || floyd[i][a]==INF || floyd[i][b] == INF)
            continue;
        
        int sum = floyd[s][i];
        sum += floyd[i][a];
        sum += floyd[i][b];
        answer = min(answer,sum);
    }
       
    return answer;
}