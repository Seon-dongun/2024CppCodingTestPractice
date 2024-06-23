#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dp[10001];
int num[101];

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = num[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - num[i]];
		}
	}
	cout << dp[k];
}