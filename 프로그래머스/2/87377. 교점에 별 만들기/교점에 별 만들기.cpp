#include <string>
#include <vector>
#include <set>
#include <climits>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    set<pair<long,long>> loc;
    
    long A,B,E,C,D,F;
    double x,y,xt,xd,yt,yd;
    long maxX=LONG_MIN,minX=LONG_MAX,maxY=LONG_MIN,minY=LONG_MAX;
    for(long i=0;i<line.size()-1;i++){
        A = line[i][0];
        B = line[i][1];
        E = line[i][2];
        for(long j=i+1;j<line.size();j++){
            C = line[j][0];
            D = line[j][1];
            F = line[j][2];
            
            xt = B*F-E*D;
            xd = A*D-B*C;
            yt = E*C-A*F;
            yd = xd;
            
            if(xd==0)
                continue;
            
            x = xt/xd;
            y = yt/yd;
            if(x==static_cast<long>(x) && y==static_cast<long>(y)){
                loc.insert({x,y});   
                if(x>maxX)
                    maxX = x;
                if(x<minX)
                    minX = x;
                if(y>maxY)
                    maxY = y;
                if(y<minY)
                    minY = y;
            }
        }
    }
    
    long length = maxX - minX +1;
    long height = maxY - minY +1;
    
    vector<string> answer;
    for(long i=0;i<height;i++){
        string tmp ="";
        for(long j=0;j<length;j++)
            tmp+=".";
        answer.push_back(tmp);
    }
    
    for(auto tmp:loc){
        long newX = tmp.second-maxY;
        long newY = tmp.first-minX;
        answer[abs(newX)][abs(newY)] = '*';
    }
    
    return answer;
}

