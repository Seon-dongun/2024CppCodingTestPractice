#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int map[1001][1001] = { 0, };
int maxlength = 0;			 

int main()
{
	string num; 
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		cin >> num;
		for (int j = 1; j <= m; j++)
			map[i][j] = num[j - 1] - '0';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			if (map[i][j] == 1){
				map[i][j] = min(min(map[i][j - 1], map[i - 1][j]), map[i - 1][j - 1]) + 1;
				maxlength = max(maxlength, map[i][j]);
			}
		}
	}

	cout << maxlength * maxlength << endl;
	return 0;
}