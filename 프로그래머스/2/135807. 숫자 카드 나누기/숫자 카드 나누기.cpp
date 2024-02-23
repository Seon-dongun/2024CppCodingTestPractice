#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int check(vector<int>& arrayA, vector<int>& arrayB){
    int maxV = max(*max_element(arrayA.begin(),arrayA.end()),*max_element(arrayB.begin(),arrayB.end()));
    int result=0;

    for(int i=2;i<=maxV;i++){
        int tmp=1;    
        for(int j=0;j<arrayA.size();j++){
            if(arrayA[j]%i!=0 || arrayB[j]%i==0){
                tmp = 0;
                break;
            }
        }
        
        if(tmp!=1){
            tmp = 1;
            for(int j=0;j<arrayA.size();j++){
                if(arrayA[j]%i==0 || arrayB[j]%i!=0){
                    tmp = 0;
                    break;
                }
            }  
            
            if(tmp==1){
                if(result<i)
                    result = i;
            }        
        }
        else{
            if(result<i)
                result = i;
        }      
    }
    return result;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    return check(arrayA,arrayB);
}
// 위의 방식은 단순 반복 확인으로 풀기. 문제는 풀리나 런타임 시간이 너무 길다.
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
// 아래 방식은 각 배열에서의 최대공약수를 찾아주고, 상대 배열을 최대공약수로 나누어보며 조건에 올바른지 확인하는 방식. 런타임이 훨씬 짧다. 정석 풀이는 이게 맞는듯 하다.
#include <string>
#include <vector>
#define MAX(a, b) ((a > b) ? a : b)

using namespace std;

int gcd(int a, int b) { // 최대공약수 구하기
    int temp;
    while(b != 0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int findValue(vector<int>& v1, vector<int>& v2, int size) {
        
    int gcdValue = v1[0];
    
    for(int i = 1; i < size; i++) {
        gcdValue = gcd(gcdValue, v1[i]); // v1 배열에 대한 최대공약수를 찾는다.
        
        if(gcdValue == 1) return 0; // 만일 v1 배열에서 최대공약수가 1, 즉 사실상 최대공약수가 없는 상황이라면 문제 조건에 부합하지 않으므로 0 리턴
    }
    
    for(auto v : v2) { // v2배열을 v1배열에서 찾은 최대공약수로 나누어 떨어지는지 체크.
        if(v % gcdValue == 0) // 하나라도 나누어떨어지면 조건에 부합하지 않으므로 0 리턴
            return 0;
    }
    
    return gcdValue;
    
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int size = arrayA.size();
    
    int a = findValue(arrayA, arrayB, size);
    int b = findValue(arrayB, arrayA, size);
    
    return MAX(a, b); // 조건에 만족할 때, A가 기준인 경우와 B가 기준인 경우 중 더 큰 것이 답이다.
}
