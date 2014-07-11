/*==========================================
  @Author      : zabambo
  @File        : datastrualgoanal/src/chp09.h
  @Encoding    : utf-8
  @Create      : 2014-07-10 14:45:57
  @Modified    : 2014-07-11 14:00:27
  @Description : 
==========================================*/

#ifndef SRC_CHP09_H_
#define SRC_CHP09_H_

#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <deque>


struct GraphInterface
{
  virtual bool TopSort(std::vector<int> &out) = 0;
};

struct GraphArray : public GraphInterface
{
  int v;  //顶点数
  int e;  //边数
  int **data;

  GraphArray();
  virtual ~GraphArray();
  GraphArray(int e);
  virtual bool TopSort(std::vector<int> &out);
};


struct GraphList : public GraphInterface
{
  int v;  //顶点数
  int e;  //边数
  std::list<int> *data;

  GraphList();
  virtual ~GraphList();
  GraphList(int e);
  virtual bool TopSort(std::vector<int> &out);
};






void TestCHP09();

#endif//SRC_CHP09_H_
