#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

string changeNum(int n,int k){
    string str = "";
    while(n>0){
        str+=n%k+'0';
        n/=k;
    }
    reverse(str.begin(),str.end());
    return str;
}

bool check(long num){
    if(num==1)
        return false;
    

    for(int i=2; i<=sqrt(num);i++){
        if(num%i==0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<int> nums;
    stringstream ss(changeNum(n,k));
    
    string tmp;
    while(getline(ss,tmp,'0')){
        if(tmp!="" && check(stol(tmp))){
            answer++;
        }
    }
    
    return answer;
}