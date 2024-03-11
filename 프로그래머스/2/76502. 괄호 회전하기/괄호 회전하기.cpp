#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

void check(string s,int& answer){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(!st.empty()&& s[i]==')' && st.top()=='('){
            st.pop();
            continue;
        }
        
        else if(!st.empty()&& s[i]=='}' && st.top()=='{'){
            st.pop();
            continue;
        }
        
        else if(!st.empty()&& s[i]==']' && st.top()=='['){
            st.pop();
            continue;
        }        
        st.push(s[i]);
    }
    
    if(st.empty())
        answer++;
}

int solution(string s) {
    int answer = 0;

    for(int i=0;i<s.length();i++){
        check(s,answer);
        s = s.substr(1) + s[0];     
    }
    
    return answer;
}