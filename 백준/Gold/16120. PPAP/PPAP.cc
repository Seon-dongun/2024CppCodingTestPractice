#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string str;

int main() {
    cin >> str;

    stack<char> st;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'P') {
            st.push('P');
            cnt++;
        }
        else {
            if (cnt >= 2 && str[i + 1] == 'P') {
                st.pop();
                st.pop();
                st.push('P');
                cnt -= 1;
                i++;
            }
            else
                st.push('A');
        }        
    }
    
    string tmp = "";
    while (!st.empty()) {
        tmp += st.top();
        st.pop();
    }

    reverse(tmp.begin(), tmp.end());

    if (tmp=="PPAP" || tmp=="P")
        cout << "PPAP";
    else
        cout << "NP";
}