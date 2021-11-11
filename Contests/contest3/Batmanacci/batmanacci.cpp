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



char batman(int n,unsigned long long k,unsigned long long *fibonacci){
    if(n==1) return 'N';
    if(n==2) return 'A';

    // Tomar el fibo n-2
    unsigned long long numFibo = fibonacci[n-2];

    return numFibo < k ? batman(n-1,k-numFibo,fibonacci) : batman(n-2,k,fibonacci);

}



int main(){
    if(getenv("CP_IO"))
        setIO();    

    unsigned long long fibo[88];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 88; i++) fibo[i] = fibo[i-2] + fibo[i-1];
    int n;
    unsigned long long k;
    scanf("%u %llu",&n,&k);
    n = n > 89 ? 89 : n;
    printf("%c\n",batman(n,k,fibo));
    return 0;

} 




    //SI la letra no esta en la secuencia fibo n-2
    // entonces esta en la secuencia n-1
    // resto letras sobrantes

    // Esta en la secuencia n-2
    // y no tengo letras sobrantes
    // N
    // A
    // N A
    // A NA
    // NA ANA
    // ANA NAANA
    // NAANA ANANAANA
    // n-2       n-1


// 1 1 2 3 5 8 13
// 7 7
// 6