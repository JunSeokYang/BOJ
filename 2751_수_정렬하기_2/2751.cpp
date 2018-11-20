#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void MyMergeSort(int *a, int first, int second) {
	if (first == second)
		return;
	int *buf = new int[second - first + 1], count = 0;
	int fit = first, sit = first + ((second - first) / 2) + 1;
	MyMergeSort(a, first, first + (second-first)/2);
	MyMergeSort(a, sit, second);
	while ((fit < first + (second-first)/2+1) && (sit < second+1))
		if (a[fit] > a[sit])
			buf[count++] = a[sit++];
		else
			buf[count++] = a[fit++];
	if (count < (second - first) + 1) {
		while (fit < first + (second-first)/2+1)
			buf[count++] = a[fit++];
		while (sit < second)
			buf[count++] = a[sit++];
	}
	copy(buf, buf + count, /*stdext::checked_array_iterator<int*>(a+first, count) */a + first );
	delete buf;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int *a;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	MyMergeSort(a, 0, n-1);
	for (int i = 0; i < n; i++)
		cout << a[i] << '\n';
	return 0;
}