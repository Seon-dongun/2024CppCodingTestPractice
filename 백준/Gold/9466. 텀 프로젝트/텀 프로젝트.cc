#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int graph[100001];
int visited[100001];
int done[100001];
int cnt;

void check(int idx) {
    visited[idx] = 1;
    int next = graph[idx];

    if (!visited[next])
        check(next);
    else if(!done[next]){
        for (int i = next; i != idx; i = graph[i])
            cnt++;
        cnt++;
    }
    done[idx] = 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, tmp;
        cin >> n;
        vector<int> num(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> graph[i];

        int answer = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                check(i);
        }
        cout << n-cnt << endl;
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(done, 0, sizeof(done));
    }
}