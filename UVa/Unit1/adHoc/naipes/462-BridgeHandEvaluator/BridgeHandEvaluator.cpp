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

void solution(string cadena) {

}

int main() {
	if (getenv("CP_IO"))
		setIO();

	string fs, token;
	vector<pair<string, int>> vs;
	map<char, map<char, int>> mps;
	while (getline(cin, fs)) {
		int total = 0;
		mps.clear();
		// tokenizamos la linea
		stringstream q1(fs);
		while (getline(q1, token, ' '))
			vs.push_back({ token,0 });

		// Asignamos puntos 
		for (auto x : vs) {
			if (x.first[0] == 'A')	total += 4;
			else if (x.first[0] == 'K')	total += 3;
			else if (x.first[0] == 'Q')	total += 2;
			else if (x.first[0] == 'J')	total += 1;

			if (x.first[0] == 'K' || x.first[0] == 'Q' || x.first[0] == 'J') mps[x.first[1]][x.first[0]] += 1;
		}

		// for (auto x : mps) {

		// 	cout << x.first.first << endl;
		// }


		cout << vs[0].first << total;

		fs.clear();
		vs.clear();

	}

	return 0;
}