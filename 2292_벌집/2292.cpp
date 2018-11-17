#include <iostream>
#include <string>
using namespace std;

int main() {
	int i;
	cin >> i;
	if (i == 1)
		cout << i;
	else
		for (int m = 1; m < 18258; m++)
			if ((3 * m*(m - 1) + 1) < i && (3 * m*(m + 1) + 1 >= i)) {
				cout << m+1;
				break;
			}

	return 0;
}