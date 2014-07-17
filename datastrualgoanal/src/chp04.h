/*==========================================
  @Author      : zabambo
  @File        : src/chp04.h
  @Encoding    : utf-8
  @Create      : 2014-07-17 10:48:30
  @Modified    : 2014-07-17 16:00:45
  @Description : 树(tree)
==========================================*/

/*
1,树的大部分操作都是O(logN)
2,二叉查找树(binary search tree),应用于set与map,平均深度O(logN)
3,深度(depth),从根到ni的路径长度,根的深度为0
4,高,从ni到树叶的最长路径长度,叶子的高为0
5,先序遍历:先根后子
  中序遍历:先左再根再右
  后序遍历:先子后根
6,二叉树(binary tree),儿子不多于两个,平均深度O(sqrt(N))
7,表达式树,叶子是操作数,节点为操作符
*/

#ifndef SRC_CHP04_H_
#define SRC_CHP04_H_


#include <stdio.h>
#include <stdlib.h>
#include <deque>


template<class E>
class Tree
{
  public:
    struct Node
    {
      E e;
      Node *child;
      Node *sibling;
      void Visit();
    };

  public:
    Tree();
    ~Tree();

  public:
    void FirstIterator(Node *tree);
    void LastIterator(Node *tree);
    void VisitNode(Node *node);

};


template<class E>
class BinaryTree
{
  public:
    struct Node
    {
      E e;
      Node *left;
      Node *right;
      void Visit();
    };

  public:
    BinaryTree();
    ~BinaryTree();

  public:
    void FirstIterator(Node *tree);
    void LastIterator(Node *tree);
    void VisitNode(Node *node);

};



#endif//SRC_CHP04_H_
