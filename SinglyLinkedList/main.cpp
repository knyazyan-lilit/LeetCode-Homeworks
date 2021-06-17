#include <iostream>
#include "List.h"

int main(){
    FwdList<int> L1;
    L1.push_back(4);
    L1.push_back(5);
    L1.pop_back();
    L1.insert(4,45);
    L1.pop_front();
    return 0;
}