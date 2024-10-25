#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> roop;
    int n,weight;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> weight;
        roop.push_back(weight);
    }
    
    sort(roop.begin(),roop.end());
    
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        int totalDivWeight = roop[i] * (roop.size()-i);
        answer = max(answer,totalDivWeight);
    }
    
    cout << answer;
    return 0;
}