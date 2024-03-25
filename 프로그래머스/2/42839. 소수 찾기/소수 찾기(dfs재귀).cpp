#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
int visited[7] = {0};
set<int> s;

bool numCheck(int num){
    if(num<=1)
        return false;
    
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return false;         
    }
    return true;
}

void check(string numbers, string str){
    if(!str.empty()){
        int num = stoi(str);
        if(numCheck(num))
            s.insert(num);
    }
    
    if(str.length() == numbers.length())
        return;
    
    for(int i=0;i<numbers.length();i++){
        if(visited[i]==0){
            visited[i] = 1;
            check(numbers,str+numbers[i]);
            visited[i] = 0;
        }
    }
}

int solution(string numbers) {
    string tmp = "";
    check(numbers,tmp);
    return s.size();
}
