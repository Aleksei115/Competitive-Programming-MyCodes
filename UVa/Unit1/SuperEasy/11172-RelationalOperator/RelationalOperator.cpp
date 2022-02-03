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
	long x, y;
	char c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {

		scanf("%ld %ld", &x, &y);
		if (x > y) printf(">\n");
		if (x < y) printf("<\n");
		if (x == y) printf("=\n");

	}
	return 0;
}