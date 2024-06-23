#include <iostream>
#define INF 987654321
using namespace std;
int money[101];
int dp[100001];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> money[i];
	
	for (int i = 1; i <= k; i++)
		dp[i] = INF;
	
	for (int i = 1; i <= n; i++) {
		for (int j = money[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - money[i]] + 1);
	}

	if (dp[k] == INF) 
		cout << -1;
	else 
		cout << dp[k];
}