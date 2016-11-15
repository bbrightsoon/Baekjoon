#include <iostream>

using namespace std;


int nodeSize;
int adArr[100][100];
int visit[100];
int result[100][100];
int front = 0, rear = 0;
int queue[100];

void BFS(int vertex) {
	front = 0;
	rear = 0;

	queue[rear++] = vertex;
	while (rear != front) {
		for (int i = 0; i < nodeSize; i++) {
			if (visit[i] == 1) {
				continue;
			}
			if ((adArr[queue[front]][i] == 1)) {
				visit[i] = 1;
				queue[rear++] = i;
				result[vertex][i] = 1; 
			}
		}
		front++;
	}
}


int main() {

	cin >> nodeSize;

	for (int i = 0; i < nodeSize; i++) {
		for (int j = 0; j < nodeSize; j++) {
			cin >> adArr[i][j];
		}
	}
	
	// deokgu 

	for (int i = 0; i < nodeSize; i++) {
		for (int j = 0; j < nodeSize; j++) {
			result[i][j] = 0;
		}
	}

	for (int i = 0; i < nodeSize; i++) {
		for (int j = 0; j < nodeSize; j++) {
			visit[j] = 0;
		}
		BFS(i);
	}


	for (int i = 0; i < nodeSize; i++) {
		for (int j = 0; j < nodeSize; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}