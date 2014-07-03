/*==========================================
  @Author      : zabambo
  @File        : chp02.h
  @Encoding    : utf-8
  @Create      : 2014-06-11 23:07:22
  @Modified    : 2014-07-03 20:36:16
  @Description : 
==========================================*/

#ifndef SRC_CHP02_H_
#define SRC_CHP02_H_

#include "comm_def.h"

/*
 *  分治法：将原问题分为n个与问题相似的子问题进行处理，多用递归法
 *
 *
 *
 */

/*
 *  brief   插入排序,n(2),
 *          增量方法(incremental):插入到已有的排序当中
 *  input   data[], length of data
 *  output  data[]
 *  return  void
 */
template<class E>
void InsertionSort(E data[], int length, int (*compare)(const E &e1, const E &e2) = NormalCompare);

/*
 *  brief   选择排序，从剩余的对象中选择最小人追加到列队末尾
 *  input   data[], length of data
 *  output  data[]
 *  return  void
 */
template<class E>
void SelectionSort(E data[], int length, int (*compare)(const E &e1, const E &e2) = NormalCompare);




/*
 *  brief   二进制加法
 *  input   a与b具体相同的长度length，c的长度比a多1, 
 *  output  c
 */
void BinaryAdd(int a[], int b[], int c[], int length);


/*
 *  brief   合并排序(merge sort)
 *          分治法(divide-and-conquer(分而治之))
 *
 *
 *
 */
template<class E>
void MergeSort(E data[], int start, int end, int (*compare)(const E &e1, const E &e2) = NormalCompare);
template<class E>
void Merge(E data[], E tmp[], int start, int mid, int end, int (*compare)(const E &e1, const E &e2) = NormalCompare);

/*
 *    brief   二分查找法
 *
 *
 */
template<class E>
int BinarySearch(const E data[], int start, int end, const E &e, int (*equal)(const E &e1, const E &e2) = NormalCompare);


void TestChp02();


#endif//SRC_CHP02_H_
