#include <iostream>
@include <cstring>

using namespace std;

int N;
int front, rear;
int queue[1001];
int visit[1001];
int adArr[1001][1001];

void DFS(int start) {
	cout << start << " ";
	visit[start] = 1;
	for (int i = 1; i <= N; i++) {
		if ((adArr[start][i] == 1) && (visit[i] != 1))	{
			DFS(i);
		}
	}
}


void BFS(int start) {
	front = 0;
	rear = 0;

	queue[rear++] = start;
	visit[start] = 1;
	cout << start << " ";
	while (front != rear) {
		for (int i = 1; i <= N; i++) {
			if ((adArr[queue[front]][i] == 1) && (visit[i] != 1)) {
				visit[i] = 1;
				queue[rear++] = i;
				cout << i << " ";
			}
		}
		front++;
	}
	cout << endl;
}

int main() {
	int M;
	int startNum;
	int adNode1, adNode2;

	cin >> N;
	cin >> M;
	cin >> startNum;

	for (int i = 1; i <= M; i++) {
		cin >> adNode1;
		cin >> adNode2;

		adArr[adNode1][adNode2] = 1;
		adArr[adNode2][adNode1] = 1;
	}

	memset(visit, 0, sizeof(visit));
	DFS(startNum);
	cout << endl;
	memset(visit, 0, sizeof(visit));
	BFS(startNum);

	return 0;
}