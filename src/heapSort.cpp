/***********************************************************************************************************************
* @file: heapSort.cpp
* @brief: 堆排序实现文件
* @date: 2026-10-29
* @update: 
* @author: lightningLW
* @note: 
***********************************************************************************************************************/

#include "sortAlgorithms.h"

/*
 * @brief: 二叉堆的上浮操作
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
 * @brief: 二叉堆的下沉操作
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

/*
* @brief: 对downIdx索引的父节点进行下沉操作
* @param leftIdx: 数组的左索引
* @param rightIdx: 数组的右索引
* @param downIdx: 所需要下沉的父节点的索引
* @return:
* @note: 因为堆排序是原地操作, 那么大根堆逐一将堆顶元素交换到堆尾, 就是升序排序.
*/
void siftDown(int* src, size_t leftIdx, size_t rightIdx, size_t downIdx, std::function<bool (int, int)> comp = std::less<int>())
{
    size_t curIdx = downIdx;
    while (true)
    {
        size_t lelfSonIdx = ((curIdx - leftIdx) << 1) + 1 + leftIdx;
        size_t rightSonIdx = lelfSonIdx + 1;
        size_t gargetIdx = curIdx;
        // std::cout << std::endl;
        // std::cout << curIdx << " " << lelfSonIdx << " " << rightSonIdx << std::endl;
        if (lelfSonIdx < rightIdx && comp(*(src + gargetIdx), *(src + lelfSonIdx)))
        {
            gargetIdx = lelfSonIdx;
        }
        if (rightSonIdx < rightIdx && comp(*(src + gargetIdx), *(src + rightSonIdx)))
        {
            gargetIdx = rightSonIdx;
        }
        //如果最大/最小元素的索引还是当前父节点, 那么证明已经堆有序了
        if (gargetIdx == curIdx)
        {
            break;
        }
        swap(src + curIdx, src + gargetIdx);
        curIdx = gargetIdx;
    }
}

void heapSort(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp)
{
    size_t len = rightIdx - leftIdx;
    if (len <= 1)
    {
        return;
    }
    //最后一个非叶子节点 len / 2 - 1;
    for (size_t curIdx = leftIdx + (len / 2 - 1); curIdx != leftIdx - 1; --curIdx)
    {
        siftDown(src, leftIdx, rightIdx, curIdx, comp);
    }
    // for (int i = leftIdx; i != rightIdx; ++i)
    // {
    //     std::cout << src[i] << "\t";
    // }
    // std::cout << std::endl;

    for (size_t i = 0; i != len; ++i)
    {
        //将堆顶元素交换到堆尾, 即堆尾元素已经排序了一个元素.
        swap(src + leftIdx, src + (rightIdx - i - 1));
        //堆的长度减1, 每次排序一个元素.
        siftDown(src, leftIdx, rightIdx - i - 1, leftIdx, comp);
    }
}
