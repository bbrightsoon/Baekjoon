#include <iostream>

using namespace std;

long long pArr[101];

void print(int val) {
	cout << pArr[val] << endl;
}

void setPArr() {
	pArr[0] = 0;
	pArr[1] = 1;
	pArr[2] = 1;
	pArr[3] = 1;
	pArr[4] = 2;
	pArr[5] = 2;

	for (int i = 6; i <= 100; i++) {
		pArr[i] = pArr[i - 1] + pArr[i - 5];
	}
}

int main() {
	int caseSize;
	int caseNum;

	cin >> caseSize;

	setPArr();
	for (int i = 0; i < caseSize; i++) {
		cin >> caseNum;
		print(caseNum);
	}
	return 0;
}