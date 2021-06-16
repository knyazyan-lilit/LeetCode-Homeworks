#include <iostream>
#include <vector>

void InsertionSort(std::vector<int> &arr)
{
    for (int j = 1; j < arr.size(); ++j)
    {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
    }
}

void print(std::vector<int> arr)
{
    for (int i = 0; i < 7; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr{3, 27, -5, 58, 7, 12, 4};
    print(arr);
    InsertionSort(arr);
    print(arr);
}