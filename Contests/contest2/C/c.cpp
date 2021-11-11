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

    int n,p,m;
    string line;
    int points = 0;
    map<string,int> mp;

    vector<string> vs;

    scanf("%d %d %d",&n,&p,&m);
    cin.ignore();
    for(int i = 0; i<n;i++){
        getline(cin,line);
        mp[line] = 0; 
    }

    for(int i = 0; i<m;i++){
        cin>>line>>points;
        mp[line] += points; 
    }

    auto it = mp.begin();
    while(it != mp.end()){
        if(it->second >= p)
            vs.push_back(it->first);
        it++;
    }

    if(vs.empty()){
        cout<<"No winner!";
    }
    else{
        for(string i : vs){
            cout<<i<<" wins!"<<endl;
        }
        // for(int i = vs.size()-1; i >= 0; i--){
        //     cout<<vs[i]<<" wins!"<<endl;
        // }
    }


    // while (getline(cin,line) && line != "***") {
    //     mp[line]++;
    // }
    return 0;
}