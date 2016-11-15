#include <iostream>

using namespace std;

#define MAXNSIZE 1000

int N;
int maxNum = 0;
int ret = 0; 

int arrSize = 0;
int numArr[MAXNSIZE];
int memo[MAXNSIZE][2];		// 최댓값 저장


int getLeft(int idx) {
	int ret = 0;

	memo[0][0] = 0;
	memo[0][1] = numArr[0];

	for (int i = 1; i < idx; i++) {
		int maxLeft = 0;
		for (int j = 0; j < i; j++) {
			if (numArr[i] > numArr[j]) {
				if (maxLeft < memo[j][0]) {
					maxLeft = memo[j][0];
				}
			}
		}
		memo[0][idx] = maxLeft + 1;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> numArr[i];
		if (maxNum < numArr[i]) {
			maxNum = numArr[i];
		}
	}

	for (int i = 0; i < N; i++) {
		if (numArr[i] == maxNum) {
			int sum = 0;
			sum += getLeft(i);
			sum += getRight(i);
			if (sum > ret) {
				ret = sum;
			}
		}
	}
	
	
	
	
	cout << ret << endl;

	return 0;
}