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

	int H, D, F, day;
	float U, pos, decrease = 0;
	bool itCan = false;

	while (scanf("%d %f %d %d", &H, &U, &D, &F) && H) {
		decrease = (float)(U * F) / 100;
		day = 1;
		pos = 0;
		while (true) {

			pos += U;

			// Si todavia puedo subir, le da fatiga 
			if (U > 0)
				U -= decrease;

			// Si el caracol alcanza la cima
			if (pos > H) {
				itCan = true;
				break;
			}

			// En la noche cae
			pos -= D;

			// Despues de caer evaluar si es nagativo su subida

			if (pos < 0) {
				break;
			}

			++day;


		}

		if (itCan)
			cout << "success on day " << day << endl;
		else
			cout << "failure on day " << day << endl;

		itCan = false;
	}

	return 0;
}
// 10 2 1 50
// 50 5 3 14
// 50 6 4 1
// 50 6 3 1
// 1 1 1 1


