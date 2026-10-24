/***********************************************************************************************************************
* @file: sortAlgorithms.h
* @brife: 学习过程中, 各类排序算法的声明
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
* @brife: 两个指针所指向的值互换
******************************************************/
static void swap(int* aPtr, int* bPtr)
{
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
    return;
}

/******************************************************
* @brife: 选择排序
* @param src: 首地址
* @param n: 待排序序列长度
* @param comp: 关系运算
* @return: 
* @note: 
******************************************************/
void selectionSort(int* src, size_t n, std::function<bool(int, int)> comp = std::less<int>());

/******************************************************
* @brife: 插入排序
* @param src: 首地址
* @param n: 待排序序列长度
* @param gap: 每隔gap元素比较
* @param comp: 关系运算
* @return: 
* @note: 采用与当前元素比较,一次移动符合的连续内存
******************************************************/
void insertSort(int* src, size_t n, size_t gap = 1, std::function<bool(int, int)> comp = std::less<int>());

/******************************************************
* @brife: 插入排序: 应用于 mergeSort_recursive排序
* @param src: 首地址
* @param left: 待排序序列[左索引
* @param right: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right), 应该可以在 insertSort上修改, 但是懒着整了, 索引重新整
******************************************************/
void insertSort_(int* src, size_t left, size_t right, std::function<bool(int, int)> comp = std::less<int>());

/******************************************************
* @brife: 插入排序
* @param src: 首地址
* @param n: 待排序序列长度
* @param comp: 关系运算
* @return: 
* @note: 采用与当前元素比较,一次移动符合的连续内存
******************************************************/
void insertSort_mem(int* src, size_t n, std::function<bool(int, int)> comp = std::less<int>());

/******************************************************
* @brife: 希尔排序
* @param src: 首地址
* @param n: 待排序序列长度
* @param comp: 关系运算
* @return: 
* @note: 
******************************************************/
void shellSort(int* src, size_t n, std::function<bool(int, int)> comp = std::less<int>());

/******************************************************
* @brife: 归并排序: 自顶向下递归(recuisive)实现
* @param src: 首地址
* @param left: 待排序序列[左索引
* @param right: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right)
******************************************************/
void mergeSort_recursive(int* src, size_t left, size_t right, std::function<bool (int, int)> comp = std::less<int>());

/******************************************************
* @brife: 归并排序: 自底向上归并排序
* @param src: 首地址
* @param left: 待排序序列[左索引
* @param right: 待排序序列右索引)
* @param comp: 关系运算
* @return: 
* @note: [left, right)
******************************************************/
void mergeSortBU(int* src, size_t left, size_t right, std::function<bool (int, int)> comp = std::less<int>());

/******************************************************
* @brife: 快速排序, 第一次实现, 简单的
* @param src: 首地址
* @param leftIdx: 待排序序列[左索引
* @param rightIdx: 待排序序列右索引)
* @param partitionIdx: 基准/分隔元素的索引
* @param comp: 关系运算
* @return: 
* @note: [left, right)
******************************************************/
void quickSort_crudity(int* src, size_t leftIdx, size_t rightIdx, size_t partitionIdx,
                       std::function<bool (int, int)> comp = std::less<int>());
#endif // !__SORTALGORITHMS_H__
