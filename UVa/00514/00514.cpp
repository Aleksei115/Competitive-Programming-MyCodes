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

void solution(vector<int> vi,int n,int inicial,int final){

    stack<int> st;
    int tmp;

    if(n == 1)
        cout<<"Yes\n";
    else{
        for(int &i : vi)
            st.push(i);
        

        if(inicial > final){

            for (int i = final; i < inicial; i++){
                tmp = st.top();
                if(tmp != i){
                    cout<<"No\n";
                    return;
                }
                st.pop();
            }
    
        }
        else{
            for (int i = final; i > 0 ; i--){
                tmp = st.top();
                if(tmp != i){
                    cout<<"No\n";
                    return;
                }
                st.pop();
            }
        }
        cout<<"Yes\n";
    }
    

    
}

int main(){
    if(getenv("CP_IO"))
        setIO();    

    int n,x;
    vector<int> v;
    while (scanf("%d",&n),n){

        while (true){
            
            for (int i = 0; i < n; i++){
                scanf("%d",&x);
                if(x == 0)
                    break;
                v.push_back(x);
            }

            if(x == 0){
                cout<<"\n";
                break;
            }

            solution(v,n,v[0],v[n-1]);

            v.clear();
        }
        
        
    }
    
    return 0;
}