#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void check(vector<int> (&graph)[1001],vector<int>& entry, int w, int n,vector<int>& delay,int& answer) {
	queue<int> q;
	vector<int> result(1001, 0);
	for (int i = 1; i <= n; i++) {
		if (entry[i] == 0) {
			q.push(i);
			result[i] = delay[i];
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		if (u == w)
			break;

		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i];
			result[v] = max(result[v], result[u] + delay[v]);
			entry[v]--;

			if (entry[v] == 0)
				q.push(v);
		}
	}
	cout << result[w] << endl;
}

int main() {
	int t, n, k,s,e,w;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> delay(1001,0);
		vector<int> graph[1001];
		vector<int> entry(1001, 0);
		int answer = 0;
		for (int i = 1; i <= n; i++) {
			cin >> delay[i];
		}

		for (int i = 0; i < k; i++) {
			cin >> s >> e;
			graph[s].push_back(e);
			entry[e]++;
		}

		cin >> w;

		check(graph,entry,w,n,delay,answer);
	}
}