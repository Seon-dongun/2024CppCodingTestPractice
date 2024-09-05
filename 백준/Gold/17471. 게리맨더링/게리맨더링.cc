#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#define INF 987665432
using namespace std;

int N, minGap = INF;
vector<int> graph[101];
int peopleCount[101];
int visited[101] = { 0, };
char groupCheckAB[101];

void Input() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> peopleCount[i];

    for (int i = 1; i <= N; i++) {
        int n, v;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> v;
            graph[i].push_back(v);
        }
    }
}

int GetTotalPeople(queue<int> area) {
    int sum = 0;
    while (!area.empty()) {
        sum += peopleCount[area.front()];
        area.pop();
    }
    return sum;
}

int bfs(queue<int> area, char checkAB) {
    int groupCnt = 0;
    while (!area.empty()) {
        if (visited[area.front()]) {
            area.pop();
            continue;
        }
        queue<int> q;
        q.push(area.front());
        visited[area.front()] = 1;
        area.pop();

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];

                if (visited[v] == 0 && groupCheckAB[v] == checkAB) {
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
        groupCnt++;
    }
    return groupCnt;
}

void Print(queue<int> area) {
    while (!area.empty()) {
        cout << area.front() << " ";
        area.pop();
    }
    cout << endl;
}

int main() {
    Input();

    for (int i = 1; i <= N*0.5; i++) {
        vector<int> check(N, 0);
        for (int j = 0; j < i; j++)
            check[N - 1 - j] = 1;

        do {
            queue<int> A, B;
            memset(visited, 0, sizeof(visited));

            for (int i = 0; i < check.size(); i++) {
                if (check[i] == 0) {
                    A.push(i + 1);
                    groupCheckAB[i + 1] = 'A';
                }
                else {
                    B.push(i + 1);
                    groupCheckAB[i + 1] = 'B';
                }
            } // 두 팀이 나누어짐

            int areaCnt = 0;
            areaCnt += bfs(A, 'A');
            areaCnt += bfs(B, 'B');


            if (areaCnt > 2)
                continue;
            
            minGap = min(minGap, abs(GetTotalPeople(A) - GetTotalPeople(B)));

        } while (next_permutation(check.begin(), check.end()));
    }

    if (minGap == INF)
        cout << -1 << endl;
    else
        cout << minGap << endl;
    return 0;
}