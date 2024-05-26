#include <iostream>
using namespace std;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    long long value = 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);
    if (value > 0) return 1; // 반시계 방향
    else if (value < 0) return -1; // 시계 방향
}

int main() {
    int x1, y1, x2, y2,x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if ((CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4) < 0) && (CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2) < 0))
        cout << 1;
    else
        cout << 0;

    return 0;
}
