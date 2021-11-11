#include <bits/stdc++.h>

using namespace std;

int main(){

    int h,f,d,cont = 0;
    double disClim = 0,u;
    vector<string> v;
    string s1 = ("success on day ");
    string s2 = ("failure on day ");

    while(scanf("%d %lf %d %d",&h,&u,&d,&f) == 4){

        if(h == 0)
            break;
    
        
        while (true){

            cout<<"antes: "<<disClim<<endl;

            disClim += u;
            cont += 1;
            if(disClim < 0 || disClim > h)
                break;
            
            disClim -= d;
            // cont += 1;
            if(disClim < 0 || disClim > h)
                break;
            cout<<"despues: "<<disClim<<endl;
            u = u - ((u*f)/100);
            cout<<u<<endl;
            // cont += 1;
            
        }
        if(disClim > 0)
            v.push_back(s1 + to_string(cont));
        else
            v.push_back(s2 + to_string(cont));  

        disClim = 0;
        cont = 0;
    }

    for(auto i = v.begin(); i != v.end(); i++)
        cout<<*i<<endl;


    return 0;
}