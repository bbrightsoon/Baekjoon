#include <iostream>

using namespace std;

#define MAX_NUM 2100000000

long long K, N;
long long lan[10001];

long long getTok(long long length) {
	long long sum = 0;
	for (long long i = 0; i < K; i++) {	sum += (lan[i] / length); }
	return sum;
}

int main() {
	long long ret = 0;
	long long lanMax = -1;

	cin >> K >> N;

	for (long long i = 0; i < K; i++) {
		cin >> lan[i];
		if (lanMax < lan[i]) { lanMax = lan[i];	}
	}

	long long _l = 0; 
	long long _r = lanMax;

	while (_l <= _r) {
		long long _p = (_l + _r) / 2;
		long long sum;

		sum = getTok(_p);
		if (sum >= N) {
			_l = _p + 1;
			if (_p > ret) {	ret = _p; }
		}
		else { _r = _p - 1; }
	}
	cout << ret << endl;

	return 0;
}