#include <iostream>

using namespace std;

int perm(int k, int n) {
	if (n == 1)
		return 1;
	else if (k == 0)
		return n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += perm(k - 1, i);
	return sum;
}

int main(void) {

	int c, k, n;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> k;
		cin >> n;
		cout << perm(k, n) << endl;
	}

	return 0;
}