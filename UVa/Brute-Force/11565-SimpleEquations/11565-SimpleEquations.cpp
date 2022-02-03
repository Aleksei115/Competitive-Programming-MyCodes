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

void solution(int A,int B,int C){

    bool sol = false;

    for(int x = -100;x <= 100;x++)
        for(int y = -100;y <= 100;y++)
            for (int z = -100; z <= 100; z++){
                if(x != y && y != z && z != x && (x+y+z == A) && (x*y*z == B) && (x*x+y*y+z*z == C)){
                    if(!sol)printf("%d %d %d\n",x,y,z);
                    sol = true;
                }
                
            }
            

    if(!sol)cout<<"No solution."<<endl;
}

// Como x, y, z no tienen restricción una búsqueda completa se tendría que hacer sobre todos los enteros
// Esto es imposible, asi que como C tiene como máximo valor 10,000 y siempre quiero que x sea el menor posible
// y que no pueden repetirse valores, calcularemos C con el valor de y,z más pequeño de enteros positivos
// utilizamos a C porque nos dará tanto un valor positivo como negativo y delimitará el rango de enteros en los que tengo que probar
// Asi que se tiene --> x^2 + 1 + 2 = 10,000
// y se obtiene que x = -+ 99.91 que redondeando x = -+ 100
// Apartir de aqui x solo puede tomar valores de -100 hasta 100
// y además x tiene que ser siempre el más pequeño por lo que delimitamos todos los intervalos de las otras variables al de x


int main(){
    if(getenv("CP_IO"))
        setIO();    

    int n;
    int a,b,c;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d %d %d",&a,&b,&c);
        solution(a,b,c);
    }
    return 0;
}