/*==========================================
  @Author      : zabambo
  @File        : chp02.cc
  @Encoding    : utf-8
  @Create      : 2014-06-11 23:07:34
  @Modified    : 2014-07-04 11:53:03
  @Description : 
==========================================*/

#include "chp02.h"


void TestChp02()
{
  {
    printf("InsertionSort\n:");
    int data[] = {1,3,6,4,2,5,8,4,2,5,6,7,8,2,5,9};
    int length = sizeof(data) / sizeof(int);
    NormalPrint("data:",data, length, "");
    InsertionSort(data, length);
    NormalPrint("data:",data, length, "");
  }
  {
    printf("SelectionSort\n:");
    int data[] = {1,3,6,4,2,5,8,4,2,5,6,7,8,2,5,9};
    int length = sizeof(data) / sizeof(int);
    NormalPrint("data:",data, length, "");
    SelectionSort(data, length);
    NormalPrint("data:",data, length, "");
  }
  {
    printf("MerageSort\n:");
    int data[] = {1,3,6,4,2,5,8,4,2,5,6,7,8,2,5,9};
    int length = sizeof(data) / sizeof(int);
    NormalPrint("data:",data, length, "");
    MergeSort<int>(data, 0, length - 1);
    NormalPrint("data:",data, length, "");
  }
  {
    printf("MergeInsertionSort\n:");
    int data[] = {1,3,6,4,2,5,8,4,2,5,6,7,8,2,5,9};
    int length = sizeof(data) / sizeof(int);
    NormalPrint("data:",data, length, "");
    MergeInsertionSort<int>(data, 0, length - 1, 3);
    NormalPrint("data:",data, length, "");
  }
  {
    printf("BubbleSort\n:");
    int data[] = {1,3,6,4,2,5,8,4,2,5,6,7,8,2,5,9};
    int length = sizeof(data) / sizeof(int);
    NormalPrint("data:",data, length, "");
    BubbleSort<int>(data, length);
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
void InsertionSort(E data[], int length, int (*compare)(const E &e1, const E &e2))
{
  if (length < 2){
    return;
  }
  int j = 0;
  for (int i = 1; i < length; ++i){
    E val = data[i];
    j = i - 1;
    while (j >= 0 && compare(val, data[j]) < 0){
      data[j + 1] = data[j];
      j--;
    }
    data[j+1] = val;
  }
}

template<class E>
void SelectionSort(E data[], int length, int (*compare)(const E &e1, const E &e2))
{
  if (length < 2){return;}
  for (int i = 0; i < length - 1; ++i){
    int k = i;
    for (int j = i + 1; j < length; ++j){
      k = (compare(data[k], data[j]) < 0 ? k : j);
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




template<class E>
void MergeSort(E data[], int start, int end, int (*compare)(const E &e1, const E &e2) = NormalCompare)
{
  static E *tmp = new E[end + 1];
  if (start >= end){return;}
  int mid = (start + end) / 2;
  MergeSort(data, start, mid);
  MergeSort(data, mid + 1, end);
  Merge(data, tmp, start, mid, end, compare);
}

template<class E>
void Merge(E data[], E tmp[], int start, int mid, int end, int (*compare)(const E &e1, const E &e2) = NormalCompare)
{
  if (start >= end){return;}
  
  for (int i = start; i <= end; ++i){
    tmp[i] = data[i];
  }

  int i = start;
  int j = start;
  int k = mid + 1;
  while (j <= mid && k <= end){
    if (compare(tmp[j], tmp[k]) < 0){
      data[i++] = tmp[j++];
      continue;
    }else{
      data[i++] = tmp[k++];
    }
  }
  while(j <= mid){
      data[i++] = tmp[j++];
  }
  while(k <= end){
      data[i++] = tmp[k++];
  }
}


template<class E>
void MergeInsertionSort(E data[], int start, int end, int insert_sort_size, int (*compare)(const E &e1, const E &e2) = NormalCompare)
{
  static E *tmp = new E[end + 1];
  if (start >= end){return;}
  if (end - start <= insert_sort_size){
    InsertionSort(&data[start], end - start + 1);
    return;
  }
  int mid = (start + end) / 2;
  MergeSort(data, start, mid);
  MergeSort(data, mid + 1, end);
  Merge(data, tmp, start, mid, end, compare);
}

template<class E>
void BubbleSort(E data[], int length, int (*compare)(const E &e1, const E &e2) = NormalCompare)
{
  if (length < 2){return;}
  E tmp;
  for (int i = 0; i < length; ++i){
    for (int j = length - 1; j > i; --j){
      if (compare(data[j], data[j-1]) < 0){
        tmp = data[j];
        data[j] = data[j - 1];
        data[j - 1] = tmp;
      }
    }
  }
}


template<class E>
int BinarySearch(const E data[], int start, int end, const E &e, int (*equal)(const E &e1, const E &e2) )
{
#if 0
  int mid = (end - start)/ 2;
  int eql = equal(data[mid], e);
  if (start > end){ return -1; }
  if (0 == eql){
    return mid;
  }else if (eql < 0){
    return BinarySearch(data, start, mid);
  }else{
    return BinarySearch(data, mid + 1, end);
  }
#else
  while (start <= end){
    int mid = (end - start)/ 2;
    int eql = equal(data[mid], e);
    if (0 == eql){
      return mid;
    }else if (eql < 0){
      end = mid;
    }else{
      start = mid + 1;
    }
  }
  return -1;
#endif
}

















