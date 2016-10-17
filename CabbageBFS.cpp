// 20161011
// 0:19:18

#include <iostream>

using namespace std;

int mSize;
int nSize;
int cabbageSize;
int wormCount;
int front, rear;

int xQueue[2501];
int yQueue[2501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int visit[51][51];
int map[51][51];

bool isRange(int xVal, int yVal) {
	if ((xVal >= 0) && (xVal < mSize)) {
		if ((yVal >= 0) && (yVal < nSize)) {
			return true;
		}
	}
	return false;
}

void pushQueue(int xVal, int yVal) {
	xQueue[rear] = xVal;
	yQueue[rear] = yVal;
	rear++;
}

void clearVisit() {
	for (int i = 0; i < mSize; i++) {
		for (int j = 0; j < nSize; j++) {
			visit[i][j] = 0;
		}
	}
}

void clearMap() {
	for (int i = 0; i < mSize; i++) {
		for (int j = 0; j < nSize; j++) {
			map[i][j] = 0;
		}
	}
}

void BFS(int sX, int sY) {
	front = 0;
	rear = 0;

	visit[sX][sY] = 1;
	pushQueue(sX, sY);

	while (front != rear) {
		for (int i = 0; i < 4; i++) {
			int nX = xQueue[front] + dx[i];
			int nY = yQueue[front] + dy[i];
			if (isRange(nX, nY)) {
				if ((visit[nX][nY] != 1) && (map[nX][nY] == 1)) {
					visit[nX][nY] = 1;
					pushQueue(nX, nY);
				}
			}
		}
		front++;
	}
	wormCount++;
}

int main() {
	int testCase;
	int inputX, inputY;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		wormCount = 0;

		cin >> mSize;
		cin >> nSize;
		cin >> cabbageSize;

		clearMap();
		for (int j = 0; j < cabbageSize; j++) {
			cin >> inputX;
			cin >> inputY;
			map[inputX][inputY] = 1;
		}
		
		clearVisit();
		for (int i = 0; i < mSize; i++) {
			for (int j = 0; j < nSize; j++) {
				if ((visit[i][j] != 1) && (map[i][j] == 1)) {
					BFS(i, j);
				}
			}
		}
		cout << wormCount << endl;
	}

	

	return 0;
}