#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAXSIZE 21

int R;
int C;
int result = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
bool alphaFlag[26];
char alpha[MAXSIZE][MAXSIZE];

bool isRange(int x, int y) { return (x >= 0) && (x < R) && (y >= 0) && (y < C); };

bool chkAlpha(char ch) { return alphaFlag[ch - 'A'] == false; }

void DFS(int sx, int sy, int len) {
	for (int i = 0; i < 4; i++) {
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		if (isRange(nx, ny)) {
			if (chkAlpha(alpha[nx][ny])) {
				alphaFlag[alpha[nx][ny] - 'A'] = true;
				DFS(nx, ny, len + 1);
				alphaFlag[alpha[nx][ny] - 'A'] = false;
			}
		}
	}
	if (result < len) {	result = len; }
}

int main() {
	char buf[MAXSIZE];

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> buf;
		for (int j = 0; j < C; j++) {
			alpha[i][j] = buf[j];
		}
	}

	memset(alphaFlag, false, sizeof(alphaFlag));
	alphaFlag[alpha[0][0] - 'A'] = true;
	DFS(0, 0, 1);

	cout << result << endl;

	return 0;
}