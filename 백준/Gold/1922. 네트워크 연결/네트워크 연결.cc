#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Node {
	int u,v,w;
}Node;

struct comp {
	bool operator()(Node& a, Node& b) {
		if (a.w > b.w)
			return true;
		else
			return false;
	}
};

int visited[10001];
vector<pair<int, int>> graph[10001];
priority_queue<Node,vector<Node>,comp> pq;
int vertex, e,cnt=0,minW = 0;

void prim(int idx) {
	for (int i = 0; i < graph[idx].size(); i++) {
		pq.push({ idx, graph[idx][i].first, graph[idx][i].second });
	}
	visited[idx] = 1;

	while (!pq.empty()) {
		if (cnt == vertex - 1)
			break;

		int v = pq.top().v;
		int cost = pq.top().w;
		pq.pop();

		if (visited[v] == 0) {
			minW += cost;
			cnt++;
			visited[v] = 1;
			for (int i = 0; i < graph[v].size(); i++) {
				pq.push({ v,graph[v][i].first,graph[v][i].second });
			}
		}
	}
	cout << minW;
}


int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int a, b, c;
	cin >> vertex >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	prim(1);
}