/*==========================================
  @Author      : zabambo
  @File        : datastrualgoanal/src/chp09.h
  @Encoding    : utf-8
  @Create      : 2014-07-10 14:45:57
  @Modified    : 2014-07-11 14:43:53
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
  //有向图的拓扑排序
  virtual bool TopSort(std::vector<int> &out) = 0;
  //广度优先算法
  virtual bool BreadthFirstSearch(std::vector<int> &out) = 0;
};

struct GraphArray : public GraphInterface
{
  int v;  //顶点数
  int e;  //边数
  int **data; //权重

  GraphArray();
  virtual ~GraphArray();
  GraphArray(int e);
  virtual bool TopSort(std::vector<int> &out);
  virtual bool BreadthFirstSearch(std::vector<int> &out);
};


struct GraphList : public GraphInterface
{
  struct E
  {
    int k;  //ID
    int w;  //权重
  };
  int v;  //顶点数
  int e;  //边数
  std::list<E> *data;

  GraphList();
  virtual ~GraphList();
  GraphList(int e);
  virtual bool TopSort(std::vector<int> &out);
  virtual bool BreadthFirstSearch(std::vector<int> &out);
};






void TestCHP09();

#endif//SRC_CHP09_H_
