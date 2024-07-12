#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int cnt = 0;
    int answer = 0;
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == '(' && str[i + 1] == ')') {
            answer += cnt;
            i++;
            continue;
        }

        if (str[i] == '(') {
            answer++;
            cnt++;
        }
        else {
            cnt--;
        }
    }
    cout << answer;
}