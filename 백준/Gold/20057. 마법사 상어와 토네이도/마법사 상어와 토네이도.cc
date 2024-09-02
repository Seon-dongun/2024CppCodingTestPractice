#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Info {
    int x, y;
    float weight;
};

int flag = 0;
int N;
int map[501][501];
int outSand = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
Info info[4][10] =
{
    {{-1,1,0.01},{1,1,0.01},{-1,0,0.07},{1,0,0.07},{-1,-1,0.1},{1,-1,0.1},{-2,0,0.02},{2,0,0.02},{0,-2,0.05},{0,-1,0.55}},
    {{-1,-1,0.01},{-1,1,0.01},{0,-1,0.07},{0,1,0.07},{1,-1,0.1},{1,1,0.1},{0,-2,0.02},{0,2,0.02},{2,0,0.05},{1,0,0.55}},
    {{-1,-1,0.01},{1,-1,0.01},{-1,0,0.07},{1,0,0.07},{-1,1,0.1},{1,1,0.1},{-2,0,0.02},{2,0,0.02},{0,2,0.05},{0,1,0.55}},
    {{1,-1,0.01},{1,1,0.01},{0,-1,0.07},{0,1,0.07},{-1,-1,0.1},{-1,1,0.1},{0,-2,0.02},{0,2,0.02},{-2,0,0.05},{-1,0,0.55}}
};

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
}


void storm() {
    int cx = (N >> 1) + 1, cy = (N >> 1) + 1;
    int moveDist = 1;
    int spreadTargetValue;
    int cnt = 0;
    int dir = 0; // 0좌 1하 2우 3상

    while (1) {
        cnt++;

        for (int i = 0; i < moveDist; i++) {
            cx += dx[dir];
            cy += dy[dir];
            spreadTargetValue = map[cx][cy];

            for (int i = 0; i < 9; i++) {
                int nx = cx + info[dir][i].x;
                int ny = cy + info[dir][i].y;
                float weight = info[dir][i].weight;

                int sand = (int)(map[cx][cy] * weight);
                spreadTargetValue -= sand;

                if (nx<1 || ny < 1 || nx > N || ny > N)
                    outSand += sand;

                else
                    map[nx][ny] += sand;
            }

            int nx = cx + info[dir][9].x;
            int ny = cy + info[dir][9].y;
            float weight = info[dir][9].weight;
            if (nx<1 || ny < 1 || nx > N || ny > N)
                outSand += spreadTargetValue;
            else
                map[nx][ny] += spreadTargetValue;

            map[cx][cy] = 0;

            if (cx == 1 && cy == 1)
                return;

        }

        dir = (dir + 1) % 4;

        if (cnt == 2) {
            cnt = 0;
            moveDist++;
        }
    }
}

int main() {
    input();
    storm();

    cout << outSand << endl;
    return 0;
}