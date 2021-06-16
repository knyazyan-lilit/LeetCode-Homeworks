#include <iostream>
#include <cmath>

int main(){
    int c=0;
    int mul = 1;
     for(int a = 1;a < 500;++a){
         for(int b = 1; b < 500;++b){
            c = 1000-b-a;
            if(c*c == b*b + a*a && a+b+c == 1000){
                mul = a*b*c;
                break;
            }
            
        }
     }
    std::cout<<mul;
    return 0;
}

