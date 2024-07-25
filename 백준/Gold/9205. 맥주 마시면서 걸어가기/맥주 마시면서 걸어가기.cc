#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void checkDist(vector<int> (&graph)[102], vector<pair<int, int>>& node) {
    for (int i = 0; i < node.size(); i++) {
        for (int j = 0; j < node.size(); j++) {
            if (i == j)
                continue;
            int dist = abs(node[i].first - node[j].first) + abs(node[i].second - node[j].second);
            if (dist <= 1000) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}

void canGoFestival(vector<int> graph[102],int goal) {
    int visited[102] = { 0, };
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int cpos = q.front();
        q.pop();

        if (cpos == goal) {
            cout << "happy" << endl;
            return;
        }

        for (int i = 0; i < graph[cpos].size(); i++) {
            int npos = graph[cpos][i];

            if (visited[npos] == 0) {
                q.push(npos);
                visited[npos] = 1;
            }
        }
    }

    cout << "sad" << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        vector<pair<int, int>> node;
        vector<int> graph[102];
        cin >> n;
        for (int i = 0; i < n+2; i++) {
            cin >> x >> y;
            node.push_back({ x,y });
        }

        checkDist(graph, node);
        canGoFestival(graph,n+1);
    }
}