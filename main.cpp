#include <iostream>
#include "sortAlgorithms.h"

int main(void)
{
    int arr[5] = {5, 10, 1, 0, 10};
    for (int i = 0; i != 5; ++i)
    {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
    selectionSort(arr, 5, std::greater<int>());
    for (int i = 0; i != 5; ++i)
    {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
    return 0;
}
