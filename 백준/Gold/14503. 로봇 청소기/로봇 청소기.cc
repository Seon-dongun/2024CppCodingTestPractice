#include <iostream>
#include <vector>
using namespace std;
int room[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool check4DirectionClean(int i, int j) {
    for (int k = 0; k < 4; k++) {
        if (room[i + dx[k]][j + dy[k]] == 0)
            return false;
    }
    return true;
}

int cleaning(int n, int m, int i, int j, int d) {
    int cnt = 0;

    while (1) {
        if (room[i][j] == 0) {
            cnt++;
            room[i][j] = 2;
        }

        if (check4DirectionClean(i, j)) {
            if (d == 0)
                i++;
            else if (d == 1)
                j--;
            else if (d == 2)
                i--;
            else if (d == 3)
                j++;
            if (room[i][j] == 1)
                break;
        }
        else {
            while (1) {
                if (d == 0) {
                    d = 3;

                    if (room[i][j - 1] == 0) {
                        j--;
                        break;
                    }
                }
                else if (d == 1) {
                    d = 0;

                    if (room[i-1][j] == 0) {
                        i--;
                        break;
                    }
                }
                else if (d == 2) {
                    d = 1;

                    if (room[i][j+1] == 0) {
                        j++;
                        break;
                    }
                }
                else if (d == 3) {
                    d = 2;

                    if (room[i + 1][j] == 0) {
                        i++;
                        break;
                    }
                }
            }
        }
    }
    return cnt;
}

int main() {
    int n, m, si, sj, d;
    cin >> n >> m;
    cin >> si >> sj >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> room[i][j];
    }

    cout << cleaning(n, m, si, sj, d);
    return 0;
}