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

	int aux = 0, res = 1;
	long long itCan = 0, n;
	vector<int> v1, v2, v0;
	scanf("%ld", &n);

	itCan = (long long)(n * (n + 1)) / 2;

	if (itCan % 2 == 1) {
		cout << "NO";
		return 0;
	}
	itCan /= 2;
	aux = n - 1;

	if (n % 2 == 0) {
		for (int i = 1; i <= n / 2; i++) {
			if (res % 2 != 0) {
				v1.push_back(i);
				v1.push_back(i + aux);
			}
			else {
				v2.push_back(i);
				v2.push_back(i + aux);
			}
			res++;
			aux -= 2;
		}

	}
	else {
		aux--;
		for (int i = 1; i <= n / 2; i++) {
			if (res % 2 != 0) {
				v1.push_back(i);
				v1.push_back(i + aux);

			}
			else {
				v2.push_back(i);
				v2.push_back(i + aux);
			}
			res++;
			aux -= 2;
		}
		if (res % 2 == 0)
			v2.push_back(n);
		else
			v1.push_back(n);

	}



	cout << "YES" << endl << v1.size() << endl;
	for (auto x : v1)
		cout << x << " ";
	cout << endl << v2.size() << endl;
	for (auto x : v2)
		cout << x << " ";

	return 0;
}