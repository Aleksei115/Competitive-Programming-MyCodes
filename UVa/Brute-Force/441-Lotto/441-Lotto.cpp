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

void solution(vector<int> s,int k){
    // Problema de Fuerza Bruta
    // 7 --- 1 2 3 4 5 6 7
    // Primero agotamos todas las posibilidades que hay de combinar los numeros iniciando
    // Con el mas pequeño posible 
    // Vamos sustituyendo siempre en orden ascendente
    // Primero 1 2 3 4 5 6 siempre empezamos la combinacion con el n-1 que seria 6
    // Luego   1 2 3 4 5 7 luego vamos sustituyendo al más grande
    // Para este punto dejaremmos constante al ultimo más grande ya que no podremos poner 7 6
    // y seguimos combinando el digito en la posicion 5 desde el más pequeño al más grande
    // Una vez que se llegue en esa posicion al 6 sería el más grande disponible
    // Se reduce la posición y empezamos combinando desde el número más pequeño al más grande disponible que si se sigue seria 5
    // Asi hasta la primera posición donde primero hicimos las combinaciones con el 1 y al final con el 2 que terminaria siendo
    // El entero más grande disponible
    // Asegurando siempre que esten ordenados en forma ascendente 



    for(int a = 0; a < k-5; a++)
        for(int b = a+1; b < k-4; b++)
            for(int c = b+1; c < k-3; c++)
                for(int d = c+1; d < k-2; d++)
                    for(int e = d+1; e < k-1; e++)
                        for(int f = e+1; f < k; f++)
                            printf("%d %d %d %d %d %d\n",s[a],s[b],s[c],s[d],s[e],s[f]);

        

}

// El if(n++)printf("\n") se ejecuta de la sig manera
// como hacemos un post-incremento evaluamos si n != 0 y luego hacemos un incremento
// Por lo que la primera iteracion no entra
// pero se incremento a 1
// despues volvemos a preguntar si  n != 0 y como es 1 entra, inmediatamente despues incrementa n = 2
// e imprimimos el primer salto de linea
// para el segundo numero ese salto de linea no se debe imprimir
// Se hacen las impresiones de las combinaciones y despues entra al ciclo pero esta vez
// K == 0 y se sale del ciclo antes de entrar al if
// Otra forma de hacerlo es con un contador


int main(){
    if(getenv("CP_IO"))
        setIO();    

    int k,cont = 0;
    while(scanf("%d",&k)){
        if(k == 0) break;
        cont++;
        if(cont > 1)printf("\n");  
        vector<int> s(k);
        for (int i = 0; i < k; i++){
            scanf("%d",&s[i]);
        }  
        solution(s,k);

        
    }



    return 0;
}

/*

1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7


*/