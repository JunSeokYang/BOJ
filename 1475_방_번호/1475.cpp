#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(void) {
	string a;
	int c, buf;
	int num[10] = { 0, };
	buf = 0;
	cin >> a;
	for (int m = 0; m < a.length(); m++)
		num[a.at(m) - 48]++;
	num[6] = (num[6] + num[9]) / 2 + (num[6] + num[9]) % 2;
	num[9] = num[6];
	for (int i = 0; i < 10; i++)
		if (buf < num[i])
			buf = num[i];
	cout << buf << endl;
	return 0;
}