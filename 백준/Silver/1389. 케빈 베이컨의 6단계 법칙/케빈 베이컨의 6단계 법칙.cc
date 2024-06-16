#include <iostream>
#define INF 987654321
using namespace std;

int kevin[101][101];
void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                kevin[i][j] = min(kevin[i][j], kevin[i][k] + kevin[k][j]);
            }
        }
    }
}

int main() {
    int n, m, u, e;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                kevin[i][j] = 0;
            else
                kevin[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> u >> e;
        kevin[u][e] = 1;
        kevin[e][u] = 1;
    }

    floyd(n);

    int minKevin = INF;
    int answer=-1;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += kevin[i][j];

        if (sum < minKevin) {
            minKevin = sum;
            answer = i;
        }
    }

    cout << answer;
    return 0;
}