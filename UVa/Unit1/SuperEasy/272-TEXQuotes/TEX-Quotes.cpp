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

	string line;
	bool isIn = false;
	while (getline(cin, line)) {

		for (auto c : line) {
			if (c == '\"' && !isIn) {
				cout << "``";
				isIn = true;
			}
			else if (c == '\"') {
				cout << "\'\'";
				isIn = false;
			}
			else {
				cout << c;
			}
		}

		cout << '\n';

	}


	return 0;
}