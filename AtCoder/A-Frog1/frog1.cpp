/*

Funcion
	dp(i)                   recibe el numero de piedra en el que esta

Casos base


Funcion de transicion
	dp[i+1] = min(array[i+1],dp[i] + |hi-hj|)
	dp[i+2] = min(array[i+2],dp[i] + |hi-hj|)

dp = [10,]
array = [10,30,40,20]

4
10 30 40 20

---- 0 -----
dp[i+1] = min(30,10 + 20)  = 30



*/

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

int vi[100000 + 1];
int dp[100000 + 1];

int solution(int stone, ) {

	int cost = 0;

	if (stone == 3)
		return cost;
	else {
		if (stone >= 1)
			cost = abs(vi[stone] - vi[stone + 1])
			return min(solution(stone + 1, ), solution(stone + 2, abs(vi[stone] - vi[stone + 2])));
	}

}

int main() {
	if (getenv("CP_IO"))
		setIO();

	int n;
	scanf("%d", &n);
	memset(vi, INT32_MAX, 100000);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &vi[i]);
	}
	// dp[1] = 1;

	cout << solution(0, 0);
	return 0;
}