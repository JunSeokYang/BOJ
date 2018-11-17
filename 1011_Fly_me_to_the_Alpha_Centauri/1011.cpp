#include <iostream>

using namespace std;

int main(void) {
	long int i, m, buf = 0,a,b,len;
	cin >> i;
	for (int n = 0; n < i; n++) {
		buf = 0;
		cin >> a;
		cin >> b;
		len = b - a;
		for (m = 0; buf < len; m++)
			buf += 2 * m;
		m--;
		if (buf - m >= len)
			cout << 2 * m - 1 << endl;
		else
			cout << 2 * m << endl;
	}
	return 0;
}