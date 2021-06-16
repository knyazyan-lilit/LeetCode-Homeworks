#include <iostream>
#include <vector>

void BubbleSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr.size() - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j + 1], arr[j]);
            }
        }
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
    std::vector<int> arr{3, -5, 27, 58, 7, 12, 27, 4};
    print(arr);
    BubbleSort(arr);
    print(arr);
    return 0;
}