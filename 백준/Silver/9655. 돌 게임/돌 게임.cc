#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,DP[1000];
    cin >> N;
    
    DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= N; i++)
		DP[i] = min(DP[i - 1] + 1, DP[i - 3] + 1);

	if (DP[N] % 2 == 1)
		cout << "SK";
	else
		cout << "CY";
    return 0;
}