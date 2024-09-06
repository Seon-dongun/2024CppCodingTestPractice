#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<vector<int>> numlist;
        vector<int> num(n);
        vector<int> select(n);
        for (int i = 0; i < n; i++)
            cin >> num[i];

        for (int i = n - 1; i >= n - 6; i--)
            select[i] = 1;

        do {
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                if (select[i] == 1)
                    tmp.push_back(num[i]);
            }
            numlist.push_back(tmp);
        } while (next_permutation(select.begin(), select.end()));


        for (int i = numlist.size() - 1; i >= 0; i--) {
            for (int j = 0; j < numlist[i].size(); j++)
                cout << numlist[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
}