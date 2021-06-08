#include <iostream>


int main(){
    int sum = 0;
    int before_prev = 0;
    int prev = 1;
    int curr = prev + before_prev;
    while(curr<4000000){
        before_prev = prev;
        prev = curr;
        curr = before_prev+prev;
        if(curr%2==0){
            sum+=curr;
        }
    }
     std::cout<<sum<<std::endl;
     return 0;
}