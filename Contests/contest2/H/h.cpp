// #include <algorithm>
// #include <cstdio>
// #include <map>
// using namespace std;

// int main() {
//    int n; scanf("%d", &n);

//    map<int, int> depth;
//    long long zbr = 0;
//    for ( int i=0; i<n; ++i ) {
//       int X; scanf("%d", &X);
//       int d = 0;
//       map<int, int>::iterator it = depth.lower_bound(X);
//       if ( it != depth.end()   ) d = max(d, it->second+1);
//       if ( it != depth.begin() ) d = max(d, (--it)->second+1);
//       depth[X] = d;
//       zbr += d;
//       printf("%lld\n", zbr);
//    }
   
//    return 0;
// }

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

class BST
{
    int data;
    BST *left, *right;
 
public:
    // Default constructor.
    BST();
 
    // Parameterized constructor.
    BST(int);
 
    // Insert function.
    BST* Insert(BST*, int);
 
    // Inorder traversal.
    void Inorder(BST*);
};
 
// Default Constructor definition.
BST ::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}
 
// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}
 
// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        root->left = Insert(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}

void solution(string cadena){

}

int main(){
    if(getenv("CP_IO"))
        setIO();    
    map<int,int> tree;
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int x; scanf("%d",&x);
        // si it es != tree.begin() o tree.end()
        // Quiere decir que estamos en un nodo con hijos
        // Y debemos seguir por un cammino, depende de el valor x
        auto it = tree.lower_bound(x);

        // Si es diferente del inicio lo ponemos a la izquierda del padre
        // Y obtenemos el 
        if(it != tree.begin())
            


    }
    return 0;
}