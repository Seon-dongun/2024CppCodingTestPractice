#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<long long ,vector<long long>,greater<long long>> pq;
int main(){
    int n,m,num;
    cin >> n >> m;
    vector<int> card(n);
    
    for(int i=0;i<n;i++){
        cin >> num;
        pq.push(num);
    }
    
    long long a,b,add;
    while(m--){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        add = a+b;
        pq.push(add);
        pq.push(add);
    }
    
    long long answer = 0;
    while(!pq.empty()){
        answer+=pq.top();
        pq.pop();
    }
    cout << answer;
    return 0;
}