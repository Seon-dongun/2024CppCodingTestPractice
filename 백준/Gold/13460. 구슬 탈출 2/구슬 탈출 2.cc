#include<iostream>
#include<queue>
#define endl "\n"
using namespace std;

struct step
{
	int Rx, Ry;
	int Bx, By;
	int Count;
};

char map[11][11];
bool visit[11][11][11][11];
int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void move(int& rx, int& ry, int& distance, int& i)
{
	while (map[rx + dx[i]][ry + dy[i]] != '#' && map[rx][ry] != 'O')
	{
		rx += dx[i];
		ry += dy[i];
		distance += 1;
	}
}

void BFS(int Rx, int Ry, int Bx, int By){
	queue<step> q;
	q.push({ Rx,Ry,Bx,By,0 });
	visit[Rx][Ry][Bx][By] = true;

	while (!q.empty())
	{
		int rx = q.front().Rx;
		int ry = q.front().Ry;
		int bx = q.front().Bx;
		int by = q.front().By;
		int count = q.front().Count;
		q.pop();

		if (count >= 10) // 이동 횟수 초과
			break;

		for (int i = 0; i < 4; i++)
		{
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, ncount = count + 1;

			move(nrx, nry, rc, i); // 빨간 공 이동
			move(nbx, nby, bc, i); // 파란 공 이동

			if (map[nbx][nby] == 'O') // 파란 공이 구멍에 빠지면 안되므로 continue
				continue;

			if (map[nrx][nry] == 'O'){ // 파란 공은 구멍에 안빠지고 빨간 공만 구멍에 들어가면 성공
				cout << ncount;
				return;
			}

			// 만약에 두 공을 어느 한 방향 끝까지 이동했을 때 서로 같은 위치에 있다면, 
			// 둘 중 더 이동 거리가 긴 공이 바깥쪽, 거리가 짧은 공이 안쪽에 위치하게 된다.
			if (nrx == nbx && nry == nby){ 
				if (rc > bc) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (visit[nrx][nry][nbx][nby] == 0) {
				visit[nrx][nry][nbx][nby] = true;
				q.push({ nrx,nry,nbx,nby,ncount });
			}
		}
	}
	cout << -1;
}

void Answer()
{
	cin >> N >> M;
	int Rx = 0, Ry = 0, Bx = 0, By = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				Rx = i; 
				Ry = j;
			}
			else if (map[i][j] == 'B') {
				Bx = i; 
				By = j;
			}
		}
	}
	BFS(Rx, Ry, Bx, By);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Answer();
	return 0;
}
