//Dada un fecha determinar que dia de la semana es
// Se sabe que el 9 de agosto de 2010 fue lunes

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

int diaSemana(int dia, int mes, int year) {
	int regular[] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
	int bisiesto[] = { 0,3,4,0,2,5,0,3,6,1,4,6 };

	int result1 = (year - 1) % 7;
	int result2 = (year - 1) / 4;
	int result3 = (3 * (((year - 1) / 100) + 1)) / 4;
	int result4 = (result2 - result3) % 7;
	int result5 = dia % 7;
	int d = (result1 + result4 + mes + result5) % 7;
	// int r;((year % 4 == 0 || year % 400 == 0) && year % 100 != 0 ? bisiesto[mes - 1] : regular[mes - 1])
	// r = ((year - 1) % 7 + (((year - 1) / 4) - (3 * (((year - 1) / 100) + 1)) / 4) % 7 + (year % 4 == 0 ? bisiesto[mes - 1] : regular[mes - 1]) + (dia % 7)) % 7;
	cout << d;
	return 1;
}


int main() {
	if (getenv("CP_IO"))
		setIO();

	char s[50];
	int fecha[3];
	int c = 0;

	while (cin.getline(s, 50, '/')) {
		stringstream f(s);
		f >> fecha[c];
		c++;
	}

	diaSemana(fecha[0], fecha[1], fecha[2]);



	// cout << fecha[1] << endl;


	return 0;
}