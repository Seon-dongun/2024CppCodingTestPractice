#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool alphaIncludeCheck(string skill, char alpha){
    for(int i=0;i<skill.length();i++){
        if(alpha==skill[i])
            return true;
    }
    return false;
}

bool check(string skill, string skill_tree){
    vector<char> str;
    stack<char> st;
    for(int i=0;i<skill_tree.length();i++){
        if(alphaIncludeCheck(skill, skill_tree[i]))
            str.push_back(skill_tree[i]);
    }
    
    for(int i=skill.length()-1;i>=0;i--)
        st.push(skill[i]);    
    
    while(!str.empty()){
        if(st.top()==str[0]){
            st.pop();
            str.erase(str.begin(),str.begin()+1);
        }
        else
            break;
    }
    
    if(str.empty())
        return true;
    else
        return false;  
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0;i<skill_trees.size();i++){
        if(check(skill,skill_trees[i])){
            cout << i << endl;
            answer++;
        }
    }  
    return answer;
}
