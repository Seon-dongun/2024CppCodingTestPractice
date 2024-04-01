#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> v;
    
    v.push_back(words[0]);
    for(int i=1;i<words.size();i++){
        if(find(v.begin(),v.end(),words[i])==v.end()){
            string tmp = v[v.size()-1];
            if(tmp[tmp.length()-1] == words[i][0])
                v.push_back(words[i]);
            else{
                if((i+1)%n==0)
                    answer.push_back(n);
                else
                    answer.push_back((i+1)%n);
                answer.push_back(ceil((float)(i+1)/n));
                return answer;
            }
        }
        else{
            if((i+1)%n==0)
                answer.push_back(n);
            else
                answer.push_back((i+1)%n);
            answer.push_back(ceil((float)(i+1)/n));
            return answer;
        }

    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}

-------------------------------------------------------------------------


#include <string>
#include <vector>
#include <map>
 
using namespace std;
 
vector<int> solution(int n, vector<string> words) {
    map<string, int> word;
    word[words[0]]++;
    for(int i=1; i<words.size(); i++){
        if(word[words[i]] || words[i].front() != words[i-1].back())
            return {(i%n)+1,(i/n)+1};
        word[words[i]]++;
    }
    return {0, 0};
}
