#include <iostream>
using namespace std;

long long minV = 1000000001;
int flag=0;
void find(long long num, long long target,int cnt){
    if(num==target){
        flag = 1;
        if(cnt<minV)
            minV = cnt;
        return;
    }
    
    if(num>target)
        return;
    
    find(num*2,target,cnt+1);
    find((num*10)+1,target,cnt+1); 
    return;  
}

int main(){
    long long num, target;
    cin >> num >> target;
    find(num,target,1);
    if(flag)
        cout << minV;
    else
        cout << -1;
    return 0;
}