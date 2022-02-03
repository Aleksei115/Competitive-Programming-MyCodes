#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

// Para utilizar la constante PI 
// De la bibliotecla cmath M_PI y otras cantidades matematicas pero se necesita usar _USE_MATH_DEFINES
// Puedo decidir la precision con std::setprecision(n) de iomanip el cual define la precision de un numero de punto flotante


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
	cout << setprecision(n + 1) << M_PI << endl;
	return 0;
}