#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string str;
    map<string, int> m;
    double cnt = 0;
    while (1) {
        getline(cin, str);
        if (cin.eof() == true)
            break;
        m[str]++;
        cnt++;
    }

    for (auto& tmp : m)
        cout << tmp.first << " " << fixed << setprecision(4) << tmp.second / cnt * 100 << endl;
}