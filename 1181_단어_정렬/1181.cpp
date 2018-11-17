#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool desc(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a.compare(b)<0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string *input,check;
	int n,max = 0;
	cin >> n;
	input = new string[n];
	for (int i = 0; i < n; i++)
		cin >> input[i];

	sort(input, input + n, desc);

	for (int i = 0; i < n; i++) {
		if(check.compare(input[i]) != 0)
			cout << input[i] << endl;
		check.clear();
		check.append(input[i]);
	}

	return 0;
}