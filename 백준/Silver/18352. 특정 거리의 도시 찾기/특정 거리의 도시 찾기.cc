#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define INF 987654321
using namespace std;

int n, m, k, x;
int dist[300001];
vector<int> graph[300001];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void djstra() {
    pq.push({ 0,x });
    dist[x] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                pq.push({ dist[v],v });
            }
        }
    }
}

void init() {
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
        dist[i] = INF;
}

void print(set<int>& answer) {
    for (auto& tmp : answer)
        cout << tmp << endl;
}

int main() {
    cin >> n >> m >> k >> x;

    init();
    djstra();

    set<int> answer;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k)
            answer.insert(i);
    }

    if (answer.size() == 0)
        cout << -1;
    else
        print(answer);

    return 0;
}