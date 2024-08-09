#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<int, int>> v;

int main() {
    int n, x, y;
    cin >> n;
    pair<int, int> maxPos = { -1,-1 };
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({ x,y });
        if (maxPos.second < y) {
            maxPos.first = x;
            maxPos.second = y;
        }
    }

    sort(v.begin(), v.end());

    int sum = 0;
    int tmpx = v[0].first;
    int tmpy = v[0].second;
    int i = 0;

    while (i<n) {
        if (tmpy <= v[i].second) {
            sum += ((v[i].first - tmpx) * tmpy);
            tmpx = v[i].first;
            tmpy = v[i].second;
        }

        i++;
    }

    i = n - 1;
    tmpx = v[i].first;
    tmpy = v[i].second;

    while (i>=0) {
        if (tmpy < v[i].second) {
            sum += ((tmpx-v[i].first) * tmpy);
            tmpx = v[i].first;
            tmpy = v[i].second;
        }

        i--;
    }

    cout << sum+maxPos.second << endl;
    return 0;
}