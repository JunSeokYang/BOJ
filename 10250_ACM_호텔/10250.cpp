#include <iostream>

using namespace std;

int main(void) {

	int c,h,w,n,floor,room=1;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> h;
		cin >> w;
		cin >> n;
		while (n>h) {
			n -= h;
			room++;
		}
		floor = n;
		if (room < 10)
			cout << floor << 0 << room << endl;
		else
			cout << floor << room << endl;
		room = 1;
	}

	return 0;
}