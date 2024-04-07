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
    
    int i=0;
    
    while(answer.length()!=t){
        while(tmp.length()<p){
            tmp += change(n,i);
            i++;
        }
        
        answer += tmp[p-1];
        p+=m;
    }
    
    return answer;
}