#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

void setIO(){
    string file = __FILE__;

    file = string(file.begin(), file.end()-3);
    string out_file = file + "out";
    string in_file = file + "in";

    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

long long solution(vector<vector<int>>& obstacleGrid){
    int filas = obstacleGrid.size();
    int columnas = obstacleGrid[0].size();
    int dp[filas][columnas];
        

        
//         Relleno la primera fila, para esto solo hay una manera de llegar a cualquier columna 
//         desde la primera columna por la izquierda
    for(int i = 0; i < columnas; i++){
            if( i > 0 && dp[0][i-1] == 0)
                dp[0][i] = 0; 
            else
                dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : 1; 
    }
        
            
        
//         Relleno la primera columna, para esto solo hay una manera de llegar a cualquier fila primera fila
//         desde la primera fila por arriba
    for(int j = 0; j < filas; j++){
//             si una casilla adyacente es 0, no hay manera que pueda llegar a la casilla que estoy estudiando
            if(j > 0 && dp[j-1][0] == 0)
                dp[j][0] = 0;
            else
                dp[j][0] = obstacleGrid[j][0] == 1 ? 0 : 1; 
    }
            

        
//         Solo tengo que rellenar el dp con las maneras de llegar a esa casilla por arriba o a la izquieda sumando las maneras
//         que tiene cada casilla adyacente
    for(int j = 1; j < filas; j++){
        for(int i = 1; i < columnas; i++){
            if(obstacleGrid[j][i] == 1){
                dp[j][i] = 0;
                
            }
            else
                dp[j][i] = (dp[j-1][i] + dp[j][i-1])%(long long)mod;
        }
    }
        

//         Al final la casilla de abajo a la izquieda tendra siempre sera la suma de los caminos que pueden llegar
    return dp[filas-1][columnas-1];

}

int main(){
    if(getenv("CP_IO"))
        setIO();    

    int n;
    char x;
    long long ans;
    string str;
    scanf("%d",&n);
    vector<vector<int>> obstacleGrid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>x;
            obstacleGrid[i][j] = x == '.' ? 0 : 1;
        }
       
    }

    // for (int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<obstacleGrid[i][j]<<" "; 
    //     }
    //     cout<<endl;
    // }
    ans = solution(obstacleGrid);
    printf("%lld",ans);
    return 0;
}