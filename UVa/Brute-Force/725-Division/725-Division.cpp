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

void solution(int n){

    bool b = false;
    for (int fghij = 1234; fghij <= 98765/n; fghij++){
        int abcde = fghij * n;
        int tmp, s = (fghij < 10000);
        // Recorremos cada digito del numero y encendemos el bit de ese digito
        tmp = abcde; while(tmp){ s |= 1 << (tmp%10); tmp /= 10;}
        tmp = fghij; while(tmp){ s |= 1 << (tmp%10); tmp /= 10;}

        if(s == (1<<10)-1){printf("%0.5d / %0.5d = %d\n",abcde,fghij,n);b = true;}

    }
    if(b == false)printf("There are no solutions for %d.\n",n);
    
}
// Steve Kleiman

int main(){
    if(getenv("CP_IO"))
        setIO();    

    int n,cont = 0;
    while(scanf("%d",&n) && n != 0){
        cont++;
        if (cont > 1)
			printf("\n");
        solution(n);
        // printf("\n");
    }
    return 0;
}

        // Si el resultado es igual a 1023 significa que en binario es 
        //  1111111110
        // Por lo que sabemos que los dos numeros usan todos los digitos sin repetición
        // Utilizamos el 0.5 para indicará que queremos 5 digitos y si no los hay
        // Entonces c++ rellena con ceros
        // el numero antes del punto indica los espacios que queremos que tenga  a la izquierda
        // Solo si el numero antes del punto es mayor que el que esta despues
        // Se verán los espacios en blanco tantos, como la resta entre los numeros de
        // Ej. 6.5 tendra 1 espacio a la izquierda
        // Esta especificacion de presicion solo aplica a enteros