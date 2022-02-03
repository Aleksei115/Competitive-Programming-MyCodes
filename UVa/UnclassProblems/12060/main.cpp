#include <bits/stdc++.h>

using namespace std;

int lengthNum(int x){
    
    int n = 0;

    while (x){
        x /= 10;
        ++n;    
    }
    
    return n;
    
}


int gcd(int a,int b){
    if(b)
        return  gcd(b,a%b);
    return a;
}

void printN(bool negative,int disAvg,int disLN,int num){
    if(negative)
        cout<<"  ";

    cout<<string(disAvg, ' ')<<setw(disLN)<<abs(num)<<'\n';
}

void solution(int avg,int n,int cas){
    int num,deno,g;

    printf("Case %d:\n",cas++);

        if(avg % n == 0){

            if(avg < 0)
                cout<<"- ";
        
            cout<<abs(avg / n)<<endl;
        }
        else{
            bool negative = avg<0;
            avg = abs(avg);

            num = avg % n; 
            avg /= n;
 

            g = gcd(num,n);                                // OBTENEMOS EL GCD 

            num /= g; deno = n / g;

            int mayor = max(lengthNum(deno),lengthNum(num));        //considera 23/3 0 3/23

            printN(negative,lengthNum(avg),mayor,num);

            if(negative)
                cout<<"- ";
            if(lengthNum(avg))
                cout<<avg;
            cout<<string(mayor, '-')<<"\n";
            printN(negative,lengthNum(avg),mayor,deno);

        }
}


int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n,e,avg = 0,cas = 1;


    while(scanf("%d",&n) == 1,n){
        
        avg = 0;

        for(int i = 0; i < n; i++){
            scanf("%d",&e);
            avg += e;
        }
        solution(avg,n,cas++);
        
    }

    return 0;
}


