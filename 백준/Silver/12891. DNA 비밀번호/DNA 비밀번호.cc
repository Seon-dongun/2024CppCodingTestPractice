#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    int s,p,answer=0;
    int cnt[4];
    char alpha[4] = {'A','C','G','T'};
    string str;
    cin >> s >> p;
    cin >> str;
    cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];
    
    unordered_map<char,int> m;
    for(int i=0;i<p;i++)
        m[str[i]]++;
    
    for(int i=0;i<=str.length()-p;i++){
        int tmp = 1;
          
        for(int i=0;i<4;i++){
            if(m[alpha[i]]<cnt[i]){
                tmp = 0;
                break;
            }
        }
        
        if(tmp==1)
            answer++;
        
        m[str[i]]--;
        m[str[i+p]]++;
    }
    
    cout << answer;
    return 0;
}