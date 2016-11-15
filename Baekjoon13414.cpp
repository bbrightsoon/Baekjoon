#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;

#define MAXKSIZE 100000
#define MAXLSIZE 500000

int K;
int L;
int printCount = 0;
int numArr[MAXLSIZE];
map <int, int> m;

int main() {
	char buf[9];
	cin >> K >> L;
	for (int i = 0; i < L; i++) {
		cin >> buf;
		numArr[i] = atoi(buf);
		if (m[numArr[i]] == '\0') {	m[numArr[i]] = 1; }
		else {
			m[numArr[i]]++;
		}
	}

	for (int i = 0; i < L; i++) {
		if (m[numArr[i]] == '\0') { continue; }
		if (m[numArr[i]] != 1) {
			m[numArr[i]]--;
		}
		else {
			printf("%08d\n", numArr[i]);
			printCount++;
			if (printCount == K) { return 0; }
		}
	}
	
	return 0;
}