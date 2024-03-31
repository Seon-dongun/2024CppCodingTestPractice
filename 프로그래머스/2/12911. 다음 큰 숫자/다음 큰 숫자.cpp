#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int check(int n){
    int cnt =0;
    while(n>0){
        if(n%2==1)
            cnt++;
        n/=2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int cnt1 = check(n);
    
    while(n<=1000000){
        n++;
        if(check(n)==cnt1)
            return n;
    }
}