/***********************************************************************************************************************
* @file: sortAlgorithms.h
* @brief: 学习过程中, 各类排序算法的声明
* @date: 2026-10-18
* @update: 2026-10-24
* @author: lightningLW
* @note: 
***********************************************************************************************************************/

#ifndef __SORTALGORITHMS_H__
#define __SORTALGORITHMS_H__

#include <iostream>
#include <functional>

/******************************************************
* @brief: 两个指针所指向的值互换
******************************************************/
static void swap(int* aPtr, int* bPtr)
{
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
    return;
}

/******************************************************
* @brief: 选择排序
* @param src: 首地址
* @param n: 待排序序列长度
* @param comp: 关系运算
* @return: 
* @note: 
******************************************************/
void selectionSort(int* src, size_t n, std::function<bool(int, int)> comp = std::less<int>());

/******************************************************
* @brief: 插入排序
* @param src: 首地址
* @param n: 待排序序列长度
* @param gap: 每隔gap元素比较
* @param comp: 关系运算
* @return: 
* @note: 采用与当前元素比较,一次移动符合的连续内存
******************************************************/
void insertSort(int* src, size_t n, size_t gap = 1, std::function<bool(int, int)> comp = std::less<int>());

/******************************************************
* @brief: 插入排序: 应用于 mergeSort_recursive排序
* @param src: 首地址
* @param left: 待排序序列[左索引
* @param right: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right), 应该可以在 insertSort上修改, 但是懒着整了, 索引重新整
******************************************************/
void insertSort_(int* src, size_t left, size_t right, std::function<bool(int, int)> comp = std::less<int>());

/******************************************************
* @brief: 插入排序
* @param src: 首地址
* @param n: 待排序序列长度
* @param comp: 关系运算
* @return: 
* @note: 采用与当前元素比较,一次移动符合的连续内存
******************************************************/
void insertSort_mem(int* src, size_t n, std::function<bool(int, int)> comp = std::less<int>());

/******************************************************
* @brief: 希尔排序
* @param src: 首地址
* @param n: 待排序序列长度
* @param comp: 关系运算
* @return: 
* @note: 
******************************************************/
void shellSort(int* src, size_t n, std::function<bool(int, int)> comp = std::less<int>());

/******************************************************
* @brief: 归并排序: 自顶向下递归(recuisive)实现
* @param src: 首地址
* @param left: 待排序序列[左索引
* @param right: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right)
******************************************************/
void mergeSort_recursive(int* src, size_t left, size_t right, std::function<bool (int, int)> comp = std::less<int>());

/******************************************************
* @brief: 归并排序: 自底向上归并排序
* @param src: 首地址
* @param left: 待排序序列[左索引
* @param right: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right)
******************************************************/
void mergeSortBU(int* src, size_t left, size_t right, std::function<bool (int, int)> comp = std::less<int>());

/******************************************************
* @brief: 快速排序 Lomuto分区法(单向扫描)
* @param src: 首地址
* @param leftIdx: 待排序序列[左索引
* @param rightIdx: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right) 左闭右开区间
* @note: 选取区间末尾元素作为基准
* @note: 假设元素升序排序, 用[慢指针]维护小于等于基准的区间右边界;
* @note: [快指针]遍历整个区间, 遇到小于等于的元素就换到慢指针区间内
******************************************************/
void quickSort_lomuto(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp = std::less<int>());

/******************************************************
* @brief: 快速排序 Hoare分区法(双向扫描)
* @param src: 首地址
* @param leftIdx: 待排序序列[左索引
* @param rightIdx: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right) 左闭右开区间
* @note: 选取区间首元素(或任意位置)作为基准
* @note: 假设元素升序排序, 用[左指针]从左向右➡️, 寻找第一个大于基准的元素;
* @note: [右指针]从右向左⬅️, 寻找第一个大于基准的元素
* @note: 交换两个元素, 直到左右指针相遇, 相遇处即为左右区间分界
******************************************************/
void quickSort_hoare(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp = std::less<int>());

/******************************************************
* @brief: 3路快速排序, 用于处理大量重复元素
* @param src: 首地址
* @param leftIdx: 待排序序列[左索引
* @param rightIdx: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right) 左闭右开区间
* @note: 选取区间首元素(或任意位置)作为基准
* @note: 假设元素升序排序, 将数组划为为三部分: 小于基准, 等于基准, 大于基准, 等于基准的不需要参与后续递归
******************************************************/
void quickSort_3way(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp = std::less<int>());

/******************************************************
* @brief: 堆排序
* @param src: 首地址
* @param leftIdx: 待排序序列[左索引
* @param rightIdx: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right) 左闭右开区间
******************************************************/
void heapSort(int* src, size_t leftIdx, size_t rightIdx, std::function<bool (int, int)> comp = std::less<int>());
#endif // !__SORTALGORITHMS_H__
