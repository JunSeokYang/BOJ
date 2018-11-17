#include <iostream>
using namespace std;

int main() {
	int N,init,count=0;
	cin >> N;
	if (N < 10)
		N *= 10;
	init = N;
	do {
		init = (init % 10) * 10 + (init % 10 + init / 10) % 10;
		count++;
	} while (N != init);
	cout << count;
	return 0;
}