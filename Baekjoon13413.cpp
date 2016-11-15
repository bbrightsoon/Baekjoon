#include <iostream>

using namespace std;

#define MAXNSIZE 100000

int T;
int N;
char start[MAXNSIZE];
char dest[MAXNSIZE];
int sBSize;
int dBSize;
int result;

int abs(int a) { return a > 0 ? a : -a; }
int min(int a, int b) { return a > b ? b : a; }

int main() {
	cin >> T;
	for (int test = 0; test < T; test++) 
	{
		cin >> N >> start >> dest;
		sBSize = 0;
		dBSize = 0;
		result = 0;
		for (int i = 0; i < N; i++) {
			if (start[i] == dest[i]) { continue; }
			if (start[i] == 'B') { sBSize++; }
			if (dest[i] == 'B') { dBSize++; }
		}
		result += min(sBSize, dBSize);
		result += abs(sBSize - dBSize);
		cout << result << endl;
	}
	return 0;
}