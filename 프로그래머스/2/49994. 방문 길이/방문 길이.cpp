#include <string>
#include <map>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int x = 5, y =5,lastX,lastY;
     map<pair<pair<int, int>, pair<int, int>>, bool> visitedEdge;
    
    for(int i=0;i<dirs.length();i++){
        lastX = x;
        lastY = y;
        
       if (dirs[i] == 'U'){
            if (x < 1) 
                continue;
            x--;
        }
        if (dirs[i] == 'D'){
            if (x > 9) 
                continue;
            x++;
        }
        if (dirs[i] == 'L'){
            if (y < 1) 
                continue;
            y--;
        }
        if (dirs[i] == 'R'){
            if (y > 9)
                continue;
            y++;
        }

        if (visitedEdge[make_pair(make_pair(lastX, lastY), make_pair(x, y))] == true)
            continue;

        visitedEdge[make_pair(make_pair(lastX, lastY), make_pair(x, y))] = true;
        visitedEdge[make_pair(make_pair(x, y), make_pair(lastX, lastY))] = true;
        answer++;
    }
    return answer;
}