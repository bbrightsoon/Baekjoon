#include <iostream>
#include <cstring>
#include <queue>
#include <stdlib.h>

using namespace std;

#define MAXSIZE 101
#define INF 987654321

int N;
int map[MAXSIZE][MAXSIZE];
int copy_map[MAXSIZE][MAXSIZE];
int island[MAXSIZE][MAXSIZE];
bool visit[MAXSIZE][MAXSIZE];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
struct mapData { int x, y, l; };

queue<mapData> que;

bool isRange(int x, int y) {
	return ((x >= 0) && (x < N) && (y >= 0) && (y < N));
}

bool isWaterSide(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isRange(nx, ny)) {
			if (map[nx][ny] == 0) {
				return true;
			}
		}
	}
	return false;
}

void enque(int x, int y) {
	mapData tmp;
	tmp.x = x;
	tmp.y = y;
	que.push(tmp);
}

int getShortestBridge(int x, int y) {
	int ret = INF;
	bool seaVisit[MAXSIZE][MAXSIZE];
	memset(seaVisit, false, sizeof(seaVisit));
	queue<mapData> tmpque;
	mapData tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.l = 0;
	tmpque.push(tmp);
	seaVisit[x][y] = true;

	while (!tmpque.empty()) {
		mapData front = tmpque.front();
		tmpque.pop();
		for (int i = 0; i < 4; i++) {
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];

			if (isRange(nx, ny)) {
				if ((map[nx][ny] == 1) && (island[nx][ny] == 0)) {
					ret = front.l;
					return ret;
				}
				if (map[nx][ny] == 0 && (seaVisit[nx][ny] == false)) {
					seaVisit[nx][ny] = true;
					tmp.x = nx;
					tmp.y = ny;
					tmp.l = front.l + 1;
					tmpque.push(tmp);
					
				}
			}
		}
	}
	return ret;
}

int searchIsland() {
	int ret = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((island[i][j] == 1) && isWaterSide(i, j)) {
				int tmp = getShortestBridge(i, j);
				if (tmp < ret) {ret = tmp;}
			}
		}
	}
	return ret;
}

int BFS(int sx, int sy) {
	island[sx][sy] = 1;
	visit[sx][sy] = 1;
	enque(sx, sy);

	while (!que.empty()) {
		mapData front = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];

			if (isRange(nx, ny)) {
				if ((visit[nx][ny] == false) && (map[nx][ny] == 1)) {
					island[nx][ny] = 1;
					visit[nx][ny] = true;
					enque(nx, ny);
				}
			}
		}
	}
	return searchIsland();
}

int main() {
	int result = INF;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	memset(visit, false, sizeof(0));
	memset(visit, 0, sizeof(0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((visit[i][j] == false) && (map[i][j] == 1)) {
				memset(island, 0, sizeof(island));
				int tmp = BFS(i, j);
				if (tmp < result) { result = tmp; }
			}
		}
	}

	cout << result << endl;
	return 0;
}