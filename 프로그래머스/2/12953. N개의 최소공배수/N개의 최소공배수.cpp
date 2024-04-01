#include <string>
#include <vector>

using namespace std;

int check(int a,int b){
    int n = a;
    int m = b;
    while(1){
        if(n==m)
            return n;      
        if(n<m)
            n+=a;
        else if(n>m)
            m+=b;
    }
}

int solution(vector<int> arr) {
    int answer = 0;
    for(int i=0;i<arr.size()-1;i++){
        answer = check(arr[i],arr[i+1]);
        arr[i+1] = answer;
    }
    return answer;
}