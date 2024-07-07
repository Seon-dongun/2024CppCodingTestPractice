#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int map[500][500] = { 0, };
    int h, w, answer = 0;
    cin >> h >> w;
    int blockh;
    for (int i = 0; i < w; i++) {
        cin >> blockh;
        for (int j = h - 1; j >= h - blockh; j--)
            map[j][i] = 1;
    }

    for (int i = 0; i < h; i++) {
        int s = 0, e = w - 1;

        while (map[i][s] == 0)
            s++;
        while (map[i][e] == 0)
            e--;

        if (s < e) {
            for (int j = s; j <= e; j++) {
                if (map[i][j] == 0)
                    answer++;
            }
        }
    }

    cout << answer;
    return 0;
}