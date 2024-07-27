#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[1000001] = { 0, };
int main() {
    long long answer = 0;
    long long minV, maxV;

    cin >> minV >> maxV;

    for (long long i = 2; i*i <= maxV ; i++) {
        long long n = minV / (i * i);

        if (minV % (i * i) != 0)
            n++;

        while (n * i * i <= maxV) {
            num[n * i * i - minV] = 1;
            n++;
        }
    }

    for (long long i = 0; i <= maxV - minV; i++) {
        if (num[i] == 0)
            answer++;
    }

    cout << answer;
    return 0;
}