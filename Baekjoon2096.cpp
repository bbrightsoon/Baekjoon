#include <iostream>

using namespace std;

#define MAXNSIZE 100000
#define INF 0x7fffffff

int N;
int maxAns = -INF;
int minAns = INF;
int inputArr[MAXNSIZE][3];
int memo[MAXNSIZE][3];
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b, int c) { return (a > b ? a : b) > c ? (a > b ? a : b) : c; }
int min(int a, int b, int c) { return (a > b ? b : a) > c ? c : (a > b ? b : a); }

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) { cin >> inputArr[i][j]; }
	}
	for (int i = 0; i < 3; i++) { memo[N - 1][i] = inputArr[N - 1][i]; }
	for (int row = N - 2; row >= 0; row--) {
		memo[row][0] = max(memo[row + 1][0], memo[row + 1][1]) + inputArr[row][0];
		memo[row][1] = max(memo[row + 1][0], memo[row + 1][1], memo[row + 1][2]) + inputArr[row][1];
		memo[row][2] = max(memo[row + 1][1], memo[row + 1][2]) + inputArr[row][2];
	}
	for (int i = 0; i < 3; i++) {
		if (maxAns < memo[0][i]) { maxAns = memo[0][i]; }
	}
	for (int i = 0; i < 3; i++) { memo[N - 1][i] = inputArr[N - 1][i]; }
	for (int row = N - 2; row >= 0; row--) {
		memo[row][0] = min(memo[row + 1][0], memo[row + 1][1]) + inputArr[row][0];
		memo[row][1] = min(memo[row + 1][0], memo[row + 1][1], memo[row + 1][2]) + inputArr[row][1];
		memo[row][2] = min(memo[row + 1][1], memo[row + 1][2]) + inputArr[row][2];
	}
	for (int i = 0; i < 3; i++) {
		if (minAns > memo[0][i]) { minAns = memo[0][i]; }
	}
	cout << maxAns << " " << minAns << endl;
	return 0;
}