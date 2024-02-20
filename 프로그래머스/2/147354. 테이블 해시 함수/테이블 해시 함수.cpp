#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int column;
bool cmp(vector<int> A, vector<int> B){
    if(A[column]>B[column])
        return false;
    else if(A[column]<B[column])
        return true;
    else{
        if(A[0]>B[0])
            return true;
        else
            return false;
    }
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col-1;
    sort(data.begin(),data.end(),cmp);
    
    for(int i=row_begin-1;i<row_end;i++){
        int tmp=0;
        for(int j=0;j<data[i].size();j++)
            tmp+=(data[i][j]%(i+1));
        answer ^= tmp;
    }
    
    return answer;
}
