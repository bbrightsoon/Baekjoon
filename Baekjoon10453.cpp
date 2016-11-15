#include <iostream>
#include <string>

using namespace std;

int T;
string str1;
string str2;

int abs(int a) { return a > 0 ? a : -a; }

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		int ans = 0;
		int prevJ = -1;
		cin >> str1 >> str2;
		int len1 = str1.length();
		int len2 = str2.length();
		if (len1 != len2) { cout << -1 << endl; continue; }
		for (int i = 0; i < len1; i++) {
			if (str1[i] == 'a') {
				if (prevJ == len2 - 1) { ans = -1; break; }
				for (int j = prevJ + 1; j < len2; j++) {
					if (str2[j] == 'a') {
						ans += abs(i - j);
						prevJ = j;
						break;
					}
					if (j == len2 - 1) { prevJ = len2 - 1; }
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}