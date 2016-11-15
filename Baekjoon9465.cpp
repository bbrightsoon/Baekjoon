#include <iostream>

using namespace std;

#define MAXNSIZE 100000

int T;
int N;
int sticker[MAXNSIZE][2];
int memo[MAXNSIZE][3];		// 0 = ¾È¶À, 1 = ¿ÞÂÊ ¶À, 2 = ¿À¸¥ÂÊ ¶À

int max(int a, int b) { return a > b ? a : b; }

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> T;
	for (int test = 0; test < T; test++) 
	{
		cin >> N;
		for (int i = 0; i < N; i++) { cin >> sticker[i][0]; }
		for (int i = 0; i < N; i++) { cin >> sticker[i][1]; }
		memo[0][0] = 0;
		memo[0][1] = sticker[0][0];
		memo[0][2] = sticker[0][1];
		for (int i = 1; i < N; i++) {
			memo[i][0] = max(memo[i - 1][1], memo[i - 1][2]);
			memo[i][1] = max(memo[i - 1][0], memo[i - 1][2]) + sticker[i][0];
			memo[i][2] = max(memo[i - 1][0], memo[i - 1][1]) + sticker[i][1];
		}
		cout << max(memo[N - 1][1], memo[N - 1][2]) << endl;
	}
	return 0;
}