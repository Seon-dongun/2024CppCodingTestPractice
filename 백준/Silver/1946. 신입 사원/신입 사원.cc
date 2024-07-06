#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        int score, rank;
        cin >> n;
        vector<pair<int, int>> people(n);
        for (int i = 0; i < n; i++) {
            cin >> score >> rank;
            people[i] = { score,rank };
        }

        sort(people.begin(), people.end());

        int answer = 1;
        int tmp = people[0].second;
        for (int i = 1; i < n; i++) {
            if (people[i].second < tmp) {
                tmp = people[i].second;
                answer++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
