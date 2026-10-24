/***********************************************************************************************************************
* @file: quickSort.cpp
* @brife: 快速排序实现文件
* @date: 2026-10-24
* @update: 
* @author: lightningLW
* @note: 
***********************************************************************************************************************/

#include "sortAlgorithms.h"

void quickSort_crudity(int* src, size_t leftIdx, size_t rightIdx, size_t partitionIdx,std::function<bool (int, int)> comp)
{
    // std::cout << "leftIdx: " << leftIdx << " rightIdx: " << rightIdx << " partitionIdx: " << partitionIdx << std::endl;
    // std::cout << "origin: " << std::endl;
    // for (size_t idx = leftIdx; idx != rightIdx; ++idx)
    // {
    //     std::cout << "[" << idx << "]=" << *(src + idx) << '\t';
    // }
    // std::cout << std::endl;
    size_t len = rightIdx - leftIdx;
    if (len <= 1)
    {
        return;
    }
    int m_src[len];
    memcpy(m_src, src + leftIdx, sizeof(int) * len);
    size_t m_leftIdx = leftIdx - leftIdx;
    size_t m_rightIdx = rightIdx - leftIdx;
    size_t m_partitionIdx = partitionIdx - leftIdx;

    size_t arg_leftIdx = leftIdx;   
    size_t arg_rightIdx = rightIdx;

    int partitionVal = *(src + partitionIdx);
    for (size_t idx = 0; idx != m_rightIdx; ++idx)
    {
        if (idx == m_partitionIdx)
        {
            continue;
        }
        if (comp(partitionVal, *(m_src + idx)))
        {
            *(src + (--arg_rightIdx)) = *(m_src + idx);
        }
        else
        {
            *(src + (arg_leftIdx++)) = *(m_src + idx);
        }
    }
    *(src + arg_leftIdx) = partitionVal;
    // std::cout << arg_leftIdx << "----" << arg_rightIdx - 1 << std::endl;
    // for (int idx = leftIdx; idx != rightIdx; ++idx)
    // {
    //     std::cout << "[" << idx << "]=" << *(src + idx) << '\t';
    // }
    // std::cout << std::endl; 
    quickSort_crudity(src, leftIdx, arg_leftIdx, leftIdx, comp);
    quickSort_crudity(src, arg_leftIdx + 1, rightIdx, arg_leftIdx + 1, comp);
}

void quickSort(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp)
{
    int* arg_src = src;
    size_t arg_leftIdx = leftIdx;
    size_t arg_rightIdx = rightIdx;

    //递归终止条件: 终止条件
    if (rightIdx - leftIdx <= 1)
    {
        return;
    }

    int partitionVal = *(src + leftIdx);
    size_t lIdx = leftIdx + 1;
    size_t rIdx = rightIdx - 1;
    size_t partitionIdx = leftIdx;

    while (lIdx < rIdx)
    {
        if (!comp(partitionVal, *(src + lIdx)))
        {
            ++lIdx;
            continue;
        }
        else
        {
            while (lIdx < rIdx)
            {
                if (!comp(partitionVal, *(src + rIdx)))
                {
                    int tmp = *(src + lIdx);
                    *(src + (lIdx++)) = *(src + rIdx);
                    *(src + (rIdx--)) = tmp;
                    break;
                }
                else
                {
                    --rIdx;
                }
            }
        }
    }

    if (lIdx == rIdx)
    {
        if (!comp(partitionVal, *(src + lIdx)))
        {
            //与partitionVal互换
            *(src + leftIdx) = *(src + lIdx);
            *(src + lIdx) = partitionVal;
            partitionIdx = lIdx;
        }
        else
        {
            //前一个与partition互换
            *(src + leftIdx) = *(src + lIdx - 1);
            *(src + lIdx - 1) = partitionVal;
            partitionIdx = lIdx - 1;
        }
    }
    else
    {
        *(src + leftIdx) = *(src + lIdx - 1);
        *(src + lIdx - 1) = partitionVal;
        partitionIdx = lIdx - 1;
    }

    quickSort(src, leftIdx, partitionIdx, comp);
    quickSort(src, partitionIdx + 1, rightIdx, comp);
}
