// 2016-10-11
// 01:03:48

#include <iostream>

using namespace std;

int rowSize;
int colSize;
int startX;
int startY;
int destX;
int destY;
int rear, front;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int xQueue[2501];
int yQueue[2501];
int tQueue[2501];

char map[51][51];
int visit[51][51];
char copyMap[51][51];
char saveArr[51][51];

void pushQueue(int xVal, int yVal) {
	xQueue[rear] = xVal;
	yQueue[rear] = yVal;
	tQueue[rear] = tQueue[front] + 1;
	rear++;
}

void getInput(int row, int col) {
	char buff[51];

	for (int i = 0; i < row; i++) {
		cin >> buff;
		for (int j = 0; j < col; j++) {
			map[i][j] = buff[j];
			copyMap[i][j] = buff[j];
			if (buff[j] == 'S') {
				startX = i;
				startY = j;
			}
			if (buff[j] == 'D') {
				destX = i;
				destY = j;
			}
		}
	}
}

bool isRange(int xVal, int yVal) {
	if ((xVal < rowSize) && (xVal >= 0)) {
		if (((yVal < colSize) && (yVal >= 0))) {
			return true;
		}
	}
	return false;
}

void waterBFS(int xVal, int yVal) {
	for (int i = 0; i < 4; i++) {
		int nX = xVal + dx[i];
		int nY = yVal + dy[i];
		if (isRange(nX, nY)) {
			if ((saveArr[nX][nY] == '.')) {
				copyMap[nX][nY] = '*';
			}
		}
	}

}	

void refreshCopyMap(int time) {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			copyMap[i][j] = map[i][j];
		}
	}

	for (int rnd = 0; rnd < time; rnd++) {
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				saveArr[i][j] = copyMap[i][j];
			}
		}
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (saveArr[i][j] == '*') {
					waterBFS(i, j);
				}
			}
		}
	}
}

void BFS(int sX, int sY) {
	front = 0;
	rear = 0;

	visit[sX][sY] = 1;
	pushQueue(sX, sY);
	tQueue[0] = 0;

	while (front != rear) {
		refreshCopyMap(tQueue[front] + 1);
		if ((xQueue[front] == destX)
			&& (yQueue[front] == destY)) {
			cout << tQueue[front] << endl;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nX = xQueue[front] + dx[i];
			int nY = yQueue[front] + dy[i];

			if (isRange(nX, nY)) {
				if ((visit[nX][nY] != 1)
					&& ((copyMap[nX][nY] == '.')
						|| (copyMap[nX][nY] == 'D'))) {
					visit[nX][nY] = 1;
					pushQueue(nX, nY);
				}
			}
		}
		front++;
	}
	cout << "KAKTUS" << endl;
}

int main() {
	cin >> rowSize >> colSize;

	getInput(rowSize, colSize);

	BFS(startX, startY);

	return 0;
}