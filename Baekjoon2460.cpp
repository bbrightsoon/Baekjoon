#include <iostream>

using namespace std;

#define STATIONSIZE 10

int takeOff[STATIONSIZE];
int takeIn[STATIONSIZE];

int main() {
	int ans = 0;
	int cur = 0;

	for (int i = 0; i < STATIONSIZE; i++) {
		cin >> takeOff[i] >> takeIn[i];
	}

	for (int i = 0; i < STATIONSIZE; i++) {
		cur -= takeOff[i];
		cur += takeIn[i];
		if (ans < cur) {
			ans = cur;
		}
	}
	cout << ans << endl;

	return 0;
}