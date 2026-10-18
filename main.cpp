#include <iostream>
#include "sortAlgorithms.h"

int main(void)
{
    int arr[5] = {0, 10, 3, 0, 10};

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
    for (int i = 0; i != 5; ++i)
    {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
    insertSort(arr, 5, std::greater<int>());
    for (int i = 0; i != 5; ++i)
    {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
#endif // !@插入排序测试

    return 0;
}
