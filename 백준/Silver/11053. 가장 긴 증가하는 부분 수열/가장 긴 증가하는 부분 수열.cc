#include <iostream>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int maxlength = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxlength = max(dp[i], maxlength);
    }
    cout << maxlength << "\n";
}