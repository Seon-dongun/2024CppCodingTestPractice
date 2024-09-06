#include <iostream>
using namespace std;

struct Egg {
    int hp; // 내구도
    int w; // 무게
};
int N;
Egg egg[10]; // 계란
int ans; // 깨진 개수

// x -> 현재 들고 있는 계란 번호
void backTracking(int x) {
    if (x > N + 1) 
        return;


    // 1 ~ N개의 계란을 모두 탐색(부딪히게 함)
    for (int i = 1; i <= N; i++) {
        // 들고 있는 계란이 이미 깨져 있으면 오른쪽 계란으로 백트래킹
        if (egg[x].hp <= 0) 
            backTracking(x + 1);
        // 자기 자신이랑 이미 깨진 계란은 패스
        else if (x == i || egg[i].hp <= 0) 
            continue;
        else {
            // 부딪힘
            egg[x].hp -= egg[i].w;
            egg[i].hp -= egg[x].w;
            backTracking(x + 1); // 해당 계란과 부딪힌 경우 백트래킹
            // 원상복구
            egg[x].hp += egg[i].w;
            egg[i].hp += egg[x].w;
        }
    }

    int tmp = 0;
    // 깨진 계란의 개수 세어줌
    for (int i = 1; i <= N; i++) {
        if (egg[i].hp <= 0) tmp++;
    }
    //최댓값 정답 저장
    ans = max(ans, tmp);
}
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        egg[i] = { v1,v2 };
    }
    backTracking(1);
    cout << ans;
}