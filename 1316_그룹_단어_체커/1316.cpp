#include <iostream>
#include <string>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T,c=0,flag=0;
	string s;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> s;
		for (int m = 0; m < s.length()-1; m++) {
			if (flag == 1)
				break;
			for (int n = m + 1; n < s.length(); n++)
				if (s[m] == s[m + 1]) {
					break;
				}
				else if (s[m] == s[n]) {
					flag = 1;
					break;
				}
		}
		if (flag != 1)
			c++;
		flag = 0;
	}

	cout << c;

	return 0;
}