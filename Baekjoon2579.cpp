#include <iostream>
#include <cstring>

using namespace std;
int dp[301][3];		// flag 0 = ºóÄ­, 1 = Ã¹Ä­, 2 = µÑÂ°Ä­
int score[301];	

int N;

int max(int a, int b) { return a > b ? a : b; }

int getScore(int step, int flag) {
	if ((step == N)) {
		if (flag != 0) {
			return score[step];
		}
		else {
			return -999999;
		}
	}

	int ret = dp[step][flag];
	if (ret != -1) {
		return ret;
	}

	if (flag == 0) {
		ret = getScore(step + 1, 1);
	}
	else if (flag == 1) {
		if (step == 0) {
			ret = max(getScore(step + 1, 0), getScore(step + 1, 1));
		}
		else {
			ret = max(getScore(step + 1, 0), getScore(step + 1, 2));
		}
	}
	else {
		ret = getScore(step + 1, 0);
	}
	if ((step != 0) && (flag != 0)) {
		ret += score[step];
	}
	dp[step][flag] = ret;
	return ret;
}

int main() {
	cin >> N;

	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		cin >> score[i];
	}

	cout << getScore(0, 1) << endl;



	return 0;
}