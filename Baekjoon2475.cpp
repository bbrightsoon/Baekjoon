#include <iostream>
#include <math.h>

using namespace std;

#define NUMSIZE 5

int numArr[NUMSIZE];

int main() {
	int ans = 0;

	for (int i = 0; i < NUMSIZE; i++) {
		cin >> numArr[i];
		ans += pow(numArr[i], 2);
	}

	ans %= 10;

	cout << ans << endl;

	return 0;
}