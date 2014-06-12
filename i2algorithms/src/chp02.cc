/*==========================================
  @Author      : zabambo
  @File        : chp02.cc
  @Encoding    : utf-8
  @Create      : 2014-06-11 23:07:34
  @Modified    : 2014-06-12 00:37:57
  @Description : 
==========================================*/

#include <stdio.h>
#include "chp02.h"


void TestChp02()
{
  int data[] = {1,3,6,4,2,5,8,4};
  int length = sizeof(data) / sizeof(int);
  printf("Origin Data:");
  for (int i = 0; i < length; ++i){
    printf("%d,", data[i]);
  }
  printf("\n");

  InsertSort(data, length);

  printf("Sort Data:");
  for (int i = 0; i < length; ++i){
    printf("%d,", data[i]);
  }
  printf("\n");
}



void InsertSort(int data[], int length)
{
  if (length < 2){
    return;
  }
  int j = 0;
  for (int i = 1; i < length; ++i){
    int val = data[i];
    j = i - 1;
    while (j && val > data[j]){
      data[j + 1] = data[j];
      j--;
    }
    data[j++] = val;
  }
}
