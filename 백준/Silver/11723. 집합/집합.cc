#include <iostream>
#include <string>
using namespace std;

int M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    int bitmask = 0;
    while (M--) {
        string str;
        int num;
        cin >> str;
        if (str == "add") {
            cin >> num;
            bitmask |= (1 << (num - 1));
        }
        else if (str == "remove") {
            cin >> num;
            bitmask &= ~(1 << (num - 1));
        }
        else if (str == "check") {
            cin >> num;
            if (bitmask & (1 << (num - 1))) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (str == "toggle") {
            cin >> num;
            if (bitmask & (1 << (num - 1))) 
                bitmask &= ~(1 << (num - 1));
            else 
                bitmask |= (1 << (num - 1));
        }
        else if (str == "all") {
            bitmask |= (1 << 20) - 1;
        }
        else if (str == "empty") {
            bitmask = 0;
        }
    }
}