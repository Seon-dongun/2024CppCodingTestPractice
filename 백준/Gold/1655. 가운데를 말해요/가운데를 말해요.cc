#include<iostream>
#include<queue>
using namespace std;

int n;
priority_queue<int> mx;
priority_queue<int, vector<int>, greater<int>> mn;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		if(mx.empty() || mx.size() == mn.size())
			mx.push(x);
		else
			mn.push(x);
		
		if(!mx.empty() && !mn.empty() && (mx.top() > mn.top())) {
			int a = mx.top();
			int b = mn.top();
			
			mx.pop();
			mn.pop();
			
			mx.push(b);
			mn.push(a);
		}
		cout << mx.top() << '\n';
	}
	return 0;
}