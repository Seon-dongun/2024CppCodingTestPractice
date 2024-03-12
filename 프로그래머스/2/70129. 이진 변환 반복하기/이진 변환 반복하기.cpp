#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string change(int cnt){
    string newStr = "";
    while(cnt>0){
        newStr+=((cnt%2)+'0');
        cnt/=2;
    }

    return newStr;
}

vector<int> solution(string s) {
    vector<int> answer;
    int zcnt = 0;
    int cycle = 0;
    while(s!="1"){
        int cnt=0;
        int len = s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='0')
                cnt++;
        }
        s = change(len - cnt);
        zcnt +=cnt;
        cycle++;
    }
    
    answer.push_back(cycle);
    answer.push_back(zcnt);
    return answer;
}
