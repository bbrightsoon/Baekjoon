#include <iostream>
#include <cstring>
using namespace std;

#define MAXNSIZE 500
#define INF 0x7fffffff

int N;
int ans = -INF;
int triArr[(MAXNSIZE * (MAXNSIZE + 1)) / 2];
int memo[(MAXNSIZE * (MAXNSIZE + 1)) / 2];
int max(int a, int b) { return a > b ? a : b; }

int proc(int num, int depth) {
	if (depth == N - 1) { return triArr[(((depth + 1) * depth) / 2) + num];	}
	int &ret = memo[(((depth + 1) * (depth)) / 2) + num];
	if (ret != -1) { return ret; }
	ret = max(proc(num, depth + 1) + triArr[(((depth + 1) * depth) / 2) + num], proc(num + 1, depth + 1) + triArr[(((depth + 1) * (depth)) / 2) + num]);
	return ret;
}
int main() {
	cin >> N;
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < (N * (N + 1)) / 2; i++) { cin >> triArr[i]; }
	ans = proc(0, 0);
	cout << ans << endl;
	return 0;
}