#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int t;
bool cmp(vector<int> A, vector<int> B){
    if(A[t]>B[t])
        return false;
    else if(A[t]<B[t])
        return true;
    else{
        if(A[0]>B[0])
            return true;
        else
            return false;
    }
}

int cal(vector<int> sum,int n){
    if(sum.size()-2==n)
        return sum[n] ^ sum[n+1]; 
        
    return sum[n] ^ cal(sum,n+1);    
}


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    vector<int> sum;
    t = col-1;
    sort(data.begin(),data.end(),cmp);
    
    for(int i=row_begin-1;i<row_end;i++){
        int tmp=0;
        for(int j=0;j<data[i].size();j++){
            tmp+=(data[i][j]%(i+1));
        }
        sum.push_back(tmp);
    }
    if(sum.size()==1)
        answer = sum[0];
    else
        answer = cal(sum,0);
    
    
    return answer;
}