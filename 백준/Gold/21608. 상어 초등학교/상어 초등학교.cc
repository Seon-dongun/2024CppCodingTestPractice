#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0, };
int seat[20][20] = { 0, };
vector<vector<int>> like;
unordered_map<int, vector<int>> m;

void rule3(vector<int>& info, vector<pair<int, int>>& maxPos) {
    int x = maxPos[0].first;
    int y = maxPos[0].second;

    for (int i = 1; i < maxPos.size(); i++) {
        if (x > maxPos[i].first) {
            x = maxPos[i].first;
            y = maxPos[i].second;
        }
        else if (x == maxPos[i].first) {
            if (y > maxPos[i].second)
                y = maxPos[i].second;
        }
    }

    seat[x][y] = info[0];
}

void rule2(vector<int>& info,vector<pair<int,int>>& maxPos) {
    vector<pair<int, int>> maxPos2;
    int maxCnt = -1;

    for (int i = 0; i < maxPos.size(); i++) {
        int cx = maxPos[i].first;
        int cy = maxPos[i].second;

        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            int nx = cx + dx[j];
            int ny = cy + dy[j];
            
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (seat[nx][ny] == 0)
                    cnt++;
            }
        }

        if (maxCnt < cnt) {
            maxPos2.clear();
            maxPos2.push_back({ cx,cy });
            maxCnt = cnt;
        }
        else if (maxCnt == cnt)
            maxPos2.push_back({ cx,cy });
    }

    if (maxPos2.size() == 1)
        seat[maxPos2[0].first][maxPos2[0].second] = info[0];
    else
        rule3(info, maxPos2);
}

void rule1(vector<int>& info) {
    vector<pair<int, int>> maxPos;
    int maxCnt = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (seat[i][j] != 0)
                continue;

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (find(info.begin() + 1, info.end(), seat[nx][ny]) != info.end())
                        cnt++;
                }
            }

            if (maxCnt < cnt) {
                maxPos.clear();
                maxPos.push_back({ i, j });
                maxCnt = cnt;
            }
            else if (maxCnt == cnt)
                maxPos.push_back({ i,j });
        }
    }

    if (maxPos.size() == 1)
        seat[maxPos[0].first][maxPos[0].second] = info[0];
    else
        rule2(info,maxPos);
}


int cul() {
    int value = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    vector<int> tmp = m[seat[i][j]];
                    if (find(tmp.begin(), tmp.end(), seat[nx][ny]) != tmp.end())
                        cnt++;
                }
            }

            if (cnt == 1)
                value += 1;
            else if (cnt == 2)
                value += 10;
            else if (cnt == 3)
                value += 100;
            else if (cnt == 4)
                value += 1000;
        }
    }
    return value;
}

int main() {
    cin >> n;
    int num;
    for (int i = 0; i < n * n; i++) {
        vector<int> tmp;
        for (int j = 0; j < 5; j++) {
            cin >> num;
            tmp.push_back(num);
        }
        m.insert({ tmp[0], { tmp[1],tmp[2],tmp[3],tmp[4] } });
        like.push_back(tmp);
    }


    for (int i = 0; i < like.size(); i++)
        rule1(like[i]);

    cout << cul();
}