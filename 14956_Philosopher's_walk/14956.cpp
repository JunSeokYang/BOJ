#include <iostream>

using namespace std;

void Philosopher(int SideLength, int location, int *a) {
	if (SideLength == 2) {
		a[0] = (location >= 3) + 1;
		a[1] =  (location == 2 || location == 3) + 1;
		return;
	}
	else {
		int buf, mm;
		int mybuf = (SideLength / 2)*(SideLength / 2);
		if (!(buf = location % mybuf))
			buf = mybuf;
		Philosopher(SideLength / 2, buf, a);
		buf = (location / mybuf) - (location%mybuf == 0) + 1;
		if (buf == 1) {
			a[0] = SideLength / 2 + 1 - a[0];
			mm = a[0];
			a[0] = a[1];
			a[1] = mm;
			a[1] = (SideLength / 2) + 1 - a[1];
		}
		else if (buf == 2)
			a[1] += SideLength / 2;
		else if (buf == 3) {
			a[0] += SideLength / 2;
			a[1] += SideLength / 2;
		}
		else {
			a[0] = SideLength / 2 + 1 - a[0];
			mm = a[0];
			a[0] = a[1];
			a[1] = mm;
			a[0] = (SideLength/2) + 1 - a[0];
			a[0] += SideLength / 2;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int a[] = { 0,0 };
	cin >> n >> m;
	Philosopher(n, m, a);
	cout << a[0] << ' ' << a[1] << endl;
}