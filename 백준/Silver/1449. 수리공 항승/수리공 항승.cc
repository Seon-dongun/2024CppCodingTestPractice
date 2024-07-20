#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,l,answer=0;
    cin >> n >> l;
    int pipe[2002]={0,};
    vector<int> loc(n);
    
    for(int i=0;i<n;i++)
        cin >> loc[i];
    sort(loc.begin(),loc.end());
    
    for(int i=0;i<n;i++){
        if(pipe[loc[i]]==1)
            continue;
        
        for(int j=loc[i];j<loc[i]+l;j++)
            pipe[j] = 1;
        
        answer++;
    }
    cout << answer;
    return 0;
}