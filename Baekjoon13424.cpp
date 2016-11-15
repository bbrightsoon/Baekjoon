#include <iostream>
#include <cstring>

using namespace std;

#define MAXNSIZE 100
#define MAXMSIZE 4950
#define INF 0x7fffffff

int T;
int N;
int M;
int K;
int a, b, c;
int man[MAXNSIZE];
int adMap[MAXNSIZE][MAXNSIZE];
int dist[MAXNSIZE][MAXNSIZE];

int main() {
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		int min = INF;
		int ans = 0;
		memset(adMap, -1, sizeof(adMap));
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			adMap[a - 1][b - 1] = adMap[b - 1][a - 1] = c;
		}
		for (int i = 0; i < N; i++) { adMap[i][i] = 0; }
		cin >> K;
		for (int i = 0; i < K; i++) { cin >> man[i]; man[i]--; }
		for (int i = 0; i < N; i++) {		// 초기화
			for (int j = 0; j < N; j++) { dist[i][j] = adMap[i][j]; }
		}
		for (int k = 0; k < N; k++) {		// Floyd warshall
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if ((dist[i][k] == -1) || (dist[k][j] == -1)) { continue; }
					if (dist[i][j] == -1) {
						dist[i][j] = dist[i][k] + dist[k][j];
						adMap[i][j] = k;
					}
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						adMap[i][j] = k;
					}
				}
			}
		}
	for (int i = 0; i < N; i++) {		// 최소 방 찾기
			int tmp = 0;
			for (int j = 0; j < K; j++) {
				if (dist[i][man[j]] == -1) { continue; }
				tmp += dist[i][man[j]];
			}
			if (min > tmp) {
				min = tmp;
				ans = i; 
			}
		}
		cout << ans + 1 << endl;
	}
	return 0;
}