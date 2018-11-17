#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int a[26] = { 0, },max=0;
	char k;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ((int)s[i] < 123 && (int)s[i]>96)
			s[i] -= 32;
		a[s[i] - 65]++;
	}
	for (int m = 0; m < 26; m++) {
		if (max < a[m]) {
			max = a[m];
			k = m + 65;
		}
		else if (max != 0 && max == a[m])
			k = '?';
	}

	cout << k << '\n';
	

	return 0;
}