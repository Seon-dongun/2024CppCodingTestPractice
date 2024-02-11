#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(int i=0;i<balls.size();i++){
        int minV = INT_MAX;
        int north,south,west,east;
        
        north = n-balls[i][1];
        south = balls[i][1];
        east = m-balls[i][0];
        west = balls[i][0];
        
        if(startX!=balls[i][0]||startY>=balls[i][1])
            minV = min(minV, static_cast<int>(pow(startX-balls[i][0], 2) + pow(startY-(n+north), 2)));
        
        if(startX!=balls[i][0]||startY<=balls[i][1])
            minV = min(minV, static_cast<int>(pow(startX-balls[i][0], 2) + pow(startY-(-1*south), 2)));
        
        if(startY!=balls[i][1] || startX<=balls[i][0])
            minV = min(minV, static_cast<int>(pow(startX-(-1*west), 2) + pow(startY-balls[i][1], 2)));
        
        if(startY!=balls[i][1]|| startX>=balls[i][0])
            minV = min(minV, static_cast<int>(pow(startX-(m+east), 2) + pow(startY-balls[i][1], 2)));
                                                           
        answer.push_back(minV);
    }  
    return answer;
}
