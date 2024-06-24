#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int checkPalin(string str) {
    int isPalin = 1;
    for (int j = 0, k = str.length() - 1; j < str.length() / 2; j++, k--) {
        if (str[j] != str[k]) {
            isPalin = 0;
            break;
        }
    }
    return isPalin;
}

int main() {
    int n;
    string str[30];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];

        if (checkPalin(str[i]))
            cout << 0 << endl;

        else {
            for (int j = 0, k = str[i].length() - 1; j < str[i].length() / 2; j++, k--) {
                if (str[i][j] != str[i][k]) {
                    string fstr = str[i].substr(0, j) + str[i].substr(j + 1, str[i].length());
                    string estr = str[i].substr(0, k) + str[i].substr(k + 1, str[i].length());
                    int fout = checkPalin(fstr);
                    int eout = checkPalin(estr);

                    if (fout || eout)
                        cout << 1 << endl;
                    else
                        cout << 2 << endl;
                    break;
                }
            }
        }
    }

}