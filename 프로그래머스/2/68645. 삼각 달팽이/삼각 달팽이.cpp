#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int tri[1000][1000];
    
    int x = -1, y = 0;
    pair<int,int> move[3] = {{1,0},{0,1},{-1,-1}};
    int num=1,cyc=0,tmp=n;
    while(tmp!=0){
        for(int i=0;i<tmp;i++){
            x+=move[cyc].first;
            y+=move[cyc].second;
            tri[x][y] = num++;
        }
        cyc++;
        cyc%=3;
        tmp--;       
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
            answer.push_back(tri[i][j]);
    }
    
    return answer;
}