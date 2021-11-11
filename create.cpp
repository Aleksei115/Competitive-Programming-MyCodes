
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
  
int main(int argc, char** argv) {
  
    if (mkdir(argv[1]) == -1)
        cerr << "Error :  " << strerror(errno) << endl;
    else{
        string ruta = argv[1];
        string filename = argv[2];

        filename = string(filename.begin(), filename.end());
        string out_file = filename + ".out";
        string in_file = filename + ".in";
        string fileExcersise = filename + ".cpp";
        
        system(("type nul >" + ruta + "/" + out_file).c_str());
        system(("type nul >" + ruta + "/" + in_file).c_str());
        system(("type nul >" + ruta + "/" + fileExcersise).c_str());
        cout << "Directory created";
   }
        
}