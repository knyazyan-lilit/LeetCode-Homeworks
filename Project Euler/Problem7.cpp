#include <iostream>
bool isPrime(int i){
    if(i<=1){
        return false;
    }
    for(int j=2;j<i;++j){
        if(i%j == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int i=1;
    int counter=0;
    while(counter<6){
        
        if(isPrime(i)){
            ++counter;
          
        }
          ++i;
    }
    --i;
    std::cout<<i;
    return 0;
}