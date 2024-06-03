#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    int answer = 0;
    int cost[1001][1001]={0,};
    for(int i=0;i<skill.size();i++){
        int type = skill[i][0];
        int r1 = skill[i][1], c1 = skill[i][2], r2 = skill[i][3]+1, c2 = skill[i][4]+1;
        int degree = skill[i][5];
        if(type==1){    
            cost[r1][c1] -=degree;
            cost[r1][c2] +=degree;
            cost[r2][c1] +=degree;
            cost[r2][c2] -=degree;
        }
        else if(type==2){
            cost[r1][c1] +=degree;
            cost[r1][c2] -=degree;
            cost[r2][c1] -=degree;
            cost[r2][c2] +=degree;
        }
    }
    
    for(int i=0;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cost[i][j] += cost[i][j-1];
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cost[i][j] += cost[i-1][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] + cost[i][j]>0)
                answer++;
        }
    }
    
    return answer;
}