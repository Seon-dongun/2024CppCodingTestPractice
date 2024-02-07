#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    
    int mNode = 0;
    for(int i=0;i<edges.size();i++)
        mNode = max(mNode,max(edges[i][0],edges[i][1]));
    
    int* input = new int[mNode+1]();
    int* output = new int[mNode+1]();
    
    for(int i=0;i<edges.size();i++){
        input[edges[i][1]]++;
        output[edges[i][0]]++;
    }
     
    for(int i=1;i<=mNode;i++){
        if(input[i]==0 && output[i]>=2) // 시작 정점 찾기. 들어오는 간선은 없고 나가는 간선이 2개 이상인 노드
            answer[0] = i;
             
        else if(output[i]==0) // 막대그래프 찾기. 나가는 간선이 없는 정점 찾기
            answer[2]++;
               
        else if(output[i]==2 && input[i]>=2)// 8자그래프 찾기. 나가는 간선 2개, 들어오는 간선 2개 이상인 노드 찾기
            answer[3]++;
    }

    answer[1] = output[answer[0]] - answer[2] - answer[3];//시작 정점에서 나가는 간선 수만큼 서브 그래프가 존재하기 때문에, 전체 그래프 수에서 막대그래프, 8자그래프 개수를 빼주면 도넛그래프 개수를 구할 수 있음. 도넛그래프는 별도의 규칙성이 없기때문에 이렇게 구하는 것.

    return answer;
}