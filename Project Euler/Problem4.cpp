#include <iostream>
#include <string>

int reverse(int num){    
    int rem = 0;
    int reversed = 0;
    while(num!=0){
        rem = num%10;
        reversed = reversed * 10 + rem;
        num = num /10;
    }
    return reversed;
}

bool is_palondrome(int num){
    if(num == reverse(num)){
        return true;
    }
    return false;
}

int main(){
    int max = 0;
    for(int i = 100;i<1000;++i){
        for(int j = 100;j<1000;++j){
            if(is_palondrome(i*j)){
                max = (i*j >= max) ? i*j : max;
            }
        }
    }
    std::cout<<max;
    retrun 0;
}
