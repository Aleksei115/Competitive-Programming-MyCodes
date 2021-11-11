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

    if(n == 1) { 
        printf("I hate it");
        return;    
    }
    queue<string> sol;

    for (int i = 1; i <= n; i++){
          
        if(i%2 == 1)
            sol.push("I hate ");
        else
            sol.push("I love ");

        if(i != n)
            sol.push("that ");
        
        
    }

    sol.push("it");

    while(!sol.empty()){
        cout<<sol.front();
        sol.pop();
    }
    

}

int main(){
    if(getenv("CP_IO"))
        setIO();    



    int n;
    scanf("%d",&n);
    solution(n);

    return 0;
}