/***********************************************************************************************************************
* @file: insertSort.cpp
* @brife: 插入排序实现文件
* @date: 2026-10-18
* @update: 2026-10-19
* @author: lightningLW
* @note: 为了使其应用于shell sort, 不采用: 一次移动连续内存; 而是采用逐一交换元素
***********************************************************************************************************************/

#include "sortAlgorithms.h"

void insertSort(int* src, size_t n, size_t gap, std::function<bool(int, int)> comp)
{
    if (n == 0 || gap == 0)
    {
        std::cerr << "Fault: In " << __FUNCTION__ << " n == 0 || gap == 0!\n"; 
        return;
    }
    for (int g = 0; g != gap; ++g)
    {
        for (int i = g + gap; i < n; i += gap)
        {
            int temp = *(src + i);
            for(int j = i - gap; j >= 0; j -= gap)
            {
                if (comp(temp, *(src + j)))
                {
                    *(src + j + gap) = std::move(*(src + j));
                    *(src + j) = std::move(temp);
                }
                else
                {
                    break;
                }
            }
        }
    }
    return;
}

void insertSort_mem(int* src, size_t n, std::function<bool(int, int)> comp)
{
    if (n == 0)
    {
        std::cerr << "Fault: "<< __FUNCTION__ << " n = 0!\n";
        return;
    }
    for (int i = 1; i != n; ++i)
    {
        for (int j = i - 1; j != -1; --j)
        {
            if (comp(*(src + i), *(src + j)))
            {
                if (j == 0)
                {
                    int temp = *(src + i);
                    // int* temp_ptr = new int[i - j];
                    // memcpy(temp_ptr, src + j, sizeof(int) * (i - j));
                    // memcpy(src + j + 1, temp_ptr, sizeof(int) * (i - j));
                    memmove(src + j + 1, src + j, sizeof(int) * (i - j));
                    *(src + j) = temp;
                    // delete [] temp_ptr;
                }
                continue;
            }
            else
            {
                if (j == i - 1)
                {
                    break;
                }
                int temp = *(src + i);
                memmove(src + j + 2, src + j + 1, sizeof(int) * (i - j - 1));
                *(src + j + 1) = temp;
                break;
            }

        }
    }
    return;
}
