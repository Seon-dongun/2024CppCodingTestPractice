#include <string>
#include <vector>
using namespace std;

void counting(vector<int> &count, int e){
    for(int i=1; i<=e; i++){
        if(i*2>e) {
            count[i]++; 
            continue; 
        }
        
        for(int j=i; j<=e; j+=i)
            count[j]++;
    }
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> count(e+1, 0);
    vector<int> max_index(e+1, 0);
    
    counting(count, e);
    max_index[e] = e; 

    for(int i=e-1; i>=1;i--){
        
        if(count[i] >= count[max_index[i+1]]) 
            max_index[i] = i;    
        else
            max_index[i] = max_index[i+1];
    }
    
    for(int i=0; i<starts.size(); i++)
        answer.push_back(max_index[starts[i]]);   
    
    return answer;
}