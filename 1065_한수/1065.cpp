#include <iostream>
using namespace std;

int main() {
	int N,count=99;
	cin >> N;
	if (N < 100)
		cout << N;
	else {
		for (int i = 100; i <= N; i++)
			if (i / 100 - ((i / 10) % 10) == ((i / 10) % 10) - i % 10)
				count++;
		cout << count;
	}
	return 0;
}