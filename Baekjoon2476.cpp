#include <iostream>

using namespace std;

#define MAXPEOPLE 1000

int N;
int numArr[MAXPEOPLE][3];

int getMax(int a, int b) { return a > b ? a : b; }

int getSameCnt(int idx) {
	int countA = 0;
	int countB = 0;
	int countC = 0;
	int max = 0;

	for (int i = 0; i < 3; i++) {
		if (numArr[idx][i] == numArr[idx][0]) {countA++;}
		if (numArr[idx][i] == numArr[idx][1]) {countB++;}
		if (numArr[idx][i] == numArr[idx][2]) {countC++;}
	}

	return getMax(getMax(countA, countB), countC) - 1;
}

int getSameNum(int idx) {
	if (numArr[idx][0] == numArr[idx][1]) {
		return numArr[idx][0];
	}
	else if (numArr[idx][0] == numArr[idx][2]) {
		return numArr[idx][0];
	}
	else {
		return numArr[idx][1];
	}
}

int getMaxNum(int idx) {
	int max = (numArr[idx][0]);
	if (max < numArr[idx][1]) {	max = numArr[idx][1]; }
	if (max < numArr[idx][2]) {	max = numArr[idx][2]; }
	return max;
}

int main() {
	int ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> numArr[i][0] >> numArr[i][1] >> numArr[i][2];
	}
	for (int i = 0; i < N; i++) {
		if (getSameCnt(i) == 0) {
			if ((getMaxNum(i) * 100) > ans) {
				ans = getMaxNum(i) * 100;
			}
		} else if (getSameCnt(i) == 1) {
			if (ans < ((getSameNum(i) * 100) + 1000)) {
				ans = ((getSameNum(i) * 100) + 1000);
			}
		}
		else {
			if (ans < ((getSameNum(i) * 1000) + 10000)) {
				ans = ((getSameNum(i) * 1000) + 10000);
			}
		}
	}

	cout << ans << endl;

	return 0;
}