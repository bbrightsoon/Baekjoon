#include <iostream>
#include <queue>
#include <cstring>
#include <stdio.h>

using namespace std;

int nSize;
int mSize;

int map[1001][1001];
int visit[1001][1001][2];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

struct mapData {
	int x, y, l, flag;
};
queue<mapData> que;

void pushData(int xVal, int yVal, int lVal, int fVal) {
	mapData mD;
	mD.x = xVal;
	mD.y = yVal;
	mD.l = lVal;
	mD.flag = fVal;
	que.push(mD);
}

bool isRange(int xVal, int yVal) {
	return (xVal >= 0) && (xVal < nSize)
		&& (yVal >= 0) && (yVal < mSize);
}

void BFS() {
	visit[0][0][0] = 1;
	pushData(0, 0, 1, 0);
	int result = 1000001;

	while (!que.empty()) {
		mapData front = que.front();
		que.pop();
		/*
		if ((front.x == (nSize - 1))
		&& (front.y == (mSize - 1))) {
		result = front.l;
		break;
		}*/
//		printf("\n%d¹øÂ°ÁÙ : ", front.l);

		for (int i = 0; i < 4; i++) {
			int nX = front.x + dx[i];
			int nY = front.y + dy[i];
			int length = front.l;

			if (isRange(nX, nY)) {
				if (front.flag == 1) {
					if ((map[nX][nY] == 0) && (visit[nX][nY][1] == 0)) {
						//						printf("(%d, %d), ", nX, nY);
						visit[nX][nY][1] = 1;
						pushData(nX, nY, length + 1, front.flag);
						if ((nX == (nSize - 1))
							&& (nY == (mSize - 1))) {
							if (result > (front.l + 1)) {
								result = front.l + 1;
							}
						}
					}
				}
				else {
					if ((map[nX][nY] == 1) && visit[nX][nY][0] == 0) {
							visit[nX][nY][1] = 1;
							pushData(nX, nY, length + 1, 1);
							if ((nX == (nSize - 1))
								&& (nY == (mSize - 1))) {
							if (result > (front.l + 1)) {
								result = front.l + 1;
							}

						}
					}
					if ((map[nX][nY] == 0) && visit[nX][nY][0] == 0) {
						//						printf("(%d, %d), ", nX, nY);
						visit[nX][nY][0] = 1;
						pushData(nX, nY, length + 1, front.flag);
						if ((nX == (nSize - 1))
							&& (nY == (mSize - 1))) {
							if (result > (front.l + 1)) {
								result = front.l + 1;
							}
						}
					}
				}
			}
		}
	}
	if (result == 1000001) {
		cout << -1 << endl;
	}
	else {
		cout << result << endl;
	}
}

int main() {
	cin >> nSize >> mSize;

	for (int i = 0; i < nSize; i++) {
		for (int j = 0; j < mSize; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	memset(visit, 0, sizeof(visit));
	BFS();

	return 0;
}