#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int doorSize;
int rootSize;
int leftDoor;
int rightDoor;		
int shortestLength = 5000;	
int route[21];				// 경로 (문 여는 차례)

void getShortestPath(int depth, int length, int lDoor, int rDoor) {
	if (depth == rootSize) {
		// 마지막까지 탐색했으면 리턴
		if (shortestLength > length) {
			shortestLength = length;
		}
		return;
	}
	int destDoor = route[depth] - 1;	// 들어갈 문
	if (lDoor > destDoor) {
		// 왼쪽 열린 문 기준으로 왼쪽에 destDoor 존재
		getShortestPath(depth + 1, length + abs(lDoor - destDoor)
			, destDoor, rDoor);
	}
	else if (rDoor < destDoor) {
		// 오른쪽 열린 문 기준으로 오른쪽에 destDoor 존재
		getShortestPath(depth + 1, length + abs(destDoor - rDoor),
			lDoor, destDoor);
	}
	else {
		// 두 열린 문 사이에 destDoor 존재
		getShortestPath(depth + 1, length + abs(lDoor - destDoor)
			, destDoor, rDoor);
		getShortestPath(depth + 1, length + abs(destDoor - rDoor),
			lDoor, destDoor);
	}
}

int main() {

	cin >> doorSize >> leftDoor >> rightDoor >> rootSize;
	
	for (int i = 0; i < rootSize; i++) {
		cin >> route[i];
	}
	// 인풋 끝


	getShortestPath(0, 0, --leftDoor, --rightDoor);	// 문 번호라서 인덱스로 사용하려고 1 뺌

	cout << shortestLength << endl;

	return 0;
}