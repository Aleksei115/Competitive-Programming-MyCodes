#include <bits/stdc++.h>

using namespace std;

//! Creo mi clase graph que es un grafo no dirigido

class Graph
{

    // Es el numero de vertices que tiene el grafo
    int V;
    
    //  Creamos un apuntador a un array de listas de enteros para instanciar el objeto en el constructor
    list<int> *ListAdj;
    map<int, bool> visited;
    // Regresara la altura maxima del grafo

    int useDFS(int currentNode,int h);

public:
    int maxH = 0;
    Graph(int V);
    void addEdges(int,int);
    void showElements(); 
    void DFS(int);
    // ~graph();
};

//  Este es mi constructor
Graph::Graph(int V){

    //  Cuando creamos nuestro objeto le añadimos el numero de vertices a su atributo V
    this->V = V;
    //  instanciamos una lista de enteros de tamaño V en nuestro apuntador;
    ListAdj = new list<int>[V+1];
}

void Graph::addEdges(int U,int V){
    ListAdj[U].push_back(V);
    ListAdj[V].push_back(U);
}


// Muestra todos los enlaces de cada nodo
void Graph::showElements(){
    for(int i = 1; i <= this->V; i++){    
        cout<<"NODO: "<<i<<"\n";
        for(auto it = ListAdj[i].begin(); it !=  ListAdj[i].end(); it++){
            cout << '\t' << *it;
            cout << '\n';
        }
    }
}

// void Graph::DFS(int bob){

//     int heightAlice = useDFS(1,0);
//     int heightBob = useDFS(bob,0);
//     cout<<heightAlice;
//     // for (int i = 1; i < V; i++){
//     //     useDFS(i);

//     //     // maxH = maxH > aux ? maxH : aux;
//     // }
// }

int Graph::useDFS(int currentNode,int h){
  
    visited[currentNode] = true;

    // cout << currentNode << " ";

    for (auto i = ListAdj[currentNode].begin(); i != ListAdj[currentNode].end(); i++){
        if (!visited[*i])
            useDFS(*i,h+1);

        else if(visited[*i]){
            // cout<<"altura: "<<h<<" ";
            maxH = maxH > h ? maxH : h; 
        }
    }

    return this->maxH;

}








void setIO(){
    string file = __FILE__;

    file = string(file.begin(), file.end()-3);
    string out_file = file + "out";
    string in_file = file + "in";

    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

// void solution(string cadena){

// }

int main(){
    if(getenv("CP_IO"))
        setIO();    

    int v,stB;
    cin>>v>>stB;

    Graph myGrafo(v);

    for (int i = 1; i < v; i++){
        int v1,v2;
        cin>>v1>>v2;
        // cin>>vi[i]>>vi[i];
        myGrafo.addEdges(v1,v2);
        // myGrafo.addEdges(0,1);
        // myGrafo.addEdges(0,1);
    } 
    myGrafo.DFS(stB);
    // cout<<myGrafo.maxH*2;
    // myGrafo.showElements();     

    return 0;
}