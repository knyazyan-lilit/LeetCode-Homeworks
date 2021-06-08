#include <iostream>

int square_of_sum(unsigned int num){
    int sum = 0;
    for(int i = 0;i <= num; ++i){
        sum+=i*i;
    }
    std::cout<<sum<<std::endl;
    return sum;
}

int sum_of_square(unsigned int num){
    int sum = 0;
    for(int i = 0;i <= num; ++i){
        sum+=i;
    }
    sum =sum* sum;
     std::cout<<sum<<std::endl;
    return sum; 
}


int main(){

    int res = 0;
    res = sum_of_square(100) - square_of_sum(100);
    std::cout<<res;
    return 0;  

}