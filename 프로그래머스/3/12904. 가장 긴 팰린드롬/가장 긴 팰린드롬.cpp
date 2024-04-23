#include <iostream>
#include <string>
using namespace std;
int answer;

int checkPalin(string s){
    if(answer>=s.length())
        return -1;
    
    for(int i=0,j=s.length()-1;i<s.length()/2;i++,j--){
        if(s[i]!=s[j])
            return -1;
    }
    
    return s.length();
}


int solution(string s)
{
    answer=0;
    
    for(int i=0;i<s.length();i++){
        string str = "";
        for(int j=i;j<s.length();j++){
            str += s[j];
            answer = max(answer,checkPalin(str));
        }
    }

    return answer;
}