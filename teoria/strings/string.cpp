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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(getenv("CP_IO"))
        setIO();    

    // Creamos un string con el contenido 2019
    string mystr("2019");
    // Creamos un entero que le pasaremos el string 
    //Para hacer una conversion de string a entero
    int myInt;

    // utilizamos stringstream con el operador >> que pasara
    // nuestra cadena mystr a myInt
    // El operador >> recibe el nombre de operador de extraccion
    // extraemos la info de la variable mystr a myInt
    stringstream (mystr)>>myInt;

    cout<<"Mi variable myInt con el valor de mystr: "<<myInt<<" si le sumamos 1 "<<myInt+1<<"\n";
    cout<<"Mi string original "<<mystr<<endl;

    // podemos usar el metodo find para saber si hay s2 es substring de s1

    string s1 = "CDU + FDP + SPD + DIELINKE = 70";
    string s2 = "SPD";

    if(s1.find(s2) != string::npos)
        cout<<"HOla";

    return 0;
}