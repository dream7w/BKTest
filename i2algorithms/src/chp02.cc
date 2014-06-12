/*==========================================
  @Author      : zabambo
  @File        : chp02.cc
  @Encoding    : utf-8
  @Create      : 2014-06-11 23:07:34
  @Modified    : 2014-06-12 02:37:44
  @Description : 
==========================================*/

#include "chp02.h"


void TestChp02()
{
  {
    printf("InsertionSort\n:");
    int data[] = {1,3,6,4,2,5,8,4};
    int length = sizeof(data) / sizeof(int);
    NormalPrint("data:",data, length, "");
    InsertionSort(data, length);
    NormalPrint("data:",data, length, "");
  }
  {
    printf("SelectionSort\n:");
    int data[] = {1,3,6,4,2,5,8,4};
    int length = sizeof(data) / sizeof(int);
    NormalPrint("data:",data, length, "");
    SelectionSort(data, length);
    NormalPrint("data:",data, length, "");
  }

  {
    printf("BinaryAdd\n:");
    #define LEN 5
    int a[] = {1, 0,1,1,0};
    int b[] = {1, 1,1,0,0};
    int c[LEN + 1] = {0};
    NormalPrint("a:",a, LEN , "");
    NormalPrint("b:",b, LEN , "");
    BinaryAdd(a, b, c, LEN);
    NormalPrint("c:",c, LEN + 1, "");

  }


}


template<class E>
void InsertionSort(E data[], int length, bool (*compare)(const E &e1, const E &e2))
{
  if (length < 2){
    return;
  }
  int j = 0;
  for (int i = 1; i < length; ++i){
    E val = data[i];
    j = i - 1;
    while (j >= 0 && compare(val, data[j])){
      data[j + 1] = data[j];
      j--;
    }
    data[j+1] = val;
  }
}

template<class E>
void SelectionSort(E data[], int length, bool (*compare)(const E &e1, const E &e2) = NormalCompare)
{
  if (length < 2){return;}
  for (int i = 0; i < length - 1; ++i){
    int k = i;
    for (int j = i + 1; j < length; ++j){
      k = (compare(data[k], data[j]) ? k : j);
    }
    if (k != i){
      E val = data[i];
      data[i] = data[k];
      data[k] = val;
    }
  }
}




void BinaryAdd(int a[], int b[], int c[], int length)
{
  if (length < 1){
    return;
  }
  int flag = 0;
  for (int i = length - 1; i >= 0; --i){
    c[i + 1] = a[i] + b[i] + flag;
    flag = c[i + 1] > 1 ? 1 : 0;
    c[i + 1] = c[i + 1] % 2;
  }
  c[0] = flag;
}
