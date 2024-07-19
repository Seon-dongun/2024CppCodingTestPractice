#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

deque<int> belt;
deque<bool> robot;

int check() {
    int cnt = 0;
    for (int i = 0; i < belt.size(); i++) {
        if (belt[i] <= 0)
            cnt++;
    }
    return cnt;
}

void rotate(int n) {
    belt.push_front(belt.back());
    belt.pop_back();

    robot.push_front(robot.back());
    robot.pop_back();

    robot[n - 1] = false;
}

void robotMove(int n) {
    for (int i = n - 2; i >= 0; i--) {
        if (robot[i + 1] == false && belt[i + 1] > 0 && robot[i] == 1) {
            robot[i] = false;
            robot[i + 1] = true;
            belt[i + 1]--;
        }
   }
    robot[n - 1] = false;
}

void putRobot() {
    if (robot[0] == false && belt[0] > 0) {
        robot[0] = true;
        belt[0]--;
    }
}

int main() {
    int n, k, num;
    cin >> n >> k;
    for (int i = 0; i < n*2; i++) {
        cin >> num;
        belt.push_back(num);
        robot.push_back(false);
    }
    

    int answer = 0;
    while (1) {
        if (check() >= k)
            break;

        rotate(n);
        robotMove(n);
        putRobot();

        answer++;
    }
    cout << answer;
}
