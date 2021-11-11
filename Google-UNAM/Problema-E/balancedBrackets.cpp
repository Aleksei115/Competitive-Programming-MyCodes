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

void solution(string cadena){

    stack<char> st;
    int f = -1,res = 0;
    
    for(int i = 1; i <= cadena.length(); i++){
        char c = cadena[i];
        char ant = cadena[i-1]; 
        stringstream cadena1,cadena2;
        cadena1<<c;
        cadena2<<ant;
        int x,y;
        cadena1>>x;
        cadena2>>y;
        if (x != f && y != 0){
            
            if(x != y){
                for(int i = 0; i < y; i++){
                    cout<<'(';
                }
            }
            cout<<y;
            res = y-x;
            if(x != y){
                for(int i = 0; i < res;i++){
                        cout<<')';
                }
            }
            f = y;

        }
        else{
            cout<<y;
        }
        

        
    }
    cout<<endl;


}

int main(){
    if(getenv("CP_IO"))
        setIO();    

    int n;
    string f;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        cin>>f;
        solution(f);
        f.clear();
    }
    
    return 0;
}




    // bool es = true;
    // char aux,c;
    // // cout<<cadena<<endl;
    // for(int i = 0; i < cadena.length();i++){
    //     c = cadena[i];
    //     if(c == 40 || c == 91 || c == 123)
    //         st.push(c);  
    //     else{
    //         if(!st.empty()){
    //             aux = st.top();

    //             if(aux == '(' && c != ')')es = false;
    //             if(aux == '[' && c != ']')es = false;
    //             if(aux == '{' && c != '}')es = false;
    //             st.pop();
    //         }
    //         else
    //             es = false;
    //     }

    // }

    // if(!st.empty())
    //     es = false;

    // if(!es)
    //     cout<<"NO"<<endl;
    // else
    //     cout<<"YES"<<endl;
                 

// }





/*
Caso #1: 0000
Caso #2: (1)0(1)
Caso #3: (111)000
Caso #4: (1)
Caso #5: (((3))1(2))
*/