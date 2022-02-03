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

	ios::sync_with_stdio(0);
	cin.tie(0);
	if (getenv("CP_IO"))
		setIO();

	int n, itCan = 0, aux = 0, len;
	vector<int> v1, v2, v0;
	scanf("%d", &n);

	itCan = (n * (n + 1)) / 2;

	if (itCan % 2 == 1) {
		cout << "NO";
		return 0;
	}
	itCan /= 2;
	for (int i = 1; i <= n; i++)
		v0.push_back(i);

	// for (auto x : v0)
	// 	cout << x << " ";

	while (true) {

		aux += v0[0];
		cout << aux << " " << itCan << endl;
		if (aux > itCan) {
			aux -= v0[0];
			if (aux == itCan)
				break;
		}

		v1.push_back(v0[0]);
		v0.erase(v0.begin());

		len = v0.size();
		aux += v0[len - 1];

		if (aux > itCan) {
			aux -= v0[len - 1];
			if (aux == itCan)
				break;
		}

		v1.push_back(v0[len - 1]);
		v0.pop_back();

	}


	// for (int i = 1; i < n; i++) {
	// 	ant = i;
	// 	if (aux1 < itCan / 2) {
	// 		aux1 += i;
	// 		cout << aux1 << " ";
	// 		if (aux1 < itCan / 2)
	// 			v1.push_back(i);
	// 		else {
	// 			aux2 = i;
	// 			continue;
	// 		}

	// 	}
	// 	else if (aux2 || aux1 >= itCan / 2)
	// 		v2.push_back(i);

	// 	aux2 = 0;

	// }
	// cout << endl;
	for (auto x : v1)
		cout << x << " ";
	// cout << endl;
	// for (auto x : v2)
	// 	cout << x << " ";


	return 0;
}