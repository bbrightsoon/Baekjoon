#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define MAXSIZE 16

int L;
int C;
char input[MAXSIZE];
stack<int> chStack;

// 모음인가 판단
bool isMWord(char ch) {
	switch (ch) {
		case 'a' :
		case 'e' :
		case 'i' :
		case 'o' :
		case 'u':	return true;
		default:	return false;
	}
	return false;
}

void printStack() {
	int buf[MAXSIZE];
	int index = 0;

	while (!chStack.empty()) {
		buf[index++] = chStack.top();
		chStack.pop();
	}
	for (int i = (index - 1); i >= 0; i--) {
		cout << input[buf[i]];
		chStack.push(buf[i]);
	}
	cout << endl;
}

// 부모 노드의 값, 모음 수, 자음 수
void proc(int cur, int p_index, int m_count, int j_count) {
	if (cur == L - 1) {
		if ((m_count >= 1) && (j_count >= 2)) {
			printStack();
			return;
		}
	}
	for (int i = 0; i < C; i++) {
		if (i > p_index) {
			if (isMWord(input[i])) {
				chStack.push(i);
				proc(cur + 1, i, m_count + 1, j_count);
				chStack.pop();
			}
			else {
				chStack.push(i);
				proc(cur + 1, i, m_count, j_count + 1);
				chStack.pop();
			}
		}
	}
}

int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) { cin >> input[i]; }

	sort(input, input + C);

	for (int i = 0; i < C; i++) {
		chStack.push(i);
		int mCount = 0;
		int jCount = 0;
		if (isMWord(input[i])) { mCount++; }
		else { jCount++;  }
		proc(0, i, mCount, jCount);
		chStack.pop();
	}
	
	return 0;
}