#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;

	sort(targets.begin(), targets.end(), [&](vector<int> &v1, vector<int> &v2) {
		return v1[1] < v2[1];
	});
    
    int minVal = -1;
	
	for (int i = 0; i < targets.size(); i++) {
		int s = targets[i][0];
		int e = targets[i][1];
		
		if (minVal <= s) {
			answer++;
			minVal = e;
		}
	} 

	return answer;
}

