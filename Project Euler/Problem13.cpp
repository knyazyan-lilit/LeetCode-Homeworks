#include <iostream>
#include <string>
#include <fstream>

int main(){ 
     std::fstream f;
     f.open("./file.txt");
     double sum = 0;
     double num;
     int i=0;
     while(!f.eof()){
        f>>num;
        sum+=num;
        ++i;
    }
   f.close();
   std::cout<<sum;
   return 0;
}
