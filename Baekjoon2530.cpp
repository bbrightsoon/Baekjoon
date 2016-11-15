#include <iostream>

using namespace std;


int _h;
int _m;
int _s;
int needTime;

int main() {
	cin >> _h >> _m >> _s >> needTime;

	_h += needTime / 3600;
	needTime %= 3600;
	_m += needTime / 60;
	needTime %= 60;
	_s += needTime;

	if (_s >= 60) {
		_m += (_s / 60);
		_s %= 60;
	}

	if (_m >= 60) {
		_h += (_m / 60);
		_m %= 60;
	}

	if (_h >= 24) {
		_h %= 24;
	}

	cout << _h << " " << _m << " " << _s << endl;
	return 0;
}