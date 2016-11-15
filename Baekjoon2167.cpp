#include <iostream>

using namespace std;

#define MAXNSIZE 300

int N;
int M;
int T;
int i, j, x, y;
int map[MAXNSIZE][MAXNSIZE];
int sumMap[MAXNSIZE][MAXNSIZE];

void setSumMap() {
	sumMap[0][0] = map[0][0];
	for (int row = 1; row < N; row++) { sumMap[row][0] = sumMap[row - 1][0] + map[row][0]; }
	for (int col = 1; col < M; col++) { sumMap[0][col] = sumMap[0][col - 1] + map[0][col]; }
	for (int row = 1; row < N; row++) {
		for (int col = 1; col < M; col++) { sumMap[row][col] = sumMap[row - 1][col] + sumMap[row][col - 1] - sumMap[row - 1][col - 1] + map[row][col]; }
	}
}
int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> map[row][col];
		}
	}
	setSumMap();
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		int ans = 0;
		cin >> i >> j >> x >> y;
		i--; j--; x--; y--;
		ans += sumMap[x][y];
		if (i != 0 && j != 0) { ans += sumMap[i - 1][j - 1]; }
		if (i != 0) { ans -= sumMap[i - 1][y]; }
		if (j != 0) { ans -= sumMap[x][j - 1]; }
		cout << ans << endl;
	}
	return 0;
}