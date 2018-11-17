#include <iostream>

using namespace std;

int main(void) {
	int i, m = 0;
	cin >> i;
		if (i == 1)
			cout << "1/1\n";
		else if (i == 2)
			cout << "1/2\n";
		else if (i == 3)
			cout << "2/1\n";
		else {
			for (m = 0; m < i; m++)
				i -= m;
			if (m % 2)
				cout << m + 1 - i << "/" << i << endl;
			else
				cout << i << "/" << m + 1 - i << endl;
		}
	return 0;
}