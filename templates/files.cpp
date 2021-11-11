#include <bits/stdc++.h>

using namespace std;

void setIO(){
    string file = __FILE__;

    file = string(file.begin(), file.end()-3);
    string out_file = file + "in";
    string in_file = file + "out";

    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

int main(){
    if(getenv("CP_IO"))
        setIO();
    int a,b;
    while (scanf("%d %d",&a,&b),a,b){
        cout<<a<<" "<<b<<endl<<"si";
    }
    


    return 0;
}