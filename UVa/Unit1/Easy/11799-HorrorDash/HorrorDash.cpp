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

	int n, s, x;
	vector<int> vel;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s);
		for (size_t j = 0; j < s; j++) {
			scanf("%d", &x);
			vel.push_back(x);
		}
		sort(vel.begin(), vel.end());
		printf("Case %d: %d\n", i + 1, vel[vel.size() - 1]);
		vel.clear();
	}
	return 0;
}