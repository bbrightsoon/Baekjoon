#include <iostream>

using namespace std;

int N;
int numArr[100];
void proc() {
	int sum = 0;
	int combo = 0;

	for (int i = 0; i < N; i++) {
		if (numArr[i] == 1) {
			combo++;
			sum += combo;
		}
		else {
			combo = 0;
		}
	}
	cout << sum << endl;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) { cin >> numArr[i]; }

	proc();

	return 0;
}