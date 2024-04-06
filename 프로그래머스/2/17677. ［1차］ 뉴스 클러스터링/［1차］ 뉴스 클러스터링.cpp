#include <string>
#include <unordered_map>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

void checkGroup(unordered_map<string,int>& m, string str){
    for(int i=0;i<str.length()-1;i++){
        string tmp = "";
        if(isalpha(str[i])) tmp+=str[i];
        else continue;
        
        if(isalpha(str[i+1])) tmp+=str[i+1];
        else continue;
        
        m[tmp]++;
    }
}

void lower(string& str){
    for(int i=0;i<str.length();i++){
        if(isalpha(str[i]) && ('A'<=str[i]&&str[i]<='Z'))
            str[i] = tolower(str[i]);
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string,int> A,B;
    lower(str1);
    lower(str2);
    
    checkGroup(A,str1);
    checkGroup(B,str2);
    
    float hap=0,zip=0;
    for(auto tmp : A){
        if(B.find(tmp.first)==B.end()){
            hap+=A[tmp.first];
        }
        else{
            if(A[tmp.first]>=B[tmp.first]){
                hap+=A[tmp.first];
                zip+=B[tmp.first];
            }
            else{
                hap+=B[tmp.first];
                zip+=A[tmp.first];
            }
            
        }        
    }
    for(auto tmp : B){
        if(A.find(tmp.first)==A.end()){
            hap+=B[tmp.first];
        }    
    }
    
    if(hap==0 && zip==0)
        return 65536;
    
    int zacard = (zip/hap) * 65536;
    
    return zacard;
}