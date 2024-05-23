#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // for std::setprecision and std::fixed

using namespace std;

struct Pos {
    long long x, y;
};

double getArea(const vector<Pos>& positions) {
    double sum = 0.0;
    int n = positions.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        sum += positions[i].x * positions[j].y;
        sum -= positions[i].y * positions[j].x;
    }
    return fabs(sum) / 2.0;
}

int main() {
    int n;
    cin >> n;
    vector<Pos> positions(n);
    for (int i = 0; i < n; i++)
        cin >> positions[i].x >> positions[i].y;

    double area = getArea(positions);
    
    cout << fixed << setprecision(1) << area << endl;
    return 0;
}
