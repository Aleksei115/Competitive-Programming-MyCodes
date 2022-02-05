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

char mat[1001][1001];
bool visited[1001][1001];
int n, m;

bool isDot(int y, int x) {

	if (x < 1 || x > m || y < 1 || y > n) return false;				//Significa que la coordenada que estoy buscando esta fuera de mi matriz
	if (visited[y][x] == true || mat[y][x] == '#') return false; 	//Si ya se visiton esa celda o la celda tiene un # no puede haber punto
	return true;   													//En cualquier otro caso es un punto 

}


void DFS(int i, int j) {

	// Como solo hay 4 direciones debo ver si aplico de nuevo el dfs en caso de que sea un punto

	// Marco como visitado la celda i,j
	visited[i][j] = true;

	//Pregunto si la celda de arriba es un punto
	if (isDot(i - 1, j))
		DFS(i - 1, j);

	//Pregunto si la celda de abajo es un punto
	if (isDot(i + 1, j))
		DFS(i + 1, j);

	//Pregunto si la celda de la izquierda es un punto
	if (isDot(i, j - 1))
		DFS(i, j - 1);

	//Pregunto si la celda de la derecha es un punto
	if (isDot(i, j + 1))
		DFS(i, j + 1);


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (getenv("CP_IO"))
		setIO();


	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			visited[i][j] = false;
		}
	}

	int numberRooms = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == '.' && visited[i][j] == false)
				DFS(i, j), numberRooms++;
			//Mando a llamar el DFS de esa celda para saber si esta conectada con 
			//paredes o con puntos, si hay más puntos hago el DFS de esos puntos 
		}
	}

	cout << numberRooms;

	return 0;
}