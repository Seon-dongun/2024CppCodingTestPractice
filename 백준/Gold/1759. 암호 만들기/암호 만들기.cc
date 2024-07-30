#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool wordCheck(string str) {
    int mocnt = 0, zacnt = 0;
    char ch = str[0];
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u' || str[i] == 'i')
            mocnt++;
        else
            zacnt++;

        if (str[i] < ch)
            return false;
        else
            ch = str[i];
    }

    if (mocnt < 1 || zacnt < 2)
        return false;

    return true;
}
int main() {
    vector<char> words;
    int l, c;
    cin >> l >> c;

    vector<int> check(c, 0);

    for (int i = c - 1; i >= c - l; i--)
        check[i] = 1;

    char ch;
    for (int i = 0; i < c; i++) {
        cin >> ch;
        words.push_back(ch);
    }

    sort(words.begin(), words.end());

    vector<string> madeWord;
    do {
        string tmp = "";
        for (int i = 0; i < c; i++) {
            if (check[i]) {
                tmp += words[i];
            }
        }

        madeWord.push_back(tmp);
    } while (next_permutation(check.begin(), check.end()));

    sort(madeWord.begin(), madeWord.end());
    for (int i = 0; i < madeWord.size(); i++) {
        if(wordCheck(madeWord[i]))
            cout << madeWord[i] << endl;
    }
}