#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int myDP(int *dp, vector<int> *list, int i) {
	vector<int> a, flag;
	if (dp[i])
		return dp[i];
	int  buf = 0, count, sz=list[i].size();
	for (int m = 0; m < sz; m++) {
		if (sz < list[list[i].at(m)].size())
			flag.push_back(m);
	}
	count = flag.size();
	for (int m = 0; m < count; m++) {
		a.push_back(myDP(dp, list, list[i].at(flag.at(m))));
	}
	for (int m = 0; m < count; m++)
		if (a.at(m) > buf)
			buf = a.at(m);
	if (!dp[i])
		dp[i] = buf + 1;
	return dp[i];

}
int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> *list;
	int city, link, first, second, buf=0, *dp;
	cin >> city;
	cin >> link;
	list = new vector<int>[city];
	dp = new int[city];
	for (int i = 0; i < city; i++)
		dp[i] = 0;
	for (int i = 0; i < link; i++) {
		cin >> first;
		cin >> second;
		list[first].push_back(second);
		list[second].push_back(first);
	}

	for (int i = 0; i < city; i++)
		myDP(dp, list, i);
	for (int i = 0; i < city; i++)
		if (buf < dp[i])
			buf = dp[i];
	cout << buf << endl;
	return 0;
}