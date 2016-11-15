#include <iostream>8

using namespace std;

#define MAXSIZE 1000000000

long long p[4][2];
long long minMoving = 9 * MAXSIZE;
long long ans;

long long min(long long a, long long b) { return a > b ? b : a; }

long long myAbs(long long a) { return a > 0 ? a : -a; }

long long getMoving(int mid) {
	int tmp = 0;
	for (int i = 0; i < 4; i++) {
		tmp += myAbs(myAbs(p[i][0]) - mid);
		tmp += myAbs(myAbs(p[i][1]) - mid);
	}
	return tmp;
}

void proc(long long f_l, long long f_r) {
	if (f_l > f_r) { return; }
	long long f_m = (f_l + f_r) / 2;
	long long l, m, r;

	l = getMoving(f_m - 1);
	m = getMoving(f_m);
	r = getMoving(f_m + 1);
	if (minMoving >= m) {
		if (minMoving == m) {
			if (f_m > ans) {
				ans = f_m;
			}
		}
		else {
			minMoving = m;
			ans = f_m;
		}
	}
	if (r >= m) {
		// 기울기 양수
		if (l < m) {
			// 왼쪽도 양수 - 왼쪽 탐색
			proc(f_l, f_m - 1);
		}
		else if (l > m) {
			// 왼쪽은 음수
			cout << 2 * f_m << endl;
			exit(0);
		}
		else {
			// 왼쪽 동일
			proc(f_l, f_m - 1);
		}
	}
	else if (r < m) {
		// 기울기 음수
		proc(f_m + 1, f_r);
	}
	
///	if (f_l >= f_r) { return; }
}

int main() {
	long long max = 0;
	long long min = MAXSIZE;

	for (int i = 0; i < 4; i++) {
		cin >> p[i][0] >> p[i][1];
		if (max < myAbs(p[i][0])) { max = myAbs(p[i][0]); }
		if (min > myAbs(p[i][0])) { min = myAbs(p[i][0]); }
		if (max < myAbs(p[i][1])) { max = myAbs(p[i][1]); }
		if (min > myAbs(p[i][1])) { min = myAbs(p[i][1]); }
	}

	proc(min, max);
	
	cout << 2 * ans << endl;

	return 0;
}