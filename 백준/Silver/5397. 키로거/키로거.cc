#include <iostream>
#include <string>
#include <list>
using namespace std;
int main() {
    int n;
    string str;
    cin >> n;

    while (n--) {
        cin >> str;
        int loc = 0;
        list<char> password;
        list<char>::iterator it;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '<') {
                if (password.empty())
                    continue;

                if (it != password.begin())
                    it--;
            }
            else if (str[i] == '>') {
                if (password.empty())
                    continue;

                if (!password.empty() && it != password.end())
                    it++;
            }
            else if (str[i] == '-') {
                if (password.empty() || it == password.begin())
                    continue;

                if(it!=password.begin())
                    it--;
                it = password.erase(it);
        
            }
            else {
                if (password.empty()) {
                    password.push_back(str[i]);
                    it = password.end();
                }
                else
                    password.insert(it, str[i]);
            }
        }
        
        for (it = password.begin(); it!=password.end(); it++)
            cout << *it;
        cout << endl;
    }

}