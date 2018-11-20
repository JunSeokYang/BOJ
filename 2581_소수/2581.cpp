#include <iostream>

using namespace std;

int main(void) {
	int n,m, count = 0,flag, min;
	cin >> n >> m;
	min = m;
	for (int i = n; i < m + 1; i++) {
		flag = 2;
		while (flag < i + 1) {
			if (flag == i) {
				count += flag;
				if (flag < min)
					min = flag;
				break;
			}
			else if (!(i%flag))
				break;
			flag++;
		}
	}
	if (!count)
		cout << -1 << endl;
	else {
		cout << count << endl;
		cout << min << endl;
	}
	return 0;
}