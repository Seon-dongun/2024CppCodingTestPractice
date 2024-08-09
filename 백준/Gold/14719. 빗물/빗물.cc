#include <iostream>
#include <vector>
using namespace std;

int main() {
    int w, h, water = 0;
    cin >> w >> h;
    vector<int> v(h);
    pair<int, int> maxPos = { -1,-1 };
    for (int i = 0; i < h; i++) {
        cin >> v[i];
        if (maxPos.second < v[i]) {
            maxPos.first = i;
            maxPos.second = v[i];
        }
    }

    int tmpH = v[0];
    for (int i = 0; i < maxPos.first; i++) {
        if (v[i] >= tmpH)
            tmpH = v[i];
        else
            water += (tmpH - v[i]);
    }

    tmpH = v[h - 1];
    for (int i = h - 1; i > maxPos.first; i--) {
        if (v[i] >= tmpH)
            tmpH = v[i];
        else 
            water += (tmpH - v[i]);
    }

    cout << water;
}