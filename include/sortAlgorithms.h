/***********************************************************************************************************************
* @file: sortAlgorithms.h
* @brife: 学习过程中, 各类排序算法的声明
* @date: 2026-10-18
* @update: 2026-10-19
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
//TODO: shell sort
void shellSort(int* src, size_t n, std::function<bool(int, int)> comp = std::less<int>());

#endif // !__SORTALGORITHMS_H__
