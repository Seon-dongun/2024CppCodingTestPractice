#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int dx[4] = {0,0,1,1};
    int dy[4] = {0,1,0,1};
    vector<pair<int,int>> deleteIndex;
    
    for(int i=0;i<board.size()-1;i++){
        for(int j=0;j<board[i].length()-1;j++){
            if(board[i][j]==board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j]==board[i+1][j+1])
                deleteIndex.push_back({i,j});
        }
    }
    
    while(deleteIndex.size()>0){
        for(int i=0;i<deleteIndex.size();i++){
            int di = deleteIndex[i].first;
            int dj = deleteIndex[i].second;
            for(int j=0;j<4;j++){
                if(board[di+dx[j]][dj+dy[j]]!='0'){
                    board[di+dx[j]][dj+dy[j]] = '0';
                    answer++;
                }
            }
        }
        deleteIndex.clear();
        
        for(int j=0;j<board[0].length();j++){
            for(int i=board.size()-2;i>=0;i--){
                if(i<board.size()-1 && board[i][j] !='0' && board[i+1][j]=='0'){
                    char tmp = board[i][j];
                    board[i][j] = board[i+1][j];
                    board[i+1][j] = tmp;
                    i+=2;
                }
            }
        }
        
        for(int i=0;i<board.size()-1;i++){
            for(int j=0;j<board[i].length()-1;j++){
                if(board[i][j]!='0' && board[i][j]==board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j]==board[i+1][j+1])
                    deleteIndex.push_back({i,j});
            }
        }
    }
    return answer;
}