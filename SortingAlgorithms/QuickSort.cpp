#include <iostream>
#include <vector>

int Partition(std::vector<int> &arr, int l, int r)
{
    int pivot = arr[l];
    int i = l;
    int j = r;
    while (i <= j)
    {
        if (arr[i] <= pivot)
        {
            ++i;
        }
        else
        {
            std::swap(arr[i], arr[j]);
            --j;
        }
    }
    std::swap(arr[j], arr[l]);
    return j;
}

void QuickSort(std::vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int k = Partition(arr, l, r);
        QuickSort(arr, l, k - 1);
        QuickSort(arr, k + 1, r);
    }
}

void print(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr{3, -5, 27, 58, 45, 3, 2};
    print(arr);
    QuickSort(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}