#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int maps[12][6];
map<char, int> m = { {'.',0},{'R',1},{'G',2},{'B',3},{'P',4},{'Y',5} };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int flag;

void setDown() {
    for (int i = 0; i < 6; i++) {
        stack<int> st;
        for (int j = 0; j < 12; j++) {
            if (maps[j][i] == 0)
                continue;
            st.push(maps[j][i]);
            maps[j][i] = 0;
        }

        int j = 11;
        while(!st.empty()){
            maps[j][i] = st.top();
            st.pop();
            j--;
        }
    }
}

void bfs(int x, int y, int (&visited)[12][6]) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> del;
    int color = maps[x][y];
    visited[x][y] = 1;
    q.push({ x,y });

    int cnt = 0;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        del.push_back({ cx,cy });
        cnt++;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < 12 && 0 <= ny && ny < 6 && maps[nx][ny] == color && visited[nx][ny] == 0) {
                q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }

    if (cnt >= 4) {
        for (int i = 0; i < del.size(); i++)
            maps[del[i].first][del[i].second] = 0;
        flag = 1;
    }
}

int main() {
    string str;
    for (int i = 0; i < 12; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            maps[i][j] = m[str[j]];
        }
    }

    int combo = 0;
    while (1) {
        int visited[12][6] = { 0, };
        flag = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (maps[i][j] == 0)
                    continue;

                bfs(i, j, visited);
            }
        }
        if (flag == 0)
            break;

        setDown();
        combo++;
    }

    cout << combo << endl;
    return 0;
}