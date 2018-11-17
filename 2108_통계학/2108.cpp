#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, *input, avg = 0, max = -4000, min = 4000, count[8001] = { 0, }, cmax = 0;
	cin >> n;
	input = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		avg += input[i];
		if (input[i] > max)
			max = input[i];
		if (input[i] < min)
			min = input[i];
		count[input[i] + 4000]++;
	}

	sort(input, input + n);
	if (avg >= 0)
		avg = (float)avg / n + 0.5;
	else
		avg = (float)avg / n- 0.5;

	cout << avg << endl;

	cout << input[n / 2] << endl;

	for (int i = min+4000; i < max+4000+1; i++)
		if (count[cmax] < count[i])
			cmax = i;
	for (int i = min+4000; i < max+4000+1; i++)
		if (count[cmax] == count[i])
			if (cmax != i) {
				cmax = i;
				break;
			}

	cout << cmax-4000 << endl;

	cout << max - min << endl;
	return 0;
}