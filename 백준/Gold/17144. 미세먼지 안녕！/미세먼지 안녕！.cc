#include <iostream>
#include <vector>
using namespace std;

int room[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dust = 0;
void upFreshing(int r, int c, pair<int, int> airfresher) {
    int i = airfresher.first - 1;
    int j = airfresher.second;

    dust -= room[i][j];

    while (i > 1) {
        room[i][j] = room[i - 1][j];
        i--;
    }

    while (j < c) {
        room[i][j] = room[i][j + 1];
        j++;
    }

    while (i < airfresher.first) {
        room[i][j] = room[i + 1][j];
        i++;
    }

    while (j > airfresher.second + 1) {
        room[i][j] = room[i][j - 1];
        j--;
    }
    room[i][j] = 0;
}

void downFreshing(int r, int c, pair<int, int> airfresher) {
    int i = airfresher.first + 1;
    int j = airfresher.second;

    dust -= room[i][j];

    while (i < r) {
        room[i][j] = room[i + 1][j];
        i++;
    }
    while (j < c) {
        room[i][j] = room[i][j + 1];
        j++;
    }
    while (i > airfresher.first) {
        room[i][j] = room[i - 1][j];
        i--;
    }
    while (j > airfresher.second + 1) {
        room[i][j] = room[i][j - 1];
        j--;
    }
    room[i][j] = 0;
}

int main() {
    int r, c, t;
    vector<pair<int, int>> airfresher;
    cin >> r >> c >> t;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> room[i][j];
            if (room[i][j] == -1)
                airfresher.push_back({ i,j });
            else if (room[i][j] > 0)
                dust += room[i][j];
        }
    }

    while (t--) {
        vector<vector<int>> add(r + 1, vector<int>(c + 1, 0));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (room[i][j] <= 0)
                    continue;

                int spreadValue = room[i][j] / 5;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (1 <= ni && ni <= r && 1 <= nj && nj <= c && room[ni][nj] != -1) {
                        room[i][j] -= spreadValue;
                        add[ni][nj] += spreadValue;
                    }
                }
            }
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++)
                room[i][j] += add[i][j];
        }

        if (airfresher[0].first < airfresher[1].first) {
            upFreshing(r, c, airfresher[0]);
            downFreshing(r, c, airfresher[1]);
        }
        else {
            upFreshing(r, c, airfresher[1]);
            downFreshing(r, c, airfresher[0]);
        }
    }

    cout << dust << endl;
    return 0;
}