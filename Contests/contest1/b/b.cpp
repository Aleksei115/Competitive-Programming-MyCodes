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

map<char,string> mp;

void solution(int iteraciones,string raiz){
    string tmp;
    int aLen = 0,index;
    char c;
    
    for(int i = 0; i < iteraciones; i++){
        aLen = raiz.length();
        for(int f = 0; f < aLen; f++){
            c = raiz[f];
            if(mp.find(c) != mp.end())
                tmp += mp.find(c)->second;
            else
                tmp += c;
        }
        raiz.replace(raiz.begin(),raiz.end(),tmp);
        tmp.clear();
    }

    cout<<raiz<<endl;
    
}



int main(){
    if(getenv("CP_IO"))
        setIO();    
    int n,m;
    string t,flecha,patron,raiz;
    char clave;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++){
        cin>>clave>>flecha>>patron;
        mp[clave] = patron;
    }
    cin>>raiz;
    solution(m,raiz);

    // auto iter = mp.begin();
    // while (iter != mp.end()) {
    //     cout << "[" << iter->first << ","
    //                 << iter->second << "]\n";
    //     ++iter;
    // }
    return 0;
}