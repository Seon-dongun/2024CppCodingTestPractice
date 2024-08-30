#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct FireBall {
    int r, c, m, s, d;
};
vector<FireBall> map[51][51];
int N, M, K;
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int T_Dir[4] = { 0,2,4,6 };
int F_Dir[4] = { 1,3,5,7 };

vector<FireBall> fireballs;

void fireBallMove() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            map[i][j].clear();
    }

    for (int i = 0; i < fireballs.size(); i++) {
        int cx = fireballs[i].r;
        int cy = fireballs[i].c;
        int cm = fireballs[i].m;
        int cs = fireballs[i].s;
        int cd = fireballs[i].d;

        int actualMove = cs % N;
        int nx = cx + dx[cd] * actualMove;
        int ny = cy + dy[cd] * actualMove;
        if (nx > N) nx -= N;
        if (ny > N) ny -= N;
        if (nx < 1) nx += N;
        if (ny < 1) ny += N;

        map[nx][ny].push_back({ nx,ny,cm,cs,cd });

        fireballs[i].r = nx;
        fireballs[i].c = ny;
    }
}

void fireBallSum() {
    vector<FireBall> tmp;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j].size() == 0)
                continue;
            if (map[i][j].size() == 1) {
                tmp.push_back(map[i][j][0]);
                continue;
            }

            int msum = 0, ssum = 0;
            int last = map[i][j][0].d % 2;
            bool isAllOddOrEven = true;
            for (int q = 0; q < map[i][j].size(); q++) {
                msum += map[i][j][q].m;
                ssum += map[i][j][q].s;
                if (map[i][j][q].d % 2 != last)
                    isAllOddOrEven = false;
            }

            int divm = msum / 5;
            int divs = ssum / map[i][j].size();

            if (divm == 0) continue;
            if (isAllOddOrEven == true) {
                for (int k = 0; k < 4; k++)
                    tmp.push_back({ i,j,divm,divs,T_Dir[k] });
            }
            else {
                for (int k = 0; k < 4; k++)
                    tmp.push_back({ i,j,divm,divs,F_Dir[k] });
            }
        }
    }
    fireballs = tmp;
}

int main() {
    cin >> N >> M >> K;
    int answer = 0;

    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fireballs.push_back({ r,c,m,s,d });
        map[r][c].push_back({ r,c,m,s,d });
    }

    while (K--) {
        fireBallMove();
        fireBallSum();
    }

    for (int i = 0; i < fireballs.size(); i++)
        answer += fireballs[i].m;

    cout << answer << endl;
}