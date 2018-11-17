#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main(void) {
	int input[10] = { 0, },i=0;
	char buf;
	while ((buf = getchar()) != '\n')
		input[i++] = buf - 48;
	sort(input, input + i, desc);
	for (int n = 0; n < i; n++)
		cout << input[n];
	cout << endl;
	return 0;
}