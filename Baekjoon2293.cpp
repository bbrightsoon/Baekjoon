#include <iostream>

using namespace std;

#define MAXNSIZE 101
#define MAXMSIZE 10001

int n;
int k;
int coin[MAXNSIZE];
int dp[MAXMSIZE] = {};

int main() {
	int min = 0x7fffffff;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) { cin >> coin[i]; }
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j >= coin[i]) {	dp[j] += dp[j - coin[i]]; }
		}
	}
	cout << dp[k] << endl;
	return 0;
}