#include <iostream>

using namespace std;

void printstar(char **a, int n) {
	if (n == 3) {
		a[0][0] = '*';
		a[1][0] = '*';
		a[1][1] = ' ';
		a[1][2] = '*';
		a[2][0] = '*';
		a[2][1] = '*';
		a[2][2] = '*';
		a[2][3] = '*';
		a[2][4] = '*';

	}
	else {
		printstar(a, n / 2);
		for (int i = n / 2; i < n; i++)
			for (int m = 0; m < i * 2 + 1; m++)
				if ((2 * i - n + 1 > m)/* || (i - n / 2) == m*/)
					a[i][m] = a[i - n / 2][m];
				else if (m > i)
					a[i][m] = a[i][i * 2 - m];
				else
					a[i][m] = ' ';
	}
}

int main(void) {
	char **buf;
	int n;
	cin >> n;
	buf = new char*[n];
	for (int i = 0; i < n; i++)
		buf[i] = new char[2 * i + 1];
	printstar(buf, n);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - i - 1; k++)
			cout << ' ';
		for (int m = 0; m < 2 * i + 1; m++)
			cout << buf[i][m];
		for (int k = 0; k < n - i - 1; k++)
			cout << ' ';
		cout << '\n';

	}
	return 0;
}