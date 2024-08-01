#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    int n,a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }

    int sum = 0;
    
    while(pq.size()!=1){
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        pq.push(a + b);
        sum += (a + b);
    }
    cout << sum;
}