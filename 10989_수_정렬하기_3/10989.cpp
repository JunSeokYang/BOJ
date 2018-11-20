#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, count[10001] = { 0, }, max = 0, in;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		count[in]++;
	}
	for (int i = 0; i < 10001; i++)
		while (count[i]) {
			cout << i << '\n';
			count[i]--;
		}
	return 0;
}