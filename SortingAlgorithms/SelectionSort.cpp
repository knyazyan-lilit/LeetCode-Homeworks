#include <iostream>
#include <vector>
void SelectionSort(std::vector<int> &arr)
{
    int index = 0;
    while (index < arr.size())
    {
        int min_ind = index;
        int j = index + 1;
        while (j < arr.size())
        {
            if (arr[j] < arr[min_ind])
            {
                std::swap(arr[j], arr[min_ind]);
                min_ind = j;
            }
            ++j;
        }
        ++index;
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
    std::vector<int> arr{3, 5, 2, 7, 12, 27, 4};
    print(arr);
    SelectionSort(arr);
    print(arr);
    return 0;
}