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

	int n, p, cont = 1;
	float d, price;
	string re, proposal, require;

	while (cin >> n >> p && n != 0) {

		string name;
		int met, max = -1;

		if (cont > 1)
			printf("\n");

		cin.ignore();


		for (int i = 0; i < n; i++) {
			getline(cin, re);

		}


		for (int i = 0; i < p; i++) {
			getline(cin, proposal);
			scanf("%f %d", &d, &met);
			cin.ignore();

			if (met > max) {
				max = met;
				name = proposal;
				price = d;
			}
			else if (met == max && d < price) {
				max = met;
				name = proposal;
				price = d;
			}


			for (int j = 0; j < met; j++)
				getline(cin, require);



		}


		printf("RFP #%d\n%s\n", cont++, name.c_str());


	}

	return 0;
}