#include <iostream>
#include <vector>

class Heap
{
private:
    size_t heapsize;
public:
    int index_of_parent(int i);
    int index_of_left(int i);
    int index_of_right(int i);
    void max_heapify(std::vector<int> &vec, int i);
    void build_max_heap(std::vector<int> &vec);
    friend void heap_sort(Heap &h, std::vector<int> &vec);
};