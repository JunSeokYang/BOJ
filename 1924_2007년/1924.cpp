#include <iostream>

using namespace std;

int main() {
	int m, n, d;
	cin >> m >> n;
	if (m % 2 == 0)
		if (m < 8)
			if (m == 2)
				d = 31 + n;
			else
				d = ((m / 2) - 2) * (30 + 31) + 31 * 2 + 28 + n;
		else
			d = 31 * 4 + 30 * 2 + 28 + ((m - 8) / 2)*(30 + 31) + n;
	else
		if (m < 8)
			if (m == 1)
				d = n;
			else
				d = (m / 2) * 31 + ((m / 2) - 1) * 30 + 28 + n;
		else
			d = 31 * 5 + 30 * 2 + 28 + ((m - 8) / 2)*(31 + 30) + n;
	
	switch (d % 7) {
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	case 0:
		cout << "SUN";
		break;
	default :
		cout << "error" << endl;
		break;
	}

	return 0;
}