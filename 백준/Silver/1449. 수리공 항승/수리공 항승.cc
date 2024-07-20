#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    vector<int> loc(n);
    
    for(int i=0;i<n;i++)
        cin >> loc[i];
    sort(loc.begin(),loc.end());
    
    int cnt = 1;
    int start = loc[0];

    for(int i = 1; i < n; i++) {
        if(loc[i] - start + 1 > l) {
            cnt++;
            start = loc[i];
        }
    }
    cout << cnt;
    return 0;
}