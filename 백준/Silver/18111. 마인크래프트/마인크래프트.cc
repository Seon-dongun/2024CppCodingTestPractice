#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[500][500];

int main() {
    int n, m, b;
    cin >> n >> m >> b;

    int maxheight = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            maxheight = max(maxheight, map[i][j]);
        }
    }

    int minTime = 999999999;
    int answerHeight=-1;
    for (int h = maxheight; h >= 0; h--) {
        int time = 0;
        int tb = b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == h)
                    continue;

                if (map[i][j] < h) {
                    int need = h - map[i][j];
                    tb -= need;
                    time += need;
                }
                else if (map[i][j] > h) {
                    int need = map[i][j] - h;
                    tb += need;
                    time += (2 * need);
                }
            }
        }

        if (tb < 0)
            continue;

        if (minTime > time) {
            minTime = time;
            answerHeight = h;
        }
        else if (minTime == time)
            answerHeight = max(answerHeight, h);
    }
    cout << minTime << " " << answerHeight << endl;
}