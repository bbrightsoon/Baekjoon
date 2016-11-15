#include <iostream>
#include <cstring>

using namespace std;


int N;				// 입력된 수의 갯수
int S;				// 합이 S인 부분집합 갯수 세기
int countLimit;
int n_arr[21];
int n_flag[21];

bool chk(int input) {
	for (int i = input; i < N; i++) {
		if (n_flag[i] == true) {
			return false;
		}
	}
	return true;
}

// size = 부분집합 갯수
int getResult(int cur, int sum, int max) {
	if (cur == max) {
		if (sum == S) { return 1; }
		else { return 0; }
	}
	int ret = 0;
	
	for (int i = 0; i < N; i++) {
		if (chk(i)) {
			n_flag[i] = 1;
			ret += getResult(cur + 1, sum + n_arr[i], max);
			n_flag[i] = 0;
		}
	}

	return ret;
}

int main() {
	int result = 0;

	cin >> N >> S;

	for (int i = 0; i < N; i++) { cin >> n_arr[i]; }

	for (int i = 1; i <= N; i++) {
		memset(n_flag, 0, sizeof(n_flag));
		result += getResult(0, 0, i); 
	}

	cout << result << endl;

	return 0;
}