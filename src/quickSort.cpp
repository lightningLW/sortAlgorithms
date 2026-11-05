/***********************************************************************************************************************
* @file: quickSort.cpp
* @brief: 快速排序实现文件
* @date: 2026-10-24
* @update: 2026-10-26
* @author: lightningLW
* @note: 
***********************************************************************************************************************/

#include "sortAlgorithms.h"

static void mid2head(int* src, size_t leftIdx, size_t rightIdx)
{
    size_t mid = leftIdx + ((rightIdx - leftIdx) >> 1);
    int arr[3] = {*(src + leftIdx), *(src + mid), *(src + rightIdx - 1)};
    insertSort_(arr, 0, 3);
    *(src + leftIdx) = arr[1];
    *(src + mid) = arr[0];
    *(src + rightIdx - 1) = arr[2];
}

/******************************************************
* @brief: Lomuto分区法(单向扫描)
* @param src: 首地址
* @param leftIdx: 待排序序列[左索引
* @param rightIdx: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right) 左闭右开区间
* @note: 选取区间末尾元素作为基准, 将末尾元素放到数组的正确的位置上
* @note: 假设元素升序排序, 用[慢指针]维护小于等于基准的区间右边界;
* @note: [快指针]遍历整个区间, 遇到小于等于的元素就换到慢指针区间内
******************************************************/
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

/******************************************************
* @brief: Hoare分区法(双向扫描)
* @param src: 首地址
* @param leftIdx: 待排序序列[左索引
* @param rightIdx: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right) 左闭右开区间
* @note: 选取区间首元素作为基准, 并放到数组的正确的位置上
* @note: 假设元素升序排序, 用[左指针]从左向右➡️, 寻找第一个大于基准的元素;
* @note: [右指针]从右向左⬅️, 寻找第一个大于基准的元素
* @note: 交换两个元素, 直到左右指针相遇, 相遇处即为左右区间分界
******************************************************/
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
    //优化: 当数组的长度小于8~15之间, 使用插入排序
    if (rightIdx - leftIdx <= 8)
    {
        insertSort_(src, leftIdx, rightIdx, comp);
        return;
    }

    //优化: 取数组的首/中/尾 的中位数放到 首元素上, 便于hoare函数取pivot
    mid2head(src, leftIdx, rightIdx);

    size_t pivotIdx = hoare(src, leftIdx, rightIdx, comp);

    // for (int i = leftIdx; i != rightIdx; ++i)
    // {
    //     std::cout << *(src + i) << "\t";
    // }
    // std::cout << std::endl;

    quickSort_hoare(src, leftIdx, pivotIdx, comp);
    quickSort_hoare(src, pivotIdx + 1, rightIdx, comp);
}

void quickSort_3way(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp)
{
    //优化: 当数组的长度小于8~15之间, 使用插入排序
    if (rightIdx <= leftIdx)
    {
        return;
    }
    if (rightIdx - leftIdx <= 8)
    {
        insertSort_(src, leftIdx, rightIdx, comp);
        return;
    }

    //优化: 取数组的首/中/尾 的中位数放到 首元素上, 便于hoare函数取pivot
    mid2head(src, leftIdx, rightIdx);

    int pivot = *(src + leftIdx);
    size_t i = leftIdx; // 用于遍历数组的快指针
    size_t pivot_leftIdx = leftIdx;
    size_t pivot_rightIdx = rightIdx - 1;

    for ( ; i <= pivot_rightIdx; )
    {
        if (comp(*(src + i), pivot))
        {
            swap((src + i), (src + pivot_leftIdx));
            ++i;
            ++pivot_leftIdx;
        }
        else if (comp(pivot, *(src + i)))
        {
            swap(src + i, src + pivot_rightIdx);
            --pivot_rightIdx;
            // ++i;
        }
        else
        {
            ++i;
        }
    }

    quickSort_3way(src, leftIdx, pivot_leftIdx, comp);
    quickSort_3way(src, pivot_rightIdx+1, rightIdx, comp);

}
