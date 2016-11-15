#include <iostream>

using namespace std;

long long N;
long long M;
long long maxNum = 0;
long long tree[1000001];

long long getSum(int H) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (tree[i] > H) {
			sum += (tree[i] - H);
		}
	}
	return sum;
}

int main() {

	cin >> N >> M;

	for (long long i = 0; i < N; i++) {
		cin >> tree[i];

		if (maxNum < tree[i]) {
			maxNum = tree[i];
		}
	}
	long long H = maxNum / 2;
	long long start = 0;
	long long end = maxNum;
	long long prev = -1;
	
	if (M == 0) {
		cout << maxNum << endl;
		return 0;
	}
	if (M == getSum(0)) {
		cout << 0 << endl;
		return 0;
	}
	while (1) {
		long long sum = getSum(H);
	//	printf("피벗 확인 (%d) : 합계 %d\n", H, sum);
		if (!(start <= end)) {
			break;
		}

		if (sum < M) {
			end = H - 1;
			H = (start + end) / 2;
		}
		else if (sum > M) {
			start = H + 1;
			H = (start + end) / 2;
		}
		else {
			break;
		}
		if (prev == H) {
			break;
		}
		prev = H;
	}
	if (getSum(H) < M) {
		H--;
	}

	cout << H << endl;

	return 0;
}