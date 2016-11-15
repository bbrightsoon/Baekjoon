#include <iostream>
#include <algorithm>

using namespace std;

int numArr[9];

int main() {
	int sum = 0;
	int saveX;
	int saveY;

	for (int i = 0; i < 9; i++) {
		cin >> numArr[i];
		sum += numArr[i];
	}

	sum -= 100;

	sort(numArr, numArr + 9);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i != j) {
				if (numArr[i] + numArr[j] == sum) {
					saveX = i;
					saveY = j;
					i = 9;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (saveX == i) { continue; }
		if (saveY == i) { continue; }
		cout << numArr[i] << endl;
	}
	return 0;
}