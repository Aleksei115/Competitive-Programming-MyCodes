//https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back
#include <bits/stdc++.h>

using namespace std;

void setIO() {
	string file = __FILE__;

	file = string(file.begin(), file.end() - 3);
	string out_file = file + "out";
	string in_file = file + "in";

	freopen(in_file.c_str(), "r", stdin);
	freopen(out_file.c_str(), "w", stdout);
}


int main() {
	if (getenv("CP_IO"))
		setIO();
	int n;
	map<int, int> mp;
	mp.clear();
	while (scanf("%d", &n) != EOF) {
		mp[n]++;
	}
	for (const auto& i : mp) {
		cout << i.first << endl;
	}
	return 0;
}