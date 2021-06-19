#include <iostream>
#include <vector>


void Merge(std::vector<int>& arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m ;
    std::vector<int> Larr(n1);
    std::vector<int> Rarr(n2);
    int x = l;
    for (int i = 0; i < n1; ++i)
    {
        Larr[i] = arr[x++];
    }
    for (int i = 0; i < n2; ++i)
    {
        Rarr[i] = arr[x++];
    }
    int k = l;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (Larr[i] < Rarr[j])
        {
            arr[k] = Larr[i];
            ++i;
        }
        else
        {
            arr[k] = Rarr[j];
            ++j;
        }
        ++k;
    }
    while (i < n1)
    {
        arr[k] = Larr[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        arr[k] = Rarr[j];
        ++j;
        ++k;
    }
}
void MergeSort(std::vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        int m = (r + l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}
void print(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    std::vector<int> arr{ 3, -5, 27, 58, 45, 2, 12, -6, 0 };
    print(arr);
    MergeSort(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}