#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    if(s[0]==')')
        return false;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')
            st.push('(');
        else if(!st.empty() && s[i]==')')
            st.pop();
    }
    
    if(st.empty())
        return true;
    return false;
}