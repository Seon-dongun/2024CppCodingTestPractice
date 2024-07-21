#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#define INF 987654321
using namespace std;

struct info {
    int x, y, value;
};

int board[16][16];
int save[16][16];
int n, m, d;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
vector<vector<int>> getCombination(vector<int>& num, int k) {
    vector<vector<int>> result;
    vector<bool> bitmask(num.size(), false);
    fill(bitmask.begin(), bitmask.begin() + k, true); // 처음 k개의 원소를 true로 설정

    do {
        vector<int> combination;
        for (int i = 0; i < num.size(); ++i) {
            if (bitmask[i])
                combination.push_back(num[i]);
        }
        result.push_back(combination);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));

    return result;
}

void enemyMove() {
    for (int i = n-1; i >= 1; i--) {
        for (int j = 0; j < m; j++) {
            board[i][j] = board[i - 1][j];
        }
    }

    for (int i = 0; i < m; i++) {
        board[0][i] = 0;
    }
}
bool isAllZero(vector<pair<int,int>>& v) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                flag = false;
                v.push_back({ i,j });
            }
        }
    }
    return flag;
}

void findNearest(int pos, set<pair<int, int>>& s, vector<pair<int, int>>& v) {
    int x = n, y = pos;
    info minDist = { -1,-1,INF };
    for (int i = 0; i<v.size(); i++) {
        int dist = abs(v[i].first - x) + abs(v[i].second - y);
        if (dist <= d) {
            if (minDist.value > dist) {
                minDist.value = dist;
                minDist.x = v[i].first;
                minDist.y = v[i].second;
            }
            else if (minDist.value == dist) {
                if (minDist.y > v[i].second) {
                    minDist.x = v[i].first;
                    minDist.y = v[i].second;
                }
            }
        }
    }
    if(minDist.value!=INF)
        s.insert({minDist.x, minDist.y});
}

void clear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            board[i][j] = save[i][j];
    }
}

int attack(vector<int>& acherLocation) {
    int cnt = 0;
    clear();

    while (1) {
        set<pair<int, int>> s;
        vector<pair<int, int>> v;
        if (isAllZero(v)==true)
            break;

        for (int i = 0; i < 3; i++)
            findNearest(acherLocation[i], s,v);
        cnt += s.size();

        for (auto& deadEnemy : s)
            board[deadEnemy.first][deadEnemy.second] = 0;

        enemyMove();
    }
    

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> d;
    int answer = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            save[i][j] = board[i][j];
        }
    }

    vector<int> num;
    for (int i = 0; i < m; i++)
        num.push_back(i);

    vector<vector<int>> acher = getCombination(num, 3);

    for (int i = 0; i < acher.size(); i++)
        answer = max(answer, attack(acher[i]));

    cout << answer;
    return 0;
}