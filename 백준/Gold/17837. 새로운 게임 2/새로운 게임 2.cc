#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;
struct Pos {
    int x, y;
};

struct Pawn {
    Pos pos;
    int dir;
};

Pos operator+(Pos& a,Pos& b) {
    return { a.x + b.x,a.y + b.y };
}

int N, K;
int board[13][13];
deque<int> dequeBoard[13][13];
unordered_map<int, Pos> dirM = { {1,{0,1}},{2,{0,-1}},{3,{-1,0}},{4,{1,0}} };
Pawn pawns[11];

void meetWhiteOrBlue(Pawn& curPawn,Pos nextPos,int pawnId){
    stack<int> st;
    while (dequeBoard[curPawn.pos.x][curPawn.pos.y].back() != pawnId) {
        st.push(dequeBoard[curPawn.pos.x][curPawn.pos.y].back());
        dequeBoard[curPawn.pos.x][curPawn.pos.y].pop_back();
    }
    st.push(dequeBoard[curPawn.pos.x][curPawn.pos.y].back());
    dequeBoard[curPawn.pos.x][curPawn.pos.y].pop_back();

    while (!st.empty()) {
        pawns[st.top()].pos = nextPos;
        dequeBoard[nextPos.x][nextPos.y].push_back(st.top());
        st.pop();
    }
}

void meetRed(Pawn& curPawn, Pos nextPos, int pawnId) {
    queue<int> q;

    while (dequeBoard[curPawn.pos.x][curPawn.pos.y].back() != pawnId) {
        q.push(dequeBoard[curPawn.pos.x][curPawn.pos.y].back());
        dequeBoard[curPawn.pos.x][curPawn.pos.y].pop_back();
    }

    q.push(dequeBoard[curPawn.pos.x][curPawn.pos.y].back());
    dequeBoard[curPawn.pos.x][curPawn.pos.y].pop_back();


    while (!q.empty()) {
        pawns[q.front()].pos = nextPos;
        dequeBoard[nextPos.x][nextPos.y].push_back(q.front());
        q.pop();
    }
}

bool isGameOver() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dequeBoard[i][j].size() >= 4)
                return true;
        }
    }
    return false;
}

bool movePawn() {
    for (int i = 1; i <= K; i++) {
        Pawn curPawn = pawns[i];

        Pos nextPos = curPawn.pos + dirM[curPawn.dir];

        if (nextPos.x<1 || nextPos.x > N || nextPos.y < 1 || nextPos.y > N || board[nextPos.x][nextPos.y] == 2) {
            if (pawns[i].dir == 1) pawns[i].dir = 2;
            else if (pawns[i].dir == 2) pawns[i].dir = 1;
            else if (pawns[i].dir == 3) pawns[i].dir = 4;
            else if (pawns[i].dir == 4) pawns[i].dir = 3;

            curPawn = pawns[i];
            nextPos = curPawn.pos + dirM[curPawn.dir];

            if (1<=nextPos.x && nextPos.x <= N && 1<=nextPos.y && nextPos.y <= N) {
                if (board[nextPos.x][nextPos.y] == 0)
                    meetWhiteOrBlue(curPawn, nextPos, i);
                else if (board[nextPos.x][nextPos.y] == 1)
                    meetRed(curPawn, nextPos, i);
            }
        }

        else if (board[nextPos.x][nextPos.y] == 0) {
            meetWhiteOrBlue(curPawn, nextPos,i);
        }
        else if (board[nextPos.x][nextPos.y] == 1) {
            meetRed(curPawn, nextPos, i);
        }

        if (isGameOver())
            return true;
    }
    return false;
}


void Input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= K; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        pawns[i] = { {x,y},dir };
        dequeBoard[x][y].push_front(i);
    }
}

int main() {
    Input();

    int turn = 1;
    while (1) {
        if (turn > 1000)
            break;

        if (movePawn())
            break;

        turn++;
    }

    if (turn > 1000)
        cout << -1;
    else
        cout << turn;
    return 0;
}