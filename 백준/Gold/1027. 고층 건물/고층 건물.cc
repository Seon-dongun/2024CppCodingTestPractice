#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    vector<int> count(n, 0);
    for (int i = 0; i < n; i++) {
        double maxV = -1000000000;

        for (int j = i + 1; j < n; j++) {
            double g = ((num[j] - num[i])*1.0) / (j - i);
            if (g > maxV) {
                maxV = g;
                count[j]++;
                count[i]++;
            }
        }
    }
    cout << *max_element(count.begin(), count.end());
}