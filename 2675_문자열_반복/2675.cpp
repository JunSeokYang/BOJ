#include <iostream>
#include <string>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, S;
	string k;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> S;
		cin >> k;
		for (int m = 0; m < k.length(); m++)
			for (int n = 0; n < S; n++)
				cout << k[m];
		cout << "\n";
	}

	return 0;
}