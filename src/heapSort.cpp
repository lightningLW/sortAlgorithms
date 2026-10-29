/***********************************************************************************************************************
* @file: heapSort.cpp
* @brife: 堆排序实现文件
* @date: 2026-10-29
* @update: 
* @author: lightningLW
* @note: 
***********************************************************************************************************************/

#include "sortAlgorithms.h"

/*
 * @brife: 二叉堆的上浮操作
 * @param src: 数组的首地址
 * @param len: 已经有序的二叉堆
 * @param val: 上浮的值
 * @param comp: 堆有序化的判断标准
 * @return: 上浮后的数组首地址
 * @note: len定义为已是堆有序的元素的个数. 有序元素从索引1开始, 而不是0.
*/
int* swim(int* src, size_t len, int val, std::function<bool (int, int)> comp = std::less<int>())
{

    //插入的元素值val放到 src[len+1]处
    size_t curIdx = len + 1;
    size_t parIdx = curIdx >> 1;
    // std::cout << "curIdx = " << curIdx << " parIdx = " << parIdx << std::endl;
    while (parIdx >= 1)
    {
        if (comp(*(src + curIdx), *(src + parIdx)))
        {
            swap(src + curIdx, src + parIdx);
            curIdx = parIdx;
            parIdx = curIdx >> 1;
        }
        else
        {
            break;
        }
    }
    // std::cout << __FUNCTION__ << std::endl;
    // for (int i = 1; i <= len + 1; ++i)
    // {
    //     std::cout << src[i] << " ";
    // }
    // std::cout << std::endl;
    return src;
}

/*
 * @brife: 二叉堆的下沉操作
 * @param src: 数组的首地址
 * @param len: 已经有序的二叉堆
 * @param idx: 删除/被替换元素的索引
 * @param comp: 堆有序化的判断标准
 * @return: 下沉后的数组首地址
 * @note: len定义为已是堆有序的元素的个数. 有序元素从索引1开始, 而不是0.
*/
int* sink(int* src, size_t len, size_t idx, std::function<bool (int, int)> comp = std::less<int>())
{
    if (len <= 1)
    {
        return src;
    }
    swap(src + len, src + idx);
    size_t curIdx = idx;
    size_t sonIdx1 = idx << 1;
    size_t sonIdx2 = sonIdx1 + 1;
    while (curIdx <= len - 1 && sonIdx1 <= len - 1)
    {
        if (sonIdx2 <= len -1)
        {
            if (comp(*(src + sonIdx1), *(src + sonIdx2)))
            {
                if (comp(*(src + sonIdx1), *(src + curIdx)))
                {
                    swap(src + sonIdx1, src + curIdx);
                    curIdx = sonIdx1;
                    sonIdx1 = curIdx << 1;
                    sonIdx2 = sonIdx1 + 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (comp(*(src + sonIdx2), *(src + curIdx)))
                {
                    swap(src + sonIdx2, src + curIdx);
                    curIdx = sonIdx2;
                    sonIdx1 = curIdx << 1;
                    sonIdx2 = sonIdx1 + 1;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            // if (comp(*(src + sonIdx1), *(src + sonIdx2)))
            // {
            if (comp(*(src + sonIdx1), *(src + curIdx)))
            {
                swap(src + sonIdx1, src + curIdx);
                curIdx = sonIdx1;
                sonIdx1 = curIdx << 1;
                sonIdx2 = sonIdx1 + 1;
            }
            else
            {
                break;
            }
            // }
        }
    }
    return src;
}

void heapSort(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp)
{
    int tmpArr[rightIdx - leftIdx + 1];
    memcpy(tmpArr + 1, src + leftIdx, sizeof(int) * (rightIdx - leftIdx));

    // @ 逐一插入元素, 堆有序化的过程
    for (int i = 1; i != rightIdx - leftIdx + 1; ++i)
    {
        swim(tmpArr, i - 1, *(tmpArr + i), comp);
        // for (int j = 1; j != i + 1; ++j)
        // {
        //     std::cout << tmpArr[j] << " ";
        // }
        // std::cout << std::endl;
    }
    // !@ 逐一插入元素, 堆有序化的过程

    // for (int i = 1; i != rightIdx - leftIdx + 1; ++i)
    // {
    //     std::cout << *(tmpArr + i) << "\t";
    // }
    // std::cout << std::endl;

    // @ 逐一删除/取堆顶元素, 即对数组进行排序
    for (int i = 1; i != rightIdx - leftIdx + 1; ++i)
    {
        *(src + i - 1 + leftIdx) = tmpArr[1];
        // std::cout << tmpArr[1] << std::endl;
        // std::cout << "len = " << rightIdx -leftIdx - i + 1 << std::endl;
        sink(tmpArr, rightIdx - leftIdx - i + 1, 1, comp);
        // for (int j = 1; j != rightIdx - leftIdx + 1; ++j)
        // {
        //     std::cout << *(tmpArr + j) << "\t";
        // }
        // std::cout << std::endl;
        // *(src + i - 1) = tmpArr[1];
    }
    // !@ 逐一删除/取堆顶元素, 即对数组进行排序

}
