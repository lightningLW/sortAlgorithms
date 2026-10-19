/***********************************************************************************************************************
* @file: shellSort.cpp
* @brife: 希尔排序实现文件
* @date: 2026-10-19
* @update: 
* @author: lightningLW
* @note: 
***********************************************************************************************************************/

#include "sortAlgorithms.h"
#include <vector>

/******************************************************
* @brife: 获取Knuth序列的gap
* @param n: 待排序序列长度
* @return: gap 的 vector 
* @note: 计算后gap 放在vector中(从小到大)
******************************************************/
static std::vector<int> gap_Knuth(size_t n)
{
    std::vector<int> gap;
    int temp = 1;
    size_t tempGap = 0;
    while (true)
    {
        temp *= 3;
        tempGap = (temp - 1) >> 1;
        if (tempGap < n)
        {
            gap.push_back(tempGap);
        }
        else
        {
            break;
        }
    }
    return std::move(gap);
}

void shellSort(int* src, size_t n, std::function<bool(int, int)> comp)
{
    if (n <= 1)
    {
        return;
    }
    std::vector<int> gap = gap_Knuth(n);
    for (auto crit = gap.crbegin(); crit != gap.crend(); ++crit)
    {
        insertSort(src, n, *crit, comp);
    }
    return;
}
