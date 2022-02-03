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

bool string_comp(const char& lhs, const char& rhs)
{

    if (tolower(lhs) == tolower(rhs))
        return lhs < rhs;
    else
        return tolower(lhs) < tolower(rhs);
}


string str;

void solution(){
    
    sort(str.begin(),str.end(),string_comp);
    
    do {
        cout<<str<<"\n";
    }while (next_permutation(str.begin(),str.end(),string_comp));
}

int main(){
    if(getenv("CP_IO"))
        setIO();    

    int n;
    
    scanf("%d",&n);
    for (int  i = 0 ; i < n; i++) {
        cin>>str;
        solution();
    }
    return 0;
}
