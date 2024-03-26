#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> s;
    for(int i=0;i<numbers.size();i++)
        s.push_back(to_string(numbers[i]));
    
    sort(s.begin(),s.end(),cmp);
    
    if(s[0]=="0")
        return "0";
    
    for(int i=0;i<s.size();i++)
        answer+=s[i];

    return answer;
}