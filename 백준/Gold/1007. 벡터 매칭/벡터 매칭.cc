#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip> 
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        vector<pair<int, int>> v;
        cin >> n;
        vector<int> check(n);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            v.push_back({ x,y });
        }

        for (int i = n / 2; i <n ; i++)
            check[i] = 1;

        long long minLen = LLONG_MAX;
        do {
            pair<long long, long long> sum = { 0,0 };
            for (int i = 0; i < n; i++) {
                if (check[i] == 0) {
                    sum.first += v[i].first;
                    sum.second += v[i].second;
                }
                else {
                    sum.first -= v[i].first;
                    sum.second -= v[i].second;
                }
            }

            long long tmp = sum.first * sum.first + sum.second * sum.second;
            if(minLen > tmp)
                minLen = tmp;


        } while (next_permutation(check.begin(), check.end()));

        cout << fixed << setprecision(12) << sqrt(minLen) << endl;
    }
}