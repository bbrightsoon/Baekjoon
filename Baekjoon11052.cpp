#include <iostream>

using namespace std;

#define MAXNSIZE 1001

int n;
int priceArr[MAXNSIZE];
int dp[MAXNSIZE];
int ans = 0;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> priceArr[i]; }
	dp[0] = 0;
	dp[1] = priceArr[1];
	for (int i = 2; i <= n; i++) {
		int max = 0;
		dp[i] = priceArr[i];
		for (int j = 0; j <= i / 2; j++) { if (max < dp[j] + dp[i - j]) { max = dp[j] + dp[i - j]; } }
		dp[i] = max;
	}
	cout << dp[n] << endl;
	return 0;
}