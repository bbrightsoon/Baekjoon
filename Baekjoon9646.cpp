#include <iostream>
#include <cstring>

using namespace std;

int result;
int K;		// ���� �� 
int N;		// �ڽ��� �� �� �ִ� ��
int num_box[8];		// �ึ�� �ڽ� ����
int box[8][8];


// ������ �ڽ��� �ִ°�
bool isRRange(int x, int y) {return box[x + 1][y] == 1;}
// �ؿ� �ڽ��� �ִ°�
bool isDRange(int x, int y) {return box[x][y + 1] == 1;}

int findNext(int xVal, int yVal, int num) {
	if ((xVal == (num_box[yVal] - 1)) || (yVal == K - 1)) {
		return 1;
	}
	if (num == K) {
		return 0;
	}
	int ret = 0;
	
	if (isRRange(xVal, yVal)) {
		for (int i = num; i <= num; i++) {
			ret += findNext(xVal + 1, yVal, i);
		}
	}
		if (isDRange(xVal, yVal)) {
			for (int i = (num + 1); i <= num; i++) {
				ret += findNext(xVal, yVal + 1, i);
		}
	}
	return ret;
}

int getTablo(int input) {
	int sum = 0;
	for (int i = 0; i < input; i++) {
		sum += findNext(0, 0, i);
	}
	return sum;
}

int main() {
	while (1) {
		result = 0;
		cin >> K;
		if (K == -1) {
			break;
		}
		memset(box, 0, sizeof(box));
		for (int i = 0; i < K; i++) {
			cin >> num_box[i];
			for (int j = 0; j < num_box[i]; j++) {
				box[i][j] = 1;
			}
		}
			cin >> N;

			cout << getTablo(N) << endl;
		
	}
	return 0;
}