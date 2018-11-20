#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int c, x, y, m, n, count, p, q;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> x;
		cin >> y;
		cin >> m;
		cin >> n;
		while ((m != n))
		{
			if (m > x*y) {
				m = -1;
				break;
			}
			if (m > n)
				n += y;
			else if (n > m)
				m += x;
		}
		cout << m << endl;
	}
	return 0;
}