#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    string num;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> numbers;
        for (int i = 0; i < n; i++) {
            cin >> num;
            numbers.push_back(num);
        }

        sort(numbers.begin(), numbers.end());

        string answer = "YES";
        for (int i = 0; i < numbers.size()-1; i++) {
            int flag = 0;
            for (int j = 0; j < numbers[i].length(); j++) {
                if (numbers[i][j] != numbers[i + 1][j]) {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 0) {
                answer = "NO";
                break;
            }
        }
        cout << answer << endl;
    }
}
