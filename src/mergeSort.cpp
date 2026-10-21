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
* @param right: 待归并数组的右边index
* @return: 
* @note: 左右数组的划分 [left, mid), [mid, right) 且 [left, mid), [mid, right)分别有序
******************************************************/
static void merge_(int* src, size_t left, size_t right, std::function<bool (int, int)> comp = std::less<int>())
{
    size_t len = right - left;
    size_t mid = len >> 1;
    size_t rightIdx_beg = mid;
    bool done = false;
    int arr[len];
    memcpy(arr, src + left, len * sizeof(int));

    for (int i = 0; i != mid; ++i)
    {
        int leftVal = *(arr + i);
        for (int j = rightIdx_beg; j != len; ++j)
        {
            int rightVal = *(arr + j);
            if (comp(leftVal, rightVal))
            {
                *(src + (left++)) = leftVal;
                if (i == mid - 1)
                {
                    //证明是左边数组的最后一个元素, 将右边数组剩余元素直接复制到原始数组
                    memcpy(src + left, arr + j, (len - j) * sizeof(int));

                }
                break;
            }
            else
            {
                *(src + (left++)) = rightVal;
                ++rightIdx_beg;
                if (j == len - 1)
                {
                    //证明右边的数组的最后一个元素, 将左边数组剩余元素直接复制到原始数组
                    memcpy(src + left, arr + i, (mid - i) * sizeof(int));
                    done = true;
                }
            }
        }
        if (rightIdx_beg == len)
        {
            break;
        }
    }
}


void mergeSort_recursive(int *src, size_t left, size_t right, std::function<bool (int, int)> comp)
{
    size_t len = right - left;
    size_t mid = (right + left) >> 1;
    if (right - left <= 1)
    {
        return;
    }
    mergeSort_recursive(src, left, mid, comp);
    mergeSort_recursive(src, mid, right, comp);
    merge_(src, left, right, comp);
}
