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
    
    int s = 0, e = 0;
    int answer = 2000001000;
    while(s<n && e < n)
    {
        if(num[e]-num[s] >= m)
        {
            answer = min(answer,num[e]-num[s]);
            s++;
        }
        else 
            e++;
    }
    cout << answer;
    return 0;
}