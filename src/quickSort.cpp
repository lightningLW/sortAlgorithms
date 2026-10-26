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
    size_t left = leftIdx - 1;
    size_t right = rightIdx - 1;
    while (left <= right)
    {
        if (comp(*(src + left), pivot))
        {
            ++left;
            continue;
        }
        else
        {
            while (right > left)
            {
                if (comp(*(src + right), pivot))
                {
                    if (!comp(*(src + left), pivot))
                    {
                        swap(src + left, src + right);
                    }
                    else
                    {
                        break;
                    }
                }
                --right;
            }
        }
    }
    swap(src + left, src + leftIdx);
    return left;
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

    size_t mid = hoare(src, leftIdx, rightIdx, comp);

    quickSort_hoare(src, leftIdx, mid, comp);
    quickSort_hoare(src, mid + 1, rightIdx, comp);
}
