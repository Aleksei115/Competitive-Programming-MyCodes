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

string a,b;
int lengthOriginal = 0;
string sol = "",st = "";

bool string_comp(const char& lhs, const char& rhs)
{

    if (tolower(lhs) == tolower(rhs))
        return lhs < rhs;
    else
        return tolower(lhs) < tolower(rhs);
}


bool comp(string a,string b){
    sort(a.begin(),a.end(),string_comp);
    sort(b.begin(),b.end(),string_comp);
    return a == b;
}




void solution(int n,string cadena,string anagram1,string st,string sol){


    if(n == lengthOriginal<<1){
        if(anagram1 == b)   
            cout<<sol<<"\n";
        return;
    } 

    //Para hacer un push se debe considerar que exista una letra para hacer push    
    // Cuando hacemos un push quitamos primer caracter, agregamos el push a sol y el caracter al stack
    if(cadena.length())
        solution(n+1,cadena.substr(1,cadena.length()-1),anagram1,st + cadena[0],sol + (n ? " i": "i")); 
    
    // Solo puedo hacer pop si existe algo en el stack

    if(st.length() && (st[st.length()-1] == b[anagram1.length()]))
        solution(n+1,cadena,anagram1 + st[st.length()-1],st.substr(0,st.length()-1),sol + " o");
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    if(getenv("CP_IO"))
        setIO();    

    while (cin>>a>>b){
        lengthOriginal = a.length();
        cout<<"[\n";
        if(comp(a,b))
            solution(0,a,"",st,sol);
        cout<<"]\n";
    }
    
    return 0;
}


