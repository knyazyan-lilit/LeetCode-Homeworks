#include <iostream>

int main(){
    int num = 20;
	int i = 1;
	while (i < 21) {
		if (num % i == 0) {
			++i;
		}
		else {
		        num++;
			i = 1;
		}
	}
	std::cout << num;
	return 0;
}
