#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pa;
    priority_queue<int,vector<int>,greater<int>> pb;
    
    for(int i=0;i<A.size();i++){
        pa.push(A[i]);
        pb.push(B[i]);
    }
    
    while(!pa.empty() && !pb.empty()){
        if(pa.top() < pb.top()){
            answer++;
            pa.pop();
            pb.pop();
        }
        else
            pb.pop();
    }
    
    return answer;
}