// Dada una fecha DD,MM,AAAA ordenar por MM ascendente
// DD ascendente y edad ascendente
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

	char line[50];
	string token;
	vector<vector<int>> vi;
	vector<int> fecha(3);
	int x;

	while (cin.getline(line, 50)) {
		stringstream ss(line);
		fecha.clear();

		while (getline(ss, token, ',')) {
			stringstream si(token);
			si >> x;
			fecha.push_back(x);
		}
		vi.push_back(fecha);
	}


	for (const auto& v : vi) {
		for (const auto& e : v) {
			cout << e << " ";
		}
		cout << endl;
	}


	return 0;
}