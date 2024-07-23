#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int visited[10001] = { 0, };

void FuncD(queue<pair<int, string>>& q, int curNum, string curStr) {
    int num = (2 * curNum) % 10000;
    if (visited[num] == 0) {
        q.push({ num, curStr + 'D' });
        visited[num] = 1;
    }
}

void FuncS(queue<pair<int, string>>& q, int curNum, string curStr) {
    int tmp = (curNum == 0 ? 9999 : curNum - 1);
    if (visited[tmp] == 0) {
        q.push({ tmp,curStr + 'S' });
        visited[tmp] = 1;
    }
}

void FuncL(queue<pair<int, string>>& q, int curNum, string curStr) {
    int num = (curNum%1000) * 10 + curNum/1000;
    if (visited[num] == 0) {
        q.push({ num,curStr + 'L' });
        visited[num] = 1;
    }
}

void FuncR(queue<pair<int, string>>& q, int curNum, string curStr) {
    int num = (curNum%10) * 1000 + curNum/10;
    if (visited[num] == 0) {
        q.push({ num,curStr + 'R' });
        visited[num] = 1;
    }
}
void check(int a, int b) {
    queue<pair<int, string>> q;
    q.push({ a,"" });
    visited[a] = 1;
    while (!q.empty()) {
        int curNum = q.front().first;
        string curStr = q.front().second;
        q.pop();

        if (curNum == b) {
            cout << curStr << '\n';
            break;
        }
 
        FuncD(q, curNum, curStr);
        FuncS(q, curNum, curStr);
        FuncL(q, curNum, curStr);
        FuncR(q, curNum, curStr);
    }
}

int main() {
    int t;
    int a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        memset(visited, 0, sizeof(visited));
        check(a, b);
    }
    return 0;
}