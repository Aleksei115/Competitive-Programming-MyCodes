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

void printAdjList(vector<vector<int>>& adj) {

	for (int i = 0; i < adj.size();i++) {
		cout << i << " --> ";
		for (auto x : adj[i])
			cout << x << " ";
		cout << endl;
	}
}

// void bfs(vector<vector<int>>& adj, int start) {

// 	vector<bool> visited(adj.size());
// 	int aux;

// 	// Ningun nodo ha sido visitado
// 	for (int i = 0; i < adj.size();i++)
// 		visited[i] = false;

// 	// Metemos el primer nodo a la cola
// 	queue<int> nodeQue;
// 	nodeQue.push(start);
// 	visited[start] = true;

// 	while (!nodeQue.empty()) {
// 		aux = nodeQue.front();				//obtenemos el primer elemento de la cola
// 		cout << aux << " ";
// 		nodeQue.pop();
// 		for (auto x : adj[aux]) {
// 			if (visited[x] != true) {
// 				nodeQue.push(x);
// 				visited[x] = true;
// 			}

// 		}

// 	}
// }

vector<int> reconstructPath(int start, int end, vector<int>& prev) {
	vector<int> path;
	vector<int> vi;
	for (auto at = end; at != (int)INFINITY; at = prev[at])
		path.push_back(at);

	reverse(path.begin(), path.end());

	if (path[0] == start)
		return path;
	return vi;

}

vector<int> solution_bfs(vector<vector<int>>& adj, int start) {
	vector<bool> visited(adj.size());
	int aux;

	// no one node has been visited
	for (int i = 0; i < adj.size();i++)
		visited[i] = false;

	//enqueue the first node
	queue<int> nodeQue;
	nodeQue.push(start);
	visited[start] = true;

	vector<int> prev(adj.size());
	// no one node has been visited
	for (int i = 0; i < adj.size();i++)
		prev[i] = (int)INFINITY;

	// printf("%d", prev[0]);

	while (!nodeQue.empty()) {
		aux = nodeQue.front();				//get the first node in the queue
		// cout << aux << " ";
		nodeQue.pop();
		for (auto x : adj[aux]) {
			if (visited[x] != true) {
				nodeQue.push(x);
				visited[x] = true;
				prev[x] = aux;
				cout << x << ":" << aux << " " << endl;
			}
		}

	}


	return prev;
}

vector<int> bfs(vector<vector<int>>& adj, int start, int end) {
	// This function is to find a path between node start and node end
	//For BFS we need undirected graph 

	// Do the BFS starting at node start
	auto prev = solution_bfs(adj, start);

	return reconstructPath(start, end, prev);
}





int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (getenv("CP_IO"))
		setIO();

	int v, a, u, w;

	vector<vector<int>> adjList;

	scanf("%d", &v);

	adjList.resize(v);			//the list has so many elements as number of vertex


	while (scanf("%d %d", &u, &w) != EOF) {
		adjList[u].push_back(w);
		// adjList[w].push_back(u);
	}

	printAdjList(adjList);
	auto f = bfs(adjList, 2, 1);

	for (auto x : f)
		cout << x << " ";


	return 0;
}