#include <iostream>
using namespace std;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    long long value = 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);
    if (value > 0) return 1; // 반시계 방향
    else if (value < 0) return -1; // 시계 방향
    else return 0; // 일직선
}

// 3번 점 (x3, y3)가 1,2번 점을 이은 선분 (x1, y1) ~ (x2, y2) 위에 있는지 확인
// 기본적으로 해당 함수가 호출되려면 3번 점이 1,2번 점을 이은 선분과 일직선에 위치함을 만족해야됨
bool onSegment(int x1, int y1, int x2, int y2, int x3, int y3) {
    return min(x1, x2) <= x3 && x3 <= max(x1, x2) &&
           min(y1, y2) <= y3 && y3 <= max(y1, y2);
}

int main() {
    int x1, y1, x2, y2,x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int ccw1 = CCW(x1, y1, x2, y2, x3, y3);
    int ccw2 = CCW(x1, y1, x2, y2, x4, y4);
    int ccw3 = CCW(x3, y3, x4, y4, x1, y1);
    int ccw4 = CCW(x3, y3, x4, y4, x2, y2);

    if ((ccw1 * ccw2 < 0) && (ccw3 * ccw4 < 0))
        cout << 1;
    else if (ccw1 == 0 && onSegment(x1, y1, x2, y2, x3, y3))
        cout << 1;
    else if (ccw2 == 0 && onSegment(x1, y1, x2, y2, x4, y4))
        cout << 1;
    else if (ccw3 == 0 && onSegment(x3, y3, x4, y4, x1, y1))
        cout << 1;
    else if (ccw4 == 0 && onSegment(x3, y3, x4, y4, x2, y2))
        cout << 1;
    else
        cout << 0;

    return 0;
}