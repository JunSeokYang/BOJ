#include <iostream>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,flag=0;
	cin >> a;
	if (a == 1)
		flag = 1;
	else if (a == 8)
		flag = 2;

	for (int i = 1; i < 8; i++) {
		cin >> a;
		if (a == i + 1 && flag == 1) {
			if (i == 7)
				cout << "ascending\n";
			continue;
		}
		else if (a == 8 - i && flag == 2) {
			if (i == 7)
				cout << "descending\n";
			continue;
		}
		else {
			cout << "mixed\n";
			break;
		}
	}

}