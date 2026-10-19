#include <iostream>
#include "sortAlgorithms.h"

void printArr(const int* arr, std::size_t n)
{
    std::cout << "arr: ";
    for (int i = 0; i != n; ++i)
    {
        std::cout << *(arr + i) << '\t';
    }
    std::cout << std::endl;
    return;
}

int main(void)
{
    int arr[12] = {5, 10, 0, 3, 10, 11, 2, 3, 15, 8, 0, 6};

#if 0 //@选择排序测试
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
#endif //!@选择排序测试

#if 0 // @插入排序测试
    for (int i = 0; i != 12; ++i)
    {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
    insertSort(arr, 11, 3);
    for (int i = 0; i != 12; ++i)
    {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
#endif // !@插入排序测试

    // @希尔排序
    printArr(arr, 12);
    shellSort(arr, 12, std::greater<int>());
    printArr(arr, 12);
    // !@希尔排序

    return 0;
}
