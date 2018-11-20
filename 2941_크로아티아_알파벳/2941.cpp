#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int c = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'c')
			if (s[i + 1] == '-' || s[i + 1] == '=')
				continue;
			else
				c++;
		else if (s[i] == 'd')
			if (s[i + 1] == 'z')
				if (s[i + 2] == '=') {
					i++;
				}
				else
					c++;
			else if (s[i + 1] == '-')
				continue;
			else
				c++;
		else if (s[i] == 'l' || s[i] == 'n')
			if (s[i + 1] == 'j')
				continue;
			else
				c++;
		else if (s[i] == 's' || s[i] == 'z')
			if (s[i + 1] == '=')
				continue;
			else
				c++;
		else
			c++;
	}
	cout << c;
	return 0;
}