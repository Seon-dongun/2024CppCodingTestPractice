#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, m, cnt = 0;
    string s, check = "";
    cin >> n;
    cin >> m;
    cin >> s;

    for (int i = 0; i < n; i++)
        check += "IO";
    check += "I";

    int len = check.length();

    for (int i = 0; i < s.length() - len + 1; i++) {
        string tmp = s.substr(i,len);
        if (tmp == check)
            cnt++;
    }

    cout << cnt;
    return 0;
}