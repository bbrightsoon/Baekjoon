#include <iostream>
#include <cstring>

using namespace std;

int inputNum;

int memo[1000001];

void proc(int input, int depth) {
	if (input <= 0) { return; }
	if (input == 1) {
		if (memo[1] > depth) { memo[1] = depth;	}
		return;
	}


	if ((input % 3) == 0) {
		if (memo[input / 3] > depth + 1 || (memo[input / 3] == 0)) { memo[input / 3] = depth + 1; }
		proc(input / 3, depth + 1);
	} 
	if ((input % 2) == 0) {
		if (memo[input / 2] > depth + 1 || (memo[input / 2] == 0)) { memo[input / 2] = depth + 1; }
		proc(input / 2, depth + 1);
	}
	if (memo[input - 1] > depth + 1 || (memo[input - 1] == 0)) { 
		memo[input - 1] = depth + 1; 
		proc(input - 1, depth + 1); 
	}
}

int main() {
	cin >> inputNum;

	memset(memo, 0, sizeof(memo));
	proc(inputNum, 0);

	cout << memo[1] << endl;

	return 0;
}