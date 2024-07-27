#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	int n, m, k;
	cin >> n >> m;

	vector<string> v;
	map<string, int> table;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	cin >> k;
	for (int i = 0; i < n; i++) {
		int offLight = 0;
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '0')
				offLight++;
		}

		if (offLight > k || (offLight % 2 != k % 2))
			continue;

		if (table.find(v[i]) == table.end())
			table.insert({ v[i], 1});
		else
			table[v[i]]++;
	}

	int ans = 0;
	for (auto& j : table)
		ans = max(ans, j.second);
	
	cout << ans;
	return 0;
}