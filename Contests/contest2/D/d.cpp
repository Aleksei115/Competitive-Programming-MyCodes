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

}

int main(){
    if(getenv("CP_IO"))
        setIO();    

    string line;
    vector<string> vs;
    int maxV = 0;
    map<string,int> mp;

    while (getline(cin,line) && line != "***") {
        mp[line]++;
    }

    for(auto i : mp){
        maxV = max(maxV,i.second); 
    }

    for(auto i : mp){
        if(maxV == i.second)
            vs.push_back(i.first);
    }
    
    if(vs.size() == 1)
        printf("%s",vs[0].c_str());
    else
        printf("Runoff!");



    return 0;
}