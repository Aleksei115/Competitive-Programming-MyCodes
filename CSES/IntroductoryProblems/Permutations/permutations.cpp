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

	if (n == 1)cout << 1;
	else if (n <= 3) cout << "NO SOLUTION";
	else if (n == 4) cout << "2 4 1 3";
	else {
		// Debemos generar todos los impares hasta el numero 
		// siempre tendrán una separacion de dos estos numeros impares
		for (int j = 1; j <= n; j += 2) {
			cout << j << " ";
		}
		// Ya que acabaron, no abra numero impares consecutivos a los numeros pares
		for (int i = 2; i <= n; i += 2) {
			cout << i << " ";
		}


	}

	return 0;
}

// ------------------ Solucion no optima ------------------------------
// y = 1;

// for (int i = 1; i <= n; i++)
// vi.push_back(i);

// if (n > 1000)
// reverse(vi.end(), vi.begin());

// for (auto x : vi) {
// 	cout << x << " ";
// }
// break;
// do {


// 	while (y < n) {
// 		if (abs(vi[y - 1] - vi[y]) == 1) {
// 			isMagical = false;
// 			break;
// 		}
// 		y++;
// 	}

// 	if (isMagical) {
// 		for (auto x : vi) {
// 			cout << x << " ";
// 		}
// 		break;
// 	}


// 	isMagical = true;
// 	y = 0;


// } while (next_permutation(vi.begin(), vi.end()));

// if (!y)
// cout << "NO SOLUTION";

