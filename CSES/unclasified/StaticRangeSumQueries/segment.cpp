#include <bits/stdc++.h>

using namespace std;

void setIO(){
    string file = __FILE__;

    file = string(file.begin(), file.end()-3);
    string out_file = file + "out";
    string in_file = file + "in";

    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

// El arbol se construye sobre un array, y no importa el tamaño que tenga orignal
// siempre debe ser de tamaño igual a una potencia de dos


// Esta funcion recorre el arbol en busca de la suma de los nodos, dado un intervalo 
// El arbol siempre se empieza a llenar desde n, es el tamaño del array
// el nodo raiz siempre será la pos[1] y la pos[0] siempre será 0
// el array se rellenará con 0s

// El arbol es global, long long evita el overflow de sumas 

// Como vamos avanzando en nodos, la raiz izq siempre seran 2*root y los derechos 2*root + 1
// Si enumeramos los nodos, [] son los nodos, lo demas la numeracion
//                      [2]--1
//          2--[3]                  [4]--3
//      4--[5]    [6]--5     6--[8]     [2]--7

//              [3 2 4 5 1 1 5 33]   
// si queremos hacer la suma del intervalo [2,4]
// Tomamos primero la raiz, pero la raiz siempre tendra la suma/num mas grande/etc del intervalo [0,n-1]
// El siguiente nodo a la izq tendra el intervalo [0,n/2] Y el de la derecha[n/2+1,node_right]
// node_right seria el extremo derecho del intervalo del padre

//Si quisieramos hacer la suma del array,debemos a empezar a iterar desde la raiz, y el node_right seria n-1

vector<long long> tree;

// Recursive version
long long sumQuerySegmentTree(int root, int node_left, int node_right, int intervalLeft, int intervalRight){
    
    // Si el nodo esta completamente en el intervalo
    if(intervalLeft <= node_left && node_right <= intervalRight){
        return tree[root];
    }
    // Si el nodo es disjoint, no esta entre los valores
    // Lo primero evalua si el intervalo esta completamente a la derecha
    // El segundo evalua si el intervalo esta completamente a la izquierda
    // [1,2] y el intervalo es [5,7]
    // Aqui [1,2] el 2 que es el nodo de la derecha y es menor al intervalo de la izquierda
    if( node_left > intervalRight || node_right < intervalLeft ){
        return 0;             //No afecta la suma                                  
    }            
    int last_in_left = (node_right+node_left)/2;
    return sumQuerySegmentTree(2*root,node_left,last_in_left,intervalLeft,intervalRight) +
           sumQuerySegmentTree(2*root+1,last_in_left+1,node_right,intervalLeft,intervalRight);
    // La primera llamada recurvisa accede al arbol izq
    // La primera llamada recurvisa accede al arbol der
}

void changeValueInTree(int k, int u,int n){
    tree[n+k] = u;
    
    for(int i = (n+k)/2 ; i >= 1; i/2){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    
}



// void solution(){

// }



int main(){
    if(getenv("CP_IO"))
        setIO();    

    int n,q;
    int type;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Mientras n no sea potencia de dos, agrega ceros al array
    while(__builtin_popcount(n) != 1){
        a.push_back(0);
        n++;
    }

    // n ya es potencia de dos, por lo que definimos su tamaño para construir el arbol
    tree.resize(2*n);

    // llenanos el arbol con el array original
    // Los numeros orignales iran desde n hasta 
    for(int i = 0;i < n; i++){
        tree[n+i] = a[i];
    }

    // en este caso estoy llenando el arbol con la suma de los dos elementos
    for(int i = n-1; i >= 1; i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    // Ya creado el nodos voy a hacer los request que me piden

    for(int i = 0; i < q; i++){
        int left,right,v,u;
        cin >> type ;
        // Les resto uno para que concuerden con los indices de mi arbol
        if(type == 1){
            cin >> v >> u;
            changeValueInTree(v-1,u,n);
            
        }
        else{
            cin >> left >> right;
            left--;
            right--;
            // imprimo la suma de ese intervalo
            cout<<sumQuerySegmentTree(1,0,n-1,left,right) << "\n";
        }

        
        
    }

    return 0;
}