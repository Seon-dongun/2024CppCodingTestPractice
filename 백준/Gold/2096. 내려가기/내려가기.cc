#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, a,b,c,maxV, minV;
    cin >> n;
    int maxdp[3],mindp[3], tmp[3],tmp2[3];
    cin >> a >> b >> c;
    maxdp[0] = a;
    maxdp[1] = b;
    maxdp[2] = c;
    mindp[0] = a;
    mindp[1] = b;
    mindp[2] = c;

    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        tmp[0] = maxdp[0];
        tmp[1] = maxdp[1];
        tmp[2] = maxdp[2];

        maxdp[0] = a + max(tmp[0], tmp[1]);
        maxdp[1] = b + max(tmp[0], max(tmp[1], tmp[2]));
        maxdp[2] = c + max(tmp[1], tmp[2]);

        tmp2[0] = mindp[0];
        tmp2[1] = mindp[1];
        tmp2[2] = mindp[2];

        mindp[0] = a + min(tmp2[0], tmp2[1]);
        mindp[1] = b + min(tmp2[0], min(tmp2[1], tmp2[2]));
        mindp[2] = c + min(tmp2[1], tmp2[2]);
    }

    cout << max(maxdp[0], max(maxdp[1], maxdp[2])) << " " << min(mindp[0], min(mindp[1], mindp[2]));
}