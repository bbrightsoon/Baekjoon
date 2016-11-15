#include <iostream>

using namespace std;

int yoot[3][4];

void printAns(int idx) {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		if (yoot[idx][i] == 0) {
			cnt++;
		}
	}

	switch (cnt) {
	case 1:
		cout << "A" << endl;
		break;
	case 2:
		cout << "B" << endl;
		break;
	case 3:
		cout << "C" << endl;
		break;
	case 4:
		cout << "D" << endl;
		break;
	case 0:
		cout << "E" << endl;
		break;
	}
}

int main() {

	for (int i = 0; i < 3; i++) {
		cin >> yoot[i][0] >> yoot[i][1] >> yoot[i][2] >> yoot[i][3];
	}

	for (int i = 0; i < 3; i++) {
		printAns(i);
	}

	return 0;
}