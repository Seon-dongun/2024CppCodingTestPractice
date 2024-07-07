#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str;
    getline(cin,str);

    vector<string> list;
    vector<int> div;
    string tmp = "";
    int flag = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '<') {
            if (tmp != "") {
                list.push_back(tmp);
                div.push_back(0);
                tmp = "";
            }
            flag = 1;
            continue;
        }
        if (str[i] == '>') {
            div.push_back(2);
            list.push_back(tmp);
            tmp = "";
            flag = 0;
            continue;
        }
        if (str[i] == ' ' && flag==0) {
            list.push_back(tmp);
            div.push_back(1);
            tmp = "";
            continue;
        }

        if (i == str.length() - 1) {
            tmp += str[i];
            list.push_back(tmp);
            div.push_back(0);
        }

        tmp += str[i];
    }

    string answer = "";
    for (int i = 0; i < list.size(); i++) {
        if (div[i] == 0) {
            reverse(list[i].begin(), list[i].end());
            answer += list[i];
        }
        else if (div[i] == 1) {
            reverse(list[i].begin(), list[i].end());
            answer += list[i];
            answer += ' ';
        }
        else{
            answer += '<';
            answer += list[i];
            answer += '>';
        }
    }
    cout << answer << endl;
    return 0;
}