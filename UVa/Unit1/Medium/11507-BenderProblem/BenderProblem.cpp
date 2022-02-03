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
	vector<string> vs;
	string st, ant = "+x";
	while (scanf("%d", &n) && n) {

		for (int i = 0; i < n - 1; i++) {
			cin >> st;
			vs.push_back(st);

		}

		vector<string>::iterator s = vs.begin();
		for (; s != vs.end(); ++s) {
			// cout << *s << " " << ant << endl;

			if (*s == "No")
				continue;

			if (*s == "+z") {
				if (ant == "+z")
					ant = "-x";
				else if (ant == "-z") {
					ant = "+x";
				}
				else if (ant == "+x") {
					ant = "+z";
				}
				else if (ant == "-x") {
					ant = "-z";
				}

			}
			else if (*s == "-z") {

				if (ant == "+z")
					ant = "+x";
				else if (ant == "-z") {
					ant = "-x";
				}
				else if (ant == "+x") {
					ant = "-z";
				}
				else if (ant == "-x") {
					ant = "+z";
				}

			}
			else if (*s == "+y") {
				if (ant == "+y") {
					ant = "-x";
				}
				else if (ant == "-y") {
					ant = "+x";
				}
				else if (ant == "+x") {
					ant = "+y";
				}
				else if (ant == "-x") {
					ant = "-y";
				}
			}
			else if (*s == "-y") {
				if (ant == "+y") {
					ant = "+x";
				}
				else if (ant == "-y") {
					ant = "-x";
				}
				else if (ant == "+x") {
					ant = "-y";
				}
				else if (ant == "-x") {
					ant = "+y";
				}
				else
					ant = *s;

			}

		}

		cout << ant << endl;
		vs.clear();
		ant = "+x";

	}





	return 0;
}