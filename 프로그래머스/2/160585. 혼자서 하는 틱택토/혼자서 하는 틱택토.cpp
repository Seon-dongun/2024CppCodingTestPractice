#include <string>
#include <vector>

using namespace std;

bool checkWin(vector<string>& board,string check){
    string col1="",col2="",col3="",dig1="",dig2="";
    col1 = col1 + board[0][0]+board[1][0]+board[2][0];
    col2 = col2 +board[0][1]+board[1][1]+board[2][1];
    col3 = col3 +board[0][2]+board[1][2]+board[2][2];
    dig1 = dig1 +board[0][0] + board[1][1] + board[2][2];
    dig2 = dig2 +board[0][2]+board[1][1] + board[2][0];
    
    if(board[0]==check || board[1]==check || board[2]==check||col1==check ||col2==check || col3==check||dig1 ==check || dig2==check)
        return true;
    else
        return false;   
}

int solution(vector<string> board) {
    int Ocnt = 0, Xcnt = 0;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].length();j++){
            if(board[i][j]=='O')
                Ocnt++;
            else if(board[i][j]=='X')
                Xcnt++;
        }
    }
    
    bool X = checkWin(board,"XXX");
    bool O = checkWin(board,"OOO");

    if(Ocnt<Xcnt || Ocnt-Xcnt>1)
        return 0;
    
    else if(Ocnt>Xcnt){
        if(X)
            return 0;
    }
    else{
        if(O)
            return 0;
    }
       
    return 1;
    
}