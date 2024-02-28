#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for(long long i=left;i<=right;i++){
        long long col = i/n;
        long long row = i%n;
        
        if(col==0 && row==0)
            answer.push_back(1); 
        else if(col==row)
            answer.push_back(col+1);
        else{
            int minV = min(col,row);
            answer.push_back(col+row+1 - minV);
        }    
    }
    return answer;
}