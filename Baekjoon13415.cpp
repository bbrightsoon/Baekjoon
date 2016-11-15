#include <iostream>
#include <algorithm>

using namespace std;

#define MAXARRSIZE 100000
#define INF 0x7fffffff

int N;
int K;
int prevL;
int numArr[MAXARRSIZE];
int setArr[MAXARRSIZE][2];
int cpyArr[MAXARRSIZE];

void swapNumArr(int a, int b) {
	int tmp = 0;
	tmp = numArr[a];
	numArr[a] = numArr[b];
	numArr[b] = tmp;
}

void doDec(int decIdx) {
	int minIdx = 0;
	int cpyArrIdx = 0;
//	cpyArr = new int[N];
	for (int i = 0; i < decIdx - 1; i++) {
		cpyArr[cpyArrIdx++] = numArr[i];
		if (numArr[i] < numArr[i + 1]) { minIdx = i; break; }
		if (i == decIdx - 2) { minIdx = decIdx - 1; }
	}
	for (int i = 0; i < decIdx - minIdx; i++) { numArr[i] = numArr[decIdx - i]; }
	for (int i = decIdx - minIdx; i <= decIdx; i++) { numArr[i] = cpyArr[i]; }
}

void doInc(int incIdx, int decIdx) {
	int minIdx = 0;
	int cpyArrIdx = 0;
	//cpyArr = new int[N];
	for (int i = 0; i < incIdx - 1; i++) {
		cpyArr[cpyArrIdx++] = numArr[i];
		if (numArr[i] < numArr[i + 1]) { minIdx = i; break; }
		if (i == incIdx - 2) { minIdx = incIdx - 1; }
	}
}

void printNow() {
	for (int i = 0; i < N; i++) { cout << numArr[i] << " "; }
	cout << endl;
}

int main() {
	int max = -1;
	int maxIdx = 0;

	cin >> N;
	for (int i = 0; i < N; i++) { cin >> numArr[i]; }
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> setArr[i][0] >> setArr[i][1];
		if (max < setArr[i][0]) { max = setArr[i][0]; maxIdx = i; }
		if (max < setArr[i][1]) { max =	setArr[i][1]; maxIdx = i; }
	}

	for (int i = 0; i < 3; i++) {
		
	}
	printNow();
	for (int i = startIdx + 1; i < K; i++) {
		if (setArr[i][0] <= setArr[i][1]) { doDec(setArr[i][1]); }
		else { doInc(setArr[i][0], setArr[i][1]); }
		printNow();
	}
	cout << "result :" << endl;
	for (int i = 0; i < N; i++) { cout << numArr[i] << " "; }
	cout << endl;
	return 0;
}