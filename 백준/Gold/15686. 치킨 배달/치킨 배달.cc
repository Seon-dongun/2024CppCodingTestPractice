#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    int street[51][51];
    vector<pair<int, int>> chickens;
    vector<pair<int, int>> homes;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> street[i][j];
            if (street[i][j] == 2)
                chickens.push_back({ i,j });
            else if (street[i][j] == 1)
                homes.push_back({ i,j });
        }
    }
    vector<vector<pair<int, int>>> chickenList;
    vector<bool> select(chickens.size(), false);
    fill(select.begin(), select.begin() + m, true);

    do {
        vector<pair<int, int>> current;
        for (int i = 0; i < chickens.size(); i++) {
            if (select[i])
                current.push_back(chickens[i]);
        }
        chickenList.push_back(current);
    } while (prev_permutation(select.begin(), select.end()));

    int minDist = 99999999;
    for (int i = 0; i < chickenList.size(); i++) {
        int totalDist = 0;
        for (int k = 0; k < homes.size(); k++) {
            int tmpMin=9999999;
            
            for (int j = 0; j < chickenList[i].size(); j++) {
                int chcR = chickenList[i][j].first;
                int chcC = chickenList[i][j].second;
                tmpMin = min(tmpMin,abs(chcR - homes[k].first) + abs(chcC - homes[k].second));
            }
            totalDist += tmpMin;
        }
        minDist = min(minDist, totalDist);
    }
    cout << minDist;
    return 0;
}