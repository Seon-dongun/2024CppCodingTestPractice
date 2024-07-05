#include <iostream>
#include <vector>
using namespace std;
int map[20][20];
int dice[6] = { 0,0,0,0,0,0 };
int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int order;
    while (k--) {
        cin >> order;
        vector<int> tmp;
        if (order == 1) {
            if (y + 1 >= m)
                continue;
            y++;

            tmp = { dice[3],dice[1],dice[0],dice[5],dice[4],dice[2] };
        }
        else if (order == 2) {
            if (y - 1 < 0)
                continue;
            y--;

            tmp = { dice[2],dice[1],dice[5],dice[0],dice[4],dice[3] };
        }
        else if (order == 3) {
            if (x - 1 < 0)
                continue;
            x--;

            tmp = { dice[4],dice[0],dice[2],dice[3],dice[5],dice[1] };
        }
        else {
            if (x + 1 >= n)
                continue;
            x++;

            tmp = { dice[1],dice[5],dice[2],dice[3],dice[0],dice[4] };
        }

        for (int i = 0; i < 6; i++)
            dice[i] = tmp[i];

        if (map[x][y] == 0)
            map[x][y] = dice[5];
        else {
            dice[5] = map[x][y];
            map[x][y] = 0;
        }

        cout << dice[0] << endl;
    }

}