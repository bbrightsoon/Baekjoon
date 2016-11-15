#include <iostream>
#include <cstring>

using namespace std;

#define MAXNSIZE 100000

int N;
int numArr[MAXNSIZE];
int memo[MAXNSIZE];		// [n][1] == 더함, [n][0] == 안더함
int ret = 0;

int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) { cin >> numArr[i]; }

	memset(memo, 0, sizeof(memo));
	memo[0] = max(0, numArr[0]);
	for (int i = 1; i < N; i++) {
		memo[i] = max(0, memo[i - 1] + numArr[i]);
		if (ret < memo[i]) { ret = memo[i]; }
	}
	if (ret == 0) {
		int max = -10000;
		for (int i = 0; i < N; i++) {
			if (max < numArr[i]) { max = numArr[i];	}
		}
		ret = max;
	}

	cout << ret << endl;

	return 0;
}