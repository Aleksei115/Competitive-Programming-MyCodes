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

void solution(map<string, float> &temp_map,int total){

    for(auto i : temp_map){
        cout<<i.first<<" ";
        printf("%.4lf\n",(((i.second)/total)*100));
    }
}

int main(){
    if(getenv("CP_IO"))
        setIO();    

    string line;
    int n,total;
    map<string,float> mp;
    scanf("%d",&n);
    // Estos dos getchar son para obtener el caracter a lado de 2*
    // y la linea vacia seguida del numero
    getchar();
    getchar();

    while(n--){
        
        total = 0;
        mp.clear();

        while (getline(cin,line) && line != "") {

            mp[line]++;
            total += 1;
        }
        solution(mp,total);
        // Mientras no se acaben los request se debe poner una linea vacia no un salto de linea
        if(n)
			puts("");
    }


    return 0;
}