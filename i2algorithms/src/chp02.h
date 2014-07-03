/*==========================================
  @Author      : zabambo
  @File        : chp02.h
  @Encoding    : utf-8
  @Create      : 2014-06-11 23:07:22
  @Modified    : 2014-07-03 16:22:54
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
 *  brief   插入排序,n(2),增量方法
 *  input   data[], length of data
 *  output  data[]
 *  return  void
 */
template<class E>
void InsertionSort(E data[], int length, bool (*compare)(const E &e1, const E &e2) = NormalCompare);

/*
 *  brief   选择排序
 *  input   data[], length of data
 *  output  data[]
 *  return  void
 */
template<class E>
void SelectionSort(E data[], int length, bool (*compare)(const E &e1, const E &e2) = NormalCompare);




/*
 *  brief   二进制加法
 *  input   a与b具体相同的长度length，c的长度比a多1, 
 *  output  c
 */
void BinaryAdd(int a[], int b[], int c[], int length);


void TestChp02();


#endif//SRC_CHP02_H_
