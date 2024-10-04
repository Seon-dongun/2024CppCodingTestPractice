#include <iostream>
#include <algorithm>

using namespace std;
int num[100000];

int main()
{
    int n,m;
    cin>> n >> m;
    
    for(int i=0;i<n;i++)
        cin >> num[i];
    
    sort(num,num+n);
    
    int s = 0, e = 1;
    int answer = 2000001000;
    while(s<=e && e < n)
    {
        if(abs(num[s]-num[e]) >= m)
        {
            answer = min(answer,abs(num[s]-num[e]));
            s++;
            e = s+1;
        }
        else 
            e++;
    }
    cout << answer;
    return 0;
}