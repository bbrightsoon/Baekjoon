#include <iostream>

using namespace std;

int N;
int numArr[1001];
int dp[1001];

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> numArr[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = numArr[i];
		for (int j = 1; j <= i; j++) {
			if (numArr[j] < numArr[i] && 
				dp[i] < dp[j] + numArr[i]) {
				dp[i] = dp[j] + numArr[i];
			}
		}
	}

	int max = -1;
	for (int i = 1; i <= N; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}

	cout << max << endl;

	return 0;
}