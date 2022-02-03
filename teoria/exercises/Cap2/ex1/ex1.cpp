//Sumar todos los enteros dados en una linea con lineas indefinidas

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

	int n = 1;
	char line[50];
	string token;
	int total = 0, x;
	while (cin.getline(line, 50)) {
		if (n > 1) printf("\n");
		stringstream ss(line);
		while (getline(ss, token, ' ')) {
			stringstream t(token);
			t >> x;
			total += x;
		}
		cout << total;
		total = 0;
		n++;
	}


	return 0;
}