#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') 
            st.push(-1);
        else if('0'<=s[i]&&s[i]<='9'){
            if(i<s.size()-1 && s[i+1]=='(') 
                st.push(s[i]-'0');
            else 
                st.push(1);
        }
        else{
            int len=0;
            while(st.top()!=-1) {
                len+=st.top();
                st.pop();
            }
            st.pop();
            len*=st.top(); 
            st.pop();
            st.push(len);
        }
    }
    
    int ans=0;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout << ans << endl;
}