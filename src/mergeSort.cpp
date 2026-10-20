/***********************************************************************************************************************
* @file: selectionSort.cpp
* @brife: 归并排序实现文件
* @date: 2026-10-20
* @update:
* @author: lightningLW
* @note: 归并排序, 分为: 排序和归并两个过程
***********************************************************************************************************************/

#include "sortAlgorithms.h"

/******************************************************
* @brife: 归并
* @param src: 首地址
* @param left: 待归并的数组的左index
* @param mid: 待归并数组的中间index
* @param right: 待归并数组的右边index
* @return: 
* @note: 左右数组的划分 [left, mid), [mid, right) 且 [left, mid), [mid, right)分别有序
******************************************************/
static void merge_(int* src, size_t left, size_t right, std::function<bool (int, int)> comp = std::less<int>())
{
    size_t mid = left + ((right - left) >> 1);
    int tempArr[right];
    memcpy(tempArr, src, sizeof(int) * (right));
    size_t rgArr_curIdx = mid;
    size_t tmpleft = left;
    for (size_t lfArr_idx = left; lfArr_idx != mid; ++lfArr_idx)
    {
        int lfArr_value = *(tempArr + lfArr_idx);
        for (size_t rgArr_idx = rgArr_curIdx; rgArr_idx != right; ++rgArr_idx)
        {
            int rgArr_value = *(tempArr + rgArr_idx);
            if (comp(lfArr_value, rgArr_value))
            {
                *(src + (tmpleft++)) = lfArr_value;
                if (lfArr_idx == mid - 1)
                {
                    //证明左边的数组已经全部排序完了
                    memcpy(src + tmpleft, tempArr + rgArr_idx, sizeof(int) * (right - rgArr_idx));
                }
                break;
            }
            else
            {
                *(src + (tmpleft++)) = rgArr_value;
                ++rgArr_curIdx;
            }
            if (rgArr_curIdx == right)
            {
                //证明右数组全部排完了 
                memcpy(src + tmpleft, tempArr + lfArr_idx, sizeof(int) * (mid - lfArr_idx));
                break;
            }
        }
    }
}

void mergeSort(int *src, size_t left, size_t right)
{
    size_t len = right - left;
    size_t mid = (right - left) >> 1;
    if (left + 2 <= right)
    {
        // mergeSort(src, left, mid);
        // mergeSort(src, mid, right);
        // merge_(src, left, right);
    }
    merge_(src, left, right);
}
