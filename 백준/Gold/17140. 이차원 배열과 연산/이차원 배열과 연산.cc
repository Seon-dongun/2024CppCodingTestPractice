#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void C(int board[101][101], int sizeX, int sizeY);



bool cmp(pair<int, int>& a ,pair<int, int>& b) {
    if (a.second < b.second)
        return true;
    else if (a.second > b.second)
        return false;
    else
        return a.first < b.first;
}

int r, c, k, t = 0;


void R(int board[101][101], int sizeX, int sizeY) {
    if (t > 100)
        return;

    if (board[r][c] == k)
        return;

    t++;
    int maxlen = 0;
    for (int i = 1; i <= sizeX; i++) {
        map<int, int> m;
        for (int j = 1; j <= sizeY; j++) {
            if (board[i][j] == 0)
                continue;
            m[board[i][j]]++;
        }
        vector<pair<int, int>> v;

        int j = 1;
        for (auto& tmp : m)
            v.push_back(tmp);

        sort(v.begin(), v.end(), cmp);

        for (int k = 0; k < v.size(); k++) {
            board[i][j++] = v[k].first;
            board[i][j++] = v[k].second;
        }

        while (j <= sizeY * 2)
            board[i][j++] = 0;

        if (m.size() > maxlen)
            maxlen = m.size();
    }
    sizeY = maxlen*2;

    if (sizeX >= sizeY)
        R(board, sizeX, sizeY);
    else
        C(board, sizeX, sizeY);
}

void C(int board[101][101], int sizeX, int sizeY) {
    if (t > 100)
        return;

    if (board[r][c] == k)
        return;

    t++;
    int maxlen = 0;
    for (int i = 1; i <= sizeY; i++) {
        map<int, int> m;
        for (int j = 1; j <= sizeX; j++) {
            if (board[j][i] == 0)
                continue;
            m[board[j][i]]++;
        }

        vector<pair<int, int>> v;

        int j = 1;
        for (auto& tmp : m)
            v.push_back(tmp);

        sort(v.begin(), v.end(), cmp);

        for (int k = 0; k < v.size(); k++) {
            board[j++][i] = v[k].first;
            board[j++][i] = v[k].second;
        }

        while (j <= sizeX * 2)
            board[j++][i] = 0;

        if (maxlen < m.size())
            maxlen = m.size();
    }
    sizeX = maxlen * 2;

    if (sizeX >= sizeY)
        R(board, sizeX, sizeY);
    else
        C(board, sizeX, sizeY);
}

int main() {
    int board[101][101];

    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> board[i][j];
        }
    }

    R(board, 3, 3);

    if (t > 100)
        cout << -1;
    else
        cout << t;
    return 0;
}