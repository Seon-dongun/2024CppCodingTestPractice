#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct shark {
    int x, y, speed, dir, size;
};
int R, C, M;
shark map[101][101] = { {0,0,0,0,0}, };
bool isShark[101][101] = { false, };
int fisherPos = 0;
int totalShark = 0;

void catchShark() {
    for (int i = 1; i <= R; i++) {
        if (isShark[i][fisherPos] == true) {
            totalShark += map[i][fisherPos].size;

            map[i][fisherPos] = { 0,0,0,0,0 };
            isShark[i][fisherPos] = false;
            break;
        }
    }
}

void moveShark() {
    shark tmp[101][101] = { {0,0,0,0,0}, };
    int isSharkTmp[101][101] = { false, };
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (isShark[i][j] == true) {
                if (map[i][j].dir == 1 || map[i][j].dir == 2) {
                    int moveDist = map[i][j].speed;
                    int moveId = i;
                    int curDir = map[i][j].dir;
                    while (moveDist != 0) {
                        if (curDir == 1) {
                            if (moveId == 1) {
                                curDir = 2;
                                moveId += 1;
                            }
                            else
                                moveId--;
                        }
                        else if (curDir == 2) {
                            if (moveId == R) {
                                curDir = 1;
                                moveId -= 1;
                            }
                            else
                                moveId++;
                        }

                        moveDist--;
                    }

                    if (tmp[moveId][j].size < map[i][j].size) {
                        tmp[moveId][j] = { moveId,j,map[i][j].speed,curDir,map[i][j].size };
                        isSharkTmp[moveId][j] = true;
                    }
                }
                if (map[i][j].dir == 3 || map[i][j].dir == 4) {
                    int moveDist = map[i][j].speed;
                    int moveId = j;
                    int curDir = map[i][j].dir;
                    while (moveDist != 0) {
                        if (curDir == 3) {
                            if (moveId == C) {
                                curDir = 4;
                                moveId -= 1;
                            }
                            else
                                moveId++;
                        }
                        else if (curDir == 4) {
                            if (moveId == 1) {
                                curDir = 3;
                                moveId += 1;
                            }
                            else
                                moveId--;
                        }
                        moveDist--;
                    }

                    if (tmp[i][moveId].size < map[i][j].size) {
                        tmp[i][moveId] = { i,moveId,map[i][j].speed,curDir,map[i][j].size };
                        isSharkTmp[i][moveId] = true;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            map[i][j] = tmp[i][j];
            isShark[i][j] = isSharkTmp[i][j];
        }
    }
}


int main() {
    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {
        int x, y, speed, dir, size;
        cin >> x >> y >> speed >> dir >> size;
        map[x][y] = { x,y,speed,dir,size };
        isShark[x][y] = true;
    }

    while (fisherPos != C) {
        fisherPos++;
        catchShark();
        moveShark();
    }

    cout << totalShark;
}

