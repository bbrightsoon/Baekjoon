#include <iostream>

using namespace std;

#define MAXNSIZE 1000

int N;
int ans = 0;
int numArr[MAXNSIZE];
int memo[MAXNSIZE];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) { cin >> numArr[i]; }

	memo[0] = 1;
	for (int i = 1; i < N; i++) {
		int minNum = 0;

		for (int j = 0; j < i; j++) {
			if (numArr[i] > numArr[j]) {
				if (minNum < memo[j]) {	minNum = memo[j]; }
			}
		}
		memo[i] = minNum + 1;
		if (ans < memo[i]) { ans = memo[i]; }
	}

	cout << ans << endl;
	return 0;
}