#include <iostream>

using namespace std;

int main() {
	int caseSize;
	int maxNum = -1;
	long long fibNum[68];
	int caseArr[70];


	cin >> caseSize;
	
	for (int i = 0; i < caseSize; i++) {
		cin >> caseArr[i];
		if (maxNum < caseArr[i]) {
			maxNum = caseArr[i];
		}
	}
	
	fibNum[0] = 1;
	fibNum[1] = 1;
	fibNum[2] = 2;
	fibNum[3] = 4;

	for (int i = 4; i <= maxNum; i++) {
		fibNum[i] = fibNum[i - 4] + fibNum[i - 3]
			+ fibNum[i - 2] + fibNum[i - 1];
	}
	
	for (int i = 0; i < caseSize; i++) {
		cout << fibNum[caseArr[i]] << endl;
	}
	



	return 0;
}