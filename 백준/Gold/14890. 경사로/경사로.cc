#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n, l,answer = 0;
vector<vector<int>> road;
int map[100][100];

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < n; i++) {
        vector<int> cul, row;
        for (int j = 0; j < n; j++) {
            cul.push_back(map[i][j]);
            row.push_back(map[j][i]);
        }

        road.push_back(cul);
        road.push_back(row);
    }
}

void checkRoad(vector<int>& road) {
    int curH = 0;
    vector<int> isSlideSet(road.size(),0);
    for (int i = 0; i < road.size(); i++) {
        if (i == road.size() - 1) {
            answer++;
            break;
        }

        if (abs(road[i] - road[i + 1]) > 1)
            return;
        
        if (road[i] - road[i+1] == 1) {
            bool canSetSlide = true;
            int tmp = road[i + 1];
            for (int j = i + 1; j < i + 1 + l; j++) {
                if (j >= n || tmp != road[j]) {
                    canSetSlide = false;
                    return ;
                }
            }

            if (canSetSlide) {
                for (int j = i + 1; j < i + 1 + l; j++)
                    isSlideSet[j] = 1;
            }
        }

        else if (road[i] - road[i + 1] == -1) {
            bool canSetSlide = true;
            int tmp = road[i];
            for (int j = i - l + 1; j <= i; j++) {
                if (j<0 || tmp != road[j] || isSlideSet[j]==1) {
                    canSetSlide = false;
                    return;
                }
            }

            if (canSetSlide) {
                for (int j = i - l + 1; j <= i; j++)
                    isSlideSet[j] = 1;
            }
        }
    }
}

int main() {
    int num;
    cin >> n >> l;

    init();

    for (int i = 0; i < road.size(); i++)
        checkRoad(road[i]);

    cout << answer << endl;
    return 0;
}