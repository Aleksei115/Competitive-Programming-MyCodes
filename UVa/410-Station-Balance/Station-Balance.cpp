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

vector<int> vi;

void solution(int chambers,int total,int m,int set){

    // 2S > C    2S-C + vector
    int add = (2 * chambers) - m;
    int imbalance = 0;

    for(int i = 0; i < add; i++){
        vi.push_back(0);
    }

    sort(vi.begin(),vi.end());


    cout<<"Set #"<<set<<endl;

    for (int i = 0; i < chambers; i++){

    }
    

}

int main(){
    if(getenv("CP_IO"))
        setIO();    
    
    int n,m,totalMass = 0,set = 1,x;
    while (cin>>n>>m){
        for (int i = 0; i < m; i++){
            cin>>x;
            vi.push_back(x);
            totalMass += x;
        }
        solution(n,totalMass,m,set);
        set++;
        totalMass = 0;
        vi.clear();
    }

    return 0;
}