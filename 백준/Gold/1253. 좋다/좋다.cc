#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,answer=0;
    cin >> n;
    
    vector<int> num(n);

    for(int i=0;i<n;i++)
        cin >> num[i];
     
    sort(num.begin(),num.end());
    
    for(int i=0;i<n;i++){
        int s=0,e=n-1;
        while(s<e){
            if (num[s] + num[e] < num[i])
				s++;		
			else if (num[s] + num[e] > num[i])
				e--;		
			else {
				if (s == i) 
                    s++;
				else if (e == i) 
                    e--;
				else {
					answer++;
					break;
				}
			}
        }
    }
    
    cout << answer;
    return 0;
}