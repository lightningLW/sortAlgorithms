/***********************************************************************************************************************
* @file: quickSort.cpp
* @brife: 快速排序实现文件
* @date: 2026-10-24
* @update: 2026-10-26
* @author: lightningLW
* @note: 
***********************************************************************************************************************/

#include "sortAlgorithms.h"


static size_t lomuto(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp = std::less<int>())
{
    size_t slowIdx = leftIdx;
    size_t quickIdx = leftIdx;
    int pivot = *(src + rightIdx - 1);
    for ( ; quickIdx != rightIdx - 1; ++quickIdx)
    {
        if (!comp(pivot, *(src + quickIdx)))
        {
            swap(src + slowIdx, src + quickIdx);
            ++slowIdx;
        }
    }
    swap(src + slowIdx, src + rightIdx - 1);
    return slowIdx;
}

static size_t hoare(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp = std::less<int>())
{
    int pivot = *(src + leftIdx);
    
    size_t i = leftIdx + 1;
    size_t j = rightIdx - 1;

    while (true)
    {
        while (i <= j && comp(*(src + i), pivot))
        {
            ++i;
        }
        while (j >= i && !comp(*(src + j), pivot))
        {
            --j;
        }
        if (j <= i)
        {
            break;
        }
        swap(src + i, src + j);
    }
    swap(src + leftIdx, src + j);
    return j;
}

void quickSort_lomuto(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp)
{
    if (rightIdx - leftIdx <= 1)
    {
        return;
    }

    size_t idx_right = lomuto(src, leftIdx, rightIdx, comp);

    quickSort_lomuto(src, leftIdx, idx_right, comp);
    quickSort_lomuto(src, idx_right + 1, rightIdx, comp);
}

void quickSort_hoare(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp)
{
    if (rightIdx - leftIdx <= 1)
    {
        return;
    }

    size_t pivotIdx = hoare(src, leftIdx, rightIdx, comp);

    // for (int i = leftIdx; i != rightIdx; ++i)
    // {
    //     std::cout << *(src + i) << "\t";
    // }
    // std::cout << std::endl;

    quickSort_hoare(src, leftIdx, pivotIdx, comp);
    quickSort_hoare(src, pivotIdx + 1, rightIdx, comp);
}
