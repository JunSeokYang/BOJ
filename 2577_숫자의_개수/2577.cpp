#include <iostream>
#include <math.h>
using namespace std;

int mypow(int a) {
	int m=1;
	for (int i = 0; i < a; i++)
		m *= 10;
	return m;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, w[10] = { 0, };
	cin >> a >> b >> c;
	for (int i = 8; i >= 0; i--) 
		w[(a*b*c / mypow(i)) % 10 ]++;
	//cout << a*b*c << "\n";
	if (a*b*c / mypow(8) == 0 && a*b*c/ mypow(7) != 0)
		w[0] -= 1;
	if (a*b*c / mypow(8) == 0 && a*b*c / mypow(7) == 0)
		w[0] -= 2;
	for (int i = 0; i < 10; i++)
		cout << w[i] << "\n";

	return 0;
}