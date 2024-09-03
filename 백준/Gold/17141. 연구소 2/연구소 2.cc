#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
using namespace std;

struct info {
    int x, y, t;
};

int N, M;
int map[51][51];
int tmpmap[51][51];
int visited[51][51] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> virusPos;
vector<int> check;


void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << tmpmap[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void make_tmpmap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1)
                tmpmap[i][j] = -1;
            else
                tmpmap[i][j] = INF;
        }
    }
}

bool isAllSpread() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tmpmap[i][j] == INF)
                return false;
        }
    }
    return true;
}

int spreadVirus(vector<pair<int, int>> virusPos) {
    queue<info> q;
    int maxt = -1;
    for (int i = 0; i < virusPos.size(); i++) {
        tmpmap[virusPos[i].first][virusPos[i].second] = 0;
        q.push({ virusPos[i].first,virusPos[i].second,0 });
        visited[virusPos[i].first][virusPos[i].second] = 1;
    }

    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int ct = q.front().t;
        q.pop();

        maxt = max(maxt, ct);

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nt = ct + 1;

            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (tmpmap[nx][ny] != -1 && visited[nx][ny] == 0) {
                    if (tmpmap[nx][ny] > nt) {
                        tmpmap[nx][ny] = nt;
                        visited[nx][ny] = 1;
                        q.push({ nx,ny,nt });
                    }
                }
            }
        }
    }

    if (isAllSpread())
        return maxt;   

    return INF;
}

int main() {
    int minTime = INF;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virusPos.push_back({ i,j });
                check.push_back(0);
            }
        }
    }

    for (int i = 0; i <M;i++)
        check[i] = 1;
    sort(check.begin(), check.end());

    do {
        vector<pair<int, int>> selectVirusPos;
        for (int i = 0; i < check.size(); i++) {
            if (check[i] == 1)
                selectVirusPos.push_back(virusPos[i]);
        }
        
        make_tmpmap();
        memset(visited, 0, sizeof(visited));
        minTime = min(minTime, spreadVirus(selectVirusPos));

    } while (next_permutation(check.begin(), check.end()));

    cout << (minTime == INF ? -1 : minTime) << endl;
}