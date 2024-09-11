#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<int> positive;
vector<int> negative;
int answer =0;

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num <= 0)
            negative.push_back(num);
        else
            positive.push_back(num);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    sort(positive.begin(), positive.end(),greater<>());
    sort(negative.begin(), negative.end());


    for (int i = 0; i <(int)positive.size() - 1; i += 2) {
        if(positive[i+1]==1)
            answer += (positive[i] + positive[i + 1]);
        else
            answer += (positive[i] * positive[i + 1]);
    }

    if (positive.size() % 2 == 1)
        answer += positive[positive.size() - 1];


    for (int i = 0; i < (int)negative.size() - 1; i += 2)
        answer += (negative[i] * negative[i + 1]);

    if (negative.size() % 2 == 1)
        answer += negative[negative.size() - 1];

    cout << answer;
}