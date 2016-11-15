#include <iostream>
#include <string.h>

using namespace std;

#define STRINGSIZE 51
#define NSIZE 51

int N;
int strLen;
char stringList[NSIZE][STRINGSIZE];
char pattern[STRINGSIZE];

bool isPossible(char ch) { return ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) || (ch == '.'); }

void findPattern() {
	int row, col;
	for (col = 0; col < strLen; col++) {
		for (row = 1; row < N; row++) {
			if (stringList[row][col] != stringList[row - 1][col]) { break; }
		}
		if ((row == N) && isPossible(stringList[0][col])) { pattern[col] = stringList[0][col]; }
		else { pattern[col] = '?'; }
	}
	for (col = 0; col < strLen; col++) { cout << pattern[col]; }
	cout << endl;
}

int main() {	
	cin >> N;

	for (int i = 0; i < N; i++) { cin >> stringList[i]; }
	strLen = strlen(stringList[0]);

	findPattern();

	return 0;
}	