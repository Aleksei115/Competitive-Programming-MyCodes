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
	scanf("%d", &n);
	vector<int> vi(3);
	int i, j, k;
	string line, token;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &vi[0], &vi[1], &vi[2]);
		sort(vi.begin(), vi.end());
		printf("Case %d: %d\n", i + 1, vi[1]);

	}

	return 0;
}