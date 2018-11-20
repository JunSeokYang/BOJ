#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int *a;
	int n, p, sum = 0;
	cin >> s;
	a = new int[s.length()];
	for (int i = 0; i < s.length(); i++) {
		p = 0;
		n = 0;
		for (int m = 0; m < 8; m++) {
			if (m == 5)
				p = 1;
			else if (m == 6) {
				n = 1;
			}
			if (((int)s[i] > (64 + m * 3 + n)) && ((int)s[i] < (68 + m * 3 + n + p)))
				a[i] = m + 2;
		}
		sum += a[i] + 1;
	}
	cout << sum << '\n';
	delete(a);
	return 0;
}