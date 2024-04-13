#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),cmp);
    
    int currentCamera = routes[0][1];
    answer++;
    
    for(int i=1;i<routes.size();i++){
        if(routes[i][0] > currentCamera){
            answer++;
            currentCamera = routes[i][1];
        }
    }
    
    return answer;
}
//[0, 10] [1, 10] [2, 3] [4, 5] 