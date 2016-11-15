#include <iostream>
#include <cstring>

using namespace std;

#define BLOCKSIZE 30
#define TWOSIZE 3
#define FOURSIZE 11

int N;
int dest;			// 찾는 숫자
int memo[BLOCKSIZE];

int getVal(int num, int sum) {
	if (num > dest) { return 0; }
	if (num == dest) { return  sum; }
//	int &ret = memo[num][sum];
//	if (ret != -1) { return ret; }
	int ret = 0;
	ret += getVal(num + 1, sum * TWOSIZE);
	ret += getVal(num + 2, sum * FOURSIZE);

	return ret;
}

int main() {
	cin >> N;

	memset(memo, -1, sizeof(memo));
	if (N % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}

	dest = N / 2;

	cout << getVal(0, 1) << endl;

	return 0;
}