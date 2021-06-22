#include <iostream>
#include "HeapSort.h"

void print(std::vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::vector<int> v{12,34,5,1,-8,};
    print(v);
    Heap h;
    heap_sort(h,v);
    print(v);
}