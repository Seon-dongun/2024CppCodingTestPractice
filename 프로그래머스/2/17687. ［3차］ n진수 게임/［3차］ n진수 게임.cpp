#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

char arr[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string change(int n,int num){
    string str = "";
    while(num>0){
        str += arr[num%n];
        num/=n;
    }
    reverse(str.begin(),str.end());
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "0";
    for(int i=1;i<=30000;i++)
        tmp += change(n,i);
    
    while(answer.length()!=t){
        answer += tmp[p-1];
        p+=m;
    }
    
    return answer;
}