#include <iostream>
#include <string>


double factorial(double x) {
 	double temp;
	if (x <= 1) return 1;
	
	temp = x * factorial(x - 1);
	return temp;
}

int main(){
    double n=factorial(100);
    std::string str = std::to_string(n);
    int sum =0;
    for(int i=0 ; i< str.size();++i){
        sum += str[i]-'0';
    }
    std::cout<<sum;
    return 0;
}