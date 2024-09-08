#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int num[8];
int tmp[8];
int visited[8] = { 0, };

void backtracking(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++)
            cout << tmp[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            tmp[depth] = num[i];
            visited[i] = 1;
            backtracking(depth + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num, num + N);
    backtracking(0);
}