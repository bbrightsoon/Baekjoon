// 20161011
// 00:24:46

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int source;
int dest;

int visit[100001];


struct moveData { int x, t; };
queue<moveData> que;

void pushData(int xVal, int tVal) {
	moveData mV;
	mV.x = xVal;
	mV.t = tVal;
	que.push(mV);
}

bool isRange(int val) { return (val <= 100000) && (val >= 0); }

void BFS() {
	visit[source] = 1;
	pushData(source, 0);

	while (!que.empty()) {
		moveData front = que.front();
		que.pop();
		if (front.x == dest) {
			cout << front.t << endl; 
			break;
		}
		int next[3];
		next[0] = front.x - 1;
		next[1] = front.x + 1;
		next[2] = 2 * front.x;

		for (int i = 0; i < 3; i++) {
			if (isRange(next[i])) {
				if (visit[next[i]] != 1) {
					visit[next[i]] = 1;
					pushData(next[i], front.t + 1);
				}
			}
		}
	}


}



int main() {

	cin >> source >> dest;

	memset(visit, 0, sizeof(visit));
	BFS();

	return 0;
}