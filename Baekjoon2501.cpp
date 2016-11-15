#include <iostream>

using namespace std;

int N;
int K;

void printAns() {
	int count = 0;

	for (int i = 1; i <= N; i++) {
		if ((N % i) == 0) { count++; }
		if (count == K) {
			cout << i << endl;
			return;
		}
	}
	cout << 0 << endl;
}


int main() {
	cin >> N >> K;
	printAns();
	return 0;
}