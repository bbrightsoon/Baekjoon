#include <iostream>
#include <cstring>

using namespace std;

int	T;
int W;

int jadoo[1001];
int dp[1001][2][31];

int max(int a, int b) { return a > b ? a: b; }

int getJadoo(int depth, int state, int remain) {
	if (depth == (T - 1)) {
		if (jadoo[depth] == state) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int ret = dp[depth][state - 1][remain];
	if (ret != -1) {
		return ret;
	}
	if (state == 1) {
		if (remain > 0) {
			if (getJadoo(depth + 1, 1, remain)
				< getJadoo(depth + 1, 2, remain - 1)) {
				ret = getJadoo(depth + 1, 2, remain - 1);
			}
			else {
				ret = getJadoo(depth + 1, 1, remain);
			}
		}
		else {
			ret = getJadoo(depth + 1, 1, remain);
		}
	}	
	else {
		if (remain > 0) {
			if (getJadoo(depth + 1, 2, remain)
				< getJadoo(depth + 1, 1, remain - 1)) {
				ret = getJadoo(depth + 1, 1, remain - 1);
			}
			else {
				ret = getJadoo(depth + 1, 2, remain);
			}
		}
		else {
			ret = getJadoo(depth + 1, 2, remain);
		}
	}

	if ((jadoo[depth] == state) && (depth != 0)) {
		ret++;
	}
	dp[depth][state - 1][remain] = ret;
	return ret;
}

int main() {

	cin >> T >> W;
	T++;

	memset(dp, -1, sizeof(dp));
	jadoo[0] = 1;
	for (int i = 1; i < T; i++) {
		cin >> jadoo[i];
	}
	
	cout << getJadoo(0, 1, W) << endl;

	return 0;
}