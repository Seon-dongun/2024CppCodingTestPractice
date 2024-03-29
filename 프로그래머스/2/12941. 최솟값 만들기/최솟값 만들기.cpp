#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int n = A.size();
    
    sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());
    
    for(int i=0;i<n;i++)
        answer+=A[i]*B[i];

    return answer;
}