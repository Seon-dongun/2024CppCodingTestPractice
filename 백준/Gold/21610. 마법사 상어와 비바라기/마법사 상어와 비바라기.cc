#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct cloud {
    int x, y;
};

vector<cloud> clouds;
int map[51][51];
int visited[51][51] = { 0, };

int n, m;

int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int diadx[4] = { -1,-1,1,1 };
int diady[4] = { -1,1,-1,1 };

void make_cloud() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j] && map[i][j] >= 2) {
                map[i][j] -= 2;
                clouds.push_back({ i,j});
            }
        }
    }

    memset(visited, 0, sizeof(visited));
}

void move_and_rain(int d, int s) {
    for (int i = 0; i < clouds.size(); i++) {
        int cx = clouds[i].x;
        int cy = clouds[i].y;
        int actualMove = s % n;

        int nx = cx + actualMove * dx[d];
        int ny = cy + actualMove * dy[d];
        if (nx < 1) nx += n;
        if (ny < 1) ny += n;
        if (nx > n) nx -= n;
        if (ny > n) ny -= n;
        clouds[i].x = nx;
        clouds[i].y = ny;
        map[nx][ny]++;
        visited[nx][ny] = 1;
    }
}

void water_copy() {
    for (int i = 0; i < clouds.size(); i++) {
        int cnt = 0;

        int cx = clouds[i].x;
        int cy = clouds[i].y;

        for (int j = 0; j < 4; j++) {
            int nx = cx + diadx[j];
            int ny = cy + diady[j];

            if (nx < 1 || ny < 1 || nx > n || ny > n)
                continue;

            if (map[nx][ny] != 0)
                cnt++;
        }

        map[cx][cy] += cnt;
    }
}

int main() {
    int answer = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    }

    int d, s;
    clouds.push_back({ n,1});
    clouds.push_back({ n,2,});
    clouds.push_back({ n - 1,1});
    clouds.push_back({ n - 1,2,});

    for (int i = 0; i < m; i++) {
        cin >> d >> s;

        move_and_rain(d - 1, s);
        water_copy();

        clouds.clear();
        make_cloud();
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            answer += map[i][j];
    }
    cout << answer;
}