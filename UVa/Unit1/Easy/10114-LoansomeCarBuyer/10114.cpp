#include <bits/stdc++.h>

using namespace std;

int main(){

    int nM,nI,mT,cont = 0;
    double fP,loan,iA,csC,pPM;
    double meses[101];
    vector<int> v;
    while(scanf("%d %lf %lf %d",&nM,&fP,&loan,&nI) == 4){        

        if(nM < 0)
            break;

        csC = (double)loan + fP;
        pPM = (double)loan/nM;

        while(nI--){
            scanf("%d %lf",&mT,&iA);
            for(int i = mT; i < 101;i++)
                meses[i] = iA;
        }

        csC = (csC -(csC*meses[0]));        //Devaluacion inicial

        while(csC < loan){
            
            cont +=1 ;
            csC = (csC -(csC*meses[cont]));
            loan -= (double)pPM;   
        }
    
        v.push_back(cont);
        cont = 0;
    
    }

    for(auto i = v.begin(); i != v.end();i++){
        if(*i == 1)
            printf("%d month\n",*i);
        else
            printf("%d months\n",*i);
    }

    return 0;
}

