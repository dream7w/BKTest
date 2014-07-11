/*==========================================
  @Author      : zabambo
  @File        : datastrualgoanal/src/chp09.cc
  @Encoding    : utf-8
  @Create      : 2014-07-10 14:45:48
  @Modified    : 2014-07-11 14:02:46
  @Description : 
==========================================*/

#include "chp09.h"

void TestCHP09()
{
}

GraphArray::GraphArray()
  :v(0), e(0), data(NULL)
{
}

GraphArray::~GraphArray()
{

}


GraphArray::GraphArray(int v)
  :v(v), e(0), data(NULL)
{
  data = (int**)malloc(sizeof(int*) * v);
  for (int i = 0; i < v; ++i){
    data[i] = new int[v];
  }
}

bool GraphArray::TopSort(std::vector<int> &out)
{
  std::vector<int> vec_indegree;
  vec_indegree.resize(v);
  for (int i = 0; i < v; ++i){
    for (int j = 0; j < v; ++j){
      if (data[i][j] > 0){
        vec_indegree[j] += 1;
      }
    }
  }

  std::deque<int> zero_queue;
  for (int i = 0; i < v; ++i){
    if (vec_indegree[i] == 0){
      zero_queue.push_back(i);
      --vec_indegree[i];
    }
  }
  while(!zero_queue.empty()){
    int id = zero_queue.front();
    zero_queue.pop_front();
    out.push_back((int)id);
    for (int i = 0; i < v; ++i){
      if (data[id][i] > 0){
        vec_indegree[i] -= 1;
        if (vec_indegree[i] == 0){
          zero_queue.push_back(i);
        }
      }
    }
  }

  return true;
}


GraphList::GraphList()
  :v(0), e(0), data(NULL)
{
}

GraphList::~GraphList()
{

}

GraphList::GraphList(int v)
  :v(0), e(v), data(NULL)
{
    data = new std::list<int>[v];
};

bool GraphList::TopSort(std::vector<int> &out)
{
  std::deque<int> zero_queue;
  std::vector<int> vec_indegree;
  vec_indegree.resize(v);
  for (int i = 0; i < v; ++i){
    for (std::list<int>::iterator it = data[i].begin(); it != data[i].end(); ++it){
      vec_indegree[*it] += 1;
    }
  }

  for (int i = 0; i < v; ++i){
    if (vec_indegree[i] == 0){
      zero_queue.push_back(i);
      --vec_indegree[i];
    }
  }
  while(!zero_queue.empty()){
    int id = zero_queue.front();
    zero_queue.pop_front();
    out.push_back((int)id);
    for (std::list<int>::iterator it = data[id].begin(); it != data[id].end(); ++it){
      vec_indegree[*it] -= 1;
      if (vec_indegree[*it] == 0){
        zero_queue.push_back(*it);
      }
    }
  }

  return true;
}



