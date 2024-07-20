#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[2001][2001]={0,};
int num[2001];
int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int n,m,s,e;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> num[i];
        dp[i][i] = 1;
    }
    
    for (int i = 1; i <= n - 1; i++) {
        if (num[i] == num[i + 1])
            dp[i][i + 1] = 1;
    }
    
    for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (num[i] == num[j] && dp[i + 1][j - 1] == true) {
				dp[i][j] = 1;
			}
		}
	}
    
    cin >> m;
    while(m--){
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}