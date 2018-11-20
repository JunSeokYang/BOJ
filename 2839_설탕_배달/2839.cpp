#include <iostream>
using namespace std;

int main() {

	int m=0,p=0,q=0,n=0;
	cin >> m;
	while (m > 0) {
		if (m % 5 == 0) {
			p += 1;
			n = 5;
		}
		else {
			n = 3;
			q += 1;
		}
		m -= n;
	}
	if (m != 0)
		cout << -1;
	else
		cout << p + q << endl;
	return 0;
}