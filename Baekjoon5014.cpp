// 20161011
// 00:27:58

#include <iostream>

using namespace std;

int maxFloor;
int startFloor;
int destFloor;
int upButton;
int downButton;

int front, rear;
int queue[1000001];
int pushCount[1000001];
int visit[1000001];

void pushQueue(int inputVal) {
	queue[rear] += inputVal;
	pushCount[rear] = pushCount[front] + 1;
	rear++;
}

bool isRange(int inputVal) {
	if ((inputVal <= maxFloor)
		&& (inputVal >= 1)) {
		return true;
	}
	return false;
}

void BFS() {
	front = 0;
	rear = 0;

	queue[0] = startFloor;
	visit[startFloor] = 1;
	rear++;

	while (front != rear) {
		if (queue[front] == destFloor) {
			cout << pushCount[front] << endl;
			return;
		}
		int nextUpFloor = queue[front] + upButton;
		int nextDownFloor = queue[front] - downButton;
		if (isRange(nextUpFloor)) {
			if (visit[nextUpFloor] != 1) {
				pushQueue(nextUpFloor);
				visit[nextUpFloor] = 1;
			}
		}
		if (isRange(nextDownFloor)) {
			if (visit[nextDownFloor] != 1) {
				pushQueue(nextDownFloor);
				visit[nextDownFloor] = 1;
			}
		}
		front++;
	}

	cout << "use the stairs" << endl;

}


int main() {

	cin >> maxFloor >> startFloor >> destFloor
		>> upButton >> downButton;

	BFS();

	return 0;
}