#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> graph[50001];
int parent[50001];

int visited[50001] = { 0, };
void checkParent(int pNum) {
    queue<int> q;
    visited[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for (int i = 0; i < graph[n].size(); i++) {
            if (!visited[graph[n][i]]) {
                visited[graph[n][i]] = 1;
                parent[graph[n][i]] = n;
                q.push(graph[n][i]);
            }
        }
    }
}

void check(int a, int b) {
    stack<int> st1, st2;
    int answer;

    st1.push(a);
    int tmp = a;
    while (parent[tmp]!=-1) {
        st1.push(parent[tmp]);
        tmp = parent[tmp];
    }

    st2.push(b);
    tmp = b;
    while (parent[tmp] != -1) {
        st2.push(parent[tmp]);
        tmp = parent[tmp];
    }

    while (!st1.empty() && !st2.empty()) {
        if (st1.top() != st2.top())
            break;
        answer = st1.top();
        st1.pop();
        st2.pop();
    }

    cout << answer << endl;
}

int main() {
    int n, m, u, v, a, b;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    parent[1] = -1;
    checkParent(1);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        check(a, b);
    }

    return 0;
}