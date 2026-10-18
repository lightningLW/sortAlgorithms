/**
* @file: insertSort.cpp
* @brife: 插入排序实现文件
* @date: 2026-10-18
* @update:
* @author: lightningLW
* @note:
*/

#include "sortAlgorithms.h"

void insertSort(int* src, size_t n, std::function<bool(int, int)> comp)
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
