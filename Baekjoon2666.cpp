#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int doorSize;
int rootSize;
int leftDoor;
int rightDoor;		
int shortestLength = 5000;	
int route[21];				// ��� (�� ���� ����)

void getShortestPath(int depth, int length, int lDoor, int rDoor) {
	if (depth == rootSize) {
		// ���������� Ž�������� ����
		if (shortestLength > length) {
			shortestLength = length;
		}
		return;
	}
	int destDoor = route[depth] - 1;	// �� ��
	if (lDoor > destDoor) {
		// ���� ���� �� �������� ���ʿ� destDoor ����
		getShortestPath(depth + 1, length + abs(lDoor - destDoor)
			, destDoor, rDoor);
	}
	else if (rDoor < destDoor) {
		// ������ ���� �� �������� �����ʿ� destDoor ����
		getShortestPath(depth + 1, length + abs(destDoor - rDoor),
			lDoor, destDoor);
	}
	else {
		// �� ���� �� ���̿� destDoor ����
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
	// ��ǲ ��


	getShortestPath(0, 0, --leftDoor, --rightDoor);	// �� ��ȣ�� �ε����� ����Ϸ��� 1 ��

	cout << shortestLength << endl;

	return 0;
}