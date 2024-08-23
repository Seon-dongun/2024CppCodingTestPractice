#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m, k, r, c;
int isStick[40][40] = { 0, };
int sticker[4][10][10];

bool check(int si, int sj, int curCir) {
    int curR = r, curC = c;
    if (curCir % 2 == 1) {
        int tmp = curR;
        curR = curC;
        curC = tmp;
    }

    if (si + curR > n || sj + curC > m)
        return false;

    for (int i = si; i < si + curR; i++) {
        for (int j = sj; j < sj + curC; j++) {
            if (isStick[i][j] == 1 && sticker[curCir][i - si][j - sj] == 1)
                return false;
        }
    }

    for (int i = si; i < si + curR; i++) {
        for (int j = sj; j < sj + curC; j++) {
            if (sticker[curCir][i - si][j - sj] == 1)
                isStick[i][j] = 1;
        }
    }

    return true;
}

void saveCirculate() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            sticker[1][j][r - 1 - i] = sticker[0][i][j];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            sticker[2][r - 1 - i][c - 1 - j] = sticker[0][i][j];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            sticker[3][c - 1 - j][i] = sticker[0][i][j];
    }
}
int main() {
    int scnt[100] = { 0, };
    int answer = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        memset(sticker, 0, sizeof(sticker));
        cin >> r >> c;
        for (int j = 0; j < r; j++) {
            for (int l = 0; l < c; l++) {
                cin >> sticker[0][j][l];
                if (sticker[0][j][l] == 1)
                    scnt[i]++;
            }
        }

        saveCirculate();

        for (int q = 0; q < 4; q++) {
            bool stickFlag = false;
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < m; l++) {
                    if (check(j, l, q)) {
                        stickFlag = true;
                        answer += scnt[i];
                        break;
                    }
                }

                if (stickFlag)
                    break;
            }

            if (stickFlag)
                break;
        }
    }

    cout << answer << endl;
}