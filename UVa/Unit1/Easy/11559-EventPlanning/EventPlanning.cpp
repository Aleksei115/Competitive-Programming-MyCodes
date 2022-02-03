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

	vector<int> datos(4);
	int precio;
	int auxPrecio = 0;
	bool itCan = false;
	while (cin >> datos[0] >> datos[1] >> datos[2] >> datos[3]) {


		vector<int> semanas(datos[3]);

		while (datos[2]--) {
			scanf("%d", &precio);
			for (int j = 0; j < datos[3]; j++) {
				cin >> semanas[j];
			}

			for (auto& h : semanas) {
				// cout << "for: " << h << endl;
				if (h >= datos[0]) {
					itCan = true;
					if (auxPrecio > precio || auxPrecio == 0)
						auxPrecio = precio;
				};
			}

		}

		if (auxPrecio) {
			if (auxPrecio * datos[0] <= datos[1]) {
				printf("%d\n", auxPrecio * datos[0]);
			}
			else
				printf("stay home\n");
		}
		else
			printf("stay home\n");

		auxPrecio = 0;
		precio = 0;
		itCan = false;

	}

	return 0;
}

