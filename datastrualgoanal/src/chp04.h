/*==========================================
  @Author      : zabambo
  @File        : src/chp04.h
  @Encoding    : utf-8
  @Create      : 2014-07-17 10:48:30
  @Modified    : 2014-07-17 18:21:24
  @Description : 树(tree)
==========================================*/

/*
1,树的大部分操作都是O(logN)
2,二叉查找树(binary search tree),应用于set与map,
  左子树小于根值，右子树大于根值
  由于树的递归定义,通常递归地编写操作例程,
  由于平均深度O(logN),不必担心栈被耗尽.
3,深度(depth),从根到ni的路径长度,根的深度为0
4,高,从ni到树叶的最长路径长度,叶子的高为0
5,先序遍历:先根后子
  中序遍历:先左再根再右
  后序遍历:先子后根
6,二叉树(binary tree),儿子不多于两个,平均深度O(sqrt(N))
7,表达式树,叶子是操作数,节点为操作符,二叉树中序遍历
*/

#ifndef SRC_CHP04_H_
#define SRC_CHP04_H_


#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <stack>


template<class E>
class Tree
{
  public:
    struct Node
    {
      E e;
      Node *child;
      Node *sibling;
    };

  public:
    Tree();
    ~Tree();

  public:
    virtual void VisitNode(Node *node);

    void FirstIterator(Node *tree);
    void LastIterator(Node *tree);

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
      Node():left(NULL), right(NULL){};
    };

  public:
    BinaryTree();
    ~BinaryTree();

  public:
    virtual void VisitNode(Node *node);

    void FirstIterator(Node *tree);
    void LastIterator(Node *tree);
    void MiddleIterator(Node *tree);
    
  protected:
    Node *tree_;
};

class ExpressionTree : public BinaryTree<char>
{
  public:
    ExpressionTree();
    ~ExpressionTree();

    virtual void VisitNode(Node *node);

  public:
    void LastIterBuild(const char *expr);
};


template<class E>
class BinarySearchTree : public BinaryTree<E>
{
  public:
    BinarySearchTree();
    ~BinarySearchTree();

  public:
    Node *Insert(const E &e, Node *tree);
    void Delete(const E &e, Node *tree);
    bool Contrain(const E &e, Node *tree);
    Node *FindMin(Node *tree);
    Node *FindMax(Node *tree);
};

#endif//SRC_CHP04_H_
