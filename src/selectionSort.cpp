/***********************************************************************************************************************
* @file: selectionSort.cpp
* @brief: 选择排序实现文件
* @date: 2026-10-18
* @update:
* @author: lightningLW
* @note:
***********************************************************************************************************************/

#include "sortAlgorithms.h"

void selectionSort(int *src, size_t n, std::function<bool(int, int)> comp)
{
    if (n == 0)
    {
        std::cerr << "Fault: "<< __FUNCTION__ << " n = 0 \n";
        return;
    }
    for (int i = 0; i != n - 1; ++i)
    {
        int temp = *(src + i);
        size_t swapIdx = i;
        for (int j = i+1; j != n; ++j)
        {
            if (!comp(temp, *(src + j)))
            {
                temp = *(src + j);
                swapIdx = j;
            }
        }
        //将剩余序列中的最小值交换到前面
        swap(src + i, src + swapIdx);
    }
    return;
}
