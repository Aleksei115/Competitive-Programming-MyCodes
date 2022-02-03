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

map<string,double> mp;

// bool CompareDoubles2 (double A, double B) 
// {
//     double diff;
//     diff = A - B;
//     return (diff < numeric_limits<double>::epsilon()) && (-diff < numeric_limits<double>::epsilon());
// }

bool solution(string cadena){

    string party,sep;
    stringstream ss(cadena);
    int sum = 0;
    // convierte la cadena en un stringstream y itera sobre ella guardando FDP +
    // hasta que se encuentre un FDP = 

    do{
        ss >> party >> sep;
        sum += mp[party];
    } while (sep == "+");
    // Recordemos que en el ultimo ciclo del while, se obtiene la operacion
    // De comparacion que se debe evaluar, por lo que buscamos nuestros
    // operadores en sep


    // Para este punto ss solo tiene el valor numerico del lado derecho

    int comparar;
    // Paso la informacion del stringstream a un int
    ss >> comparar;
    comparar *= 10;
    // Como podemos comparar enteros con enteros 
    // Reducimos nuestros casos de comparacion a 3
    if(sum == comparar)
        return cadena.find('=') != string::npos;
    else if(sum > comparar)
        return cadena.find('>') != string::npos;
    else 
        return cadena.find('<') != string::npos;
    

}

int main(){
    if(getenv("CP_IO"))
        setIO();    

    int numP,numQ;
    string str;
    char punto;
    int parteEntera,parteDecimal;

    cin>>numP>>numQ;

    for(int i = 0; i < numP; i++){
        //obtenemos la parte decimal como entero para que no tengamos error
        // si leemos 0.1, ya que la computadora no maneja bien las comparaciones
        // con decimales 
        cin>>str>>parteEntera>>punto>>parteDecimal;
        mp.insert({str,(parteEntera*10)+parteDecimal});
    }

    // for(auto element : mp){
    //     cout<<element.first<<endl;
    // }
    cin.ignore();

    for(int i = 0; i < numQ; i++){
        string input;
        getline(cin, input);
        cout<<"Guess #"<<i+1<<" was "<<(solution(input) ? "correct." : "incorrect.")<<endl;
    }
    
    return 0;
}