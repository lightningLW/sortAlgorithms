/***********************************************************************************************************************
* @file: selectionSort.cpp
* @brife: 归并排序实现文件
* @date: 2026-10-20
* @update: 2026-10-21
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

/******************************************************
* @brife: 归并, 应用于 自底向上的归并排序
* @param src: 首地址
* @param left: 待归并的数组的左index
* @param right: 待归并数组的右边index
* @param mid: 待归并数组的右边index
* @return: 
* @note: 左右数组的划分 [left, mid), [mid, right) 且 [left, mid), [mid, right)分别有序
******************************************************/
static void merge_BU(int* src, size_t left, size_t mid, size_t right, std::function<bool (int, int)> comp = std::less<int>())
{
    size_t len = right - left;
    size_t rightIdx_beg = mid - left;
    size_t _left = left;
    bool done = false;
    int arr[len];
    memcpy(arr, src + left, len * sizeof(int));

    for (int i = 0; i != mid - left; ++i)
    {
        int leftVal = *(arr + i);
        for (int j = rightIdx_beg; j != len; ++j)
        {
            int rightVal = *(arr + j);
            if (comp(leftVal, rightVal))
            {
                *(src + (_left++)) = leftVal;
                if (i == mid - left - 1)
                {
                    //证明是左边数组的最后一个元素, 将右边数组剩余元素直接复制到原始数组
                    memcpy(src + _left, arr + j, (len - j) * sizeof(int));

                }
                break;
            }
            else
            {
                *(src + (_left++)) = rightVal;
                ++rightIdx_beg;
                if (j == len - 1)
                {
                    //证明右边的数组的最后一个元素, 将左边数组剩余元素直接复制到原始数组
                    memcpy(src + _left, arr + i, (mid - left - i) * sizeof(int));
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
    if (right - left <= 15)
    {
        insertSort_(src, left, right, comp);
        return;
    }
    mergeSort_recursive(src, left, mid, comp);
    mergeSort_recursive(src, mid, right, comp);
    merge_(src, left, right, comp);
}

void mergeSortBU(int* src, size_t left, size_t right, std::function<bool (int, int)> comp)
{
    size_t len = right - left;
    if (len <= 1)
    {
        return;
    }
    for (size_t i = 1; i < len; i *= 2)
    {
        size_t j = 0;
        while(true)
        {
            size_t rightIdx = j + 2 * i;
            size_t mid = j + i;
            if (mid > (len - 1))
            {
                // std::cout << "mid over: " << mid << std::endl;
                break;
            }
            if (rightIdx > len)
            {
                // std::cout << "right over:" << "[" << j << ", " << mid << ", " << rightIdx << ")" << std::endl;
                rightIdx = len;
                merge_BU(src + left, j, mid, rightIdx, comp);
                // for(int idx = 0; idx != len; ++idx)
                // {
                //     std::cout << *(src + left + idx) << "\t";
                // }
                // std::cout << std::endl;
                break;
            }
            else
            {
                // std::cout << "[" << j << ", " << mid << ", " << rightIdx << ")" << std::endl;
                merge_BU(src + left, j, mid, rightIdx, comp);
                // for(int idx = 0; idx != len; ++idx)
                // {
                //     std::cout << *(src + left + idx) << "\t";
                // }
                // std::cout << std::endl;
            }
            j = rightIdx;
        }
    }
}
