#include <iostream>

using namespace std;

#define MAXNSIZE 1000
#define MAXINTSIZE 1000000

int T;
int N;
int numArr[MAXNSIZE][3];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> T;

	for (int test = 0; test < T; test++) 
	{
		int ans = 0;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> numArr[i][0] >> numArr[i][1] 
				>> numArr[i][2];
			int tmp = max(numArr[i][0], max(numArr[i][1], numArr[i][2]));
			if (tmp > 0) { ans += tmp; }
		}
		cout << ans << endl;
	}

	return 0;
}