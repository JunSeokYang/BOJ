#include <iostream>
using namespace std;

int maken(int n) {
	if (n < 10)
		return n + n % 10;
	else if (n < 100)
		return n + n / 10 + n % 10;
	else if (n < 1000)
		return n + n / 100 + (n / 10) % 10 + n % 10;
	else if (n < 10000)
		return n + n / 1000 + (n / 100) % 10 + (n / 10) % 10 + n % 10;
}

int main() {
	int flag = 0;
	for (int i = 1; i < 10000; i++) {
		for (int m = 1; m < i; m++)
			if (i == maken(m))
				flag = 1;
		if (flag == 1) {
			flag = 0;
			continue;
		}
		cout << i << "\n";
	}
}