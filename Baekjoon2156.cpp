#include <iostream>
#include <cstring>
using namespace std;
#define MAXNSIZE 10000
int N;
int numArr[MAXNSIZE];
int memo[MAXNSIZE][3];	// 0 = 안마심, 1 = 마심, 2 = 2잔 연속 마심
int max(int a, int b) { return a > b ? a : b; }
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> numArr[i]; }
	memo[0][0] = 0;
	memo[0][1] = numArr[0];
	memo[1][0] = numArr[0];
	memo[1][1] = numArr[1];
	memo[1][2] = numArr[0] + numArr[1];
	for (int i = 2; i < N; i++) {
		memo[i][0] = max(memo[i - 1][0], max(memo[i - 1][1], memo[i - 1][2]));
		memo[i][1] = memo[i - 1][0] + numArr[i];
		memo[i][2] = memo[i - 1][1] + numArr[i];
	}
	cout << max(memo[N - 1][0], max(memo[N - 1][1], memo[N - 1][2])) << endl;
	return 0;
}