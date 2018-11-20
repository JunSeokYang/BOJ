#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int Happyfunc(int in) {
	int buf = 0;
	while (in >= 10) {
		buf += pow(in % 10, 2);
		in = in / 10;
	}
	buf += pow(in, 2);
	return buf;
}

int main(void) {
	int input, buf,flag=0;
	string s="";
	cin >> input;
	while (input != 1 && !flag) {
		input = Happyfunc(input);
		s.append(""+input+48);
		for(int i=0; i<s.length(); i++)
			if (s.at(i) == input) {
				flag = 1;
				break;
			}
	}
	if (!flag)
		cout << "HAPPY\n";
	else
		cout << "UNHAPPY\n";

	return 0;
}