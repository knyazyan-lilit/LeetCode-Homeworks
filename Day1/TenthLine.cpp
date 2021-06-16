#include <iostream>
#include <fstream>

int main(){
    std::fstream f;
    f.open("file.txt");
    int numofline = 0;
    std::string line;
    while(!f.eof() &&  numofline != 10) {
        f >> line;
        if(f.peek() == '\n'){
            ++numofline;
        }
    }
    std::cout<<line<<std::endl;
    return 0;
}
