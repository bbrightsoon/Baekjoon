#include <iostream>
#include <cstring>

using namespace std;

#define INF 987654321

int dp[1000][3];

int N;

struct payToPaint {
	int r, g, b;
};

payToPaint payList[1000];

int min(int a, int b) { return a > b ? b : a; }

int getExpense(int depth, int color) {
	if (depth == (N - 1)) {
		if (color == 0) {
			return payList[N - 1].r;
		}
		if (color == 1) {
			return payList[N - 1].g;
		}
		if (color == 2) {
			return payList[N - 1].b;
		}
	}
	int ret = dp[depth][color];
	if (ret != -1) {
		return ret;
	}
	//r
	if (color == 0) {
		return (dp[depth][color]
			= min(getExpense(depth + 1, 1), getExpense(depth + 1, 2))
			+ payList[depth].r);
	}
	//g
	if (color == 1) {
		return (dp[depth][color]
			= min(getExpense(depth + 1, 0), getExpense(depth + 1, 2))
			+ payList[depth].g);
	}
	//b
	if (color == 2) {
		return (dp[depth][color]
			= min(getExpense(depth + 1, 0), getExpense(depth + 1, 1))
			+ payList[depth].b);
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> payList[i].r >> payList[i].g >> payList[i].b;
	}
	memset(dp, -1, sizeof(dp));
	
	cout << min(min(getExpense(0, 0), getExpense(0, 1)), getExpense(0, 2))
		<< endl;

	return 0;
}