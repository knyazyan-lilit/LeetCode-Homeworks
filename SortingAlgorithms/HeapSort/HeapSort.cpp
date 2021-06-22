#include <iostream>
#include "HeapSort.h"

int Heap::index_of_parent(int i)
{
    return i / 2;
}

int Heap::index_of_left(int i)
{
    return 2 * i;
}

int Heap::index_of_right(int i)
{
    return 2 * i + 1;
}

void Heap::max_heapify(std::vector<int> &vec, int i)
{
    if (i < 0)
    {
        return;
    }
    int l = index_of_left(i);
    int r = index_of_right(i);
    int largest = 0;
    if (l <= heapsize && vec[l] > vec[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= heapsize && vec[r] > vec[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        std::swap(vec[i], vec[largest]);
    }
    max_heapify(vec, i - 1);
}

void Heap::build_max_heap(std::vector<int> &vec)
{
    heapsize = vec.size() - 1;
    for (int i = vec.size() / 2 - 1; i > 0; --i)
    {
        max_heapify(vec, i);
    }
}

void heap_sort(Heap &h, std::vector<int> &vec)
{
    h.heapsize = vec.size() - 1;
    h.build_max_heap(vec);
    for (int i = h.heapsize; i >= 1; --i)
    {
        std::swap(vec[0], vec[i]);
        --h.heapsize;
        h.max_heapify(vec, vec.size() / 2 - 1);
    }
}

