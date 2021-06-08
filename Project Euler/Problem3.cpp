#include <iostream>

bool isPrime(int i){
    for(int j=2;j<i;++j){
        if(i%j == 0){
            return false;
        }
    }
    return true;
}

int main(){
   
   int max=0;
   long int num = 600851475143;
   int i=2;
   
   while(num != 1){
       if(num%i == 0){
           num = num/i;
           max = (i >= max) ? i : max;
           
           i=2;
       }
       else{
           ++i;
           while(!isPrime(i)){
               ++i;
           }
       }
   }
   std::cout<<max;

}