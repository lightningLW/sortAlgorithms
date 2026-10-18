/**
* @file: sortAlgorithms.h
* @brife: 学习过程中, 各类排序算法的声明
* @date: 2026-10-18
* @update:
* @author: lightningLW
* @note: 
*/

#ifndef __SORTALGORITHMS_H__
#define __SORTALGORITHMS_H__

#include <iostream>
#include <functional>

/**
* @brife: 两个指针所指向的值互换
*/
static void swap(int* aPtr, int* bPtr)
{
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
    return;
}

/**
* @brife: 选择排序
* @param src: 首地址
* @param n: 待排序序列长度
* @return: 
* @note: 
*/
void selectionSort(int* src, size_t n, std::function<bool(int, int)> comp = std::less<int>());

/**
* @brife: 插入排序
* @param src: 首地址
* @param n: 待排序序列长度
* @return: 
* @note: 
*/
void insertSort(int* src, size_t n, std::function<bool(int, int)> comp = std::less<int>());

#endif // !__SORTALGORITHMS_H__
