/*==========================================
  @Author      : zabambo
  @File        : src/chp04.h
  @Encoding    : utf-8
  @Create      : 2014-07-17 10:48:30
  @Modified    : 2014-07-18 17:27:11
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
8,二叉平衡树,任一节点的左右子树的高最多相差1,通过旋转(rotation)来修平衡
*/

#ifndef SRC_CHP04_H_
#define SRC_CHP04_H_


#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <stack>


template<typename E>
struct TreeNode
{
  E e;
  TreeNode *child;
  TreeNode *sibling;
};


template<typename Element, typename Node>
class Tree
{
  public:
    Tree();
    ~Tree();

  public:
    virtual void VisitNode(Node *node);

    void FirstIterator(Node *tree);
    void LastIterator(Node *tree);

};



template<typename E>
struct BinaryTreeNode
{
  E e;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
};



template<typename Element, typename Node>
class BinaryTree
{
  public:
    BinaryTree();
    ~BinaryTree();

  public:
    virtual void VisitNode(Node *node);

    void FirstIterator(Node *tree);
    void LastIterator(Node *tree);
    void MiddleIterator(Node *tree);
    
    void Release(Node *&tree);
    void Release();

    BinaryTree& operator = (const BinaryTree& bt);

    Node *Clone(const Node *node) {
      if (NULL == node){
        return NULL;
      }
      Node *new_node = new Node();
      new_node->e = node->e;
      new_node->left = Clone(node->left);
      new_node->right = Clone(node->right);
      return new_node;
    }

  protected:
    Node *tree_;
};



struct ExpressionTreeNode : public BinaryTreeNode<char>
{
};


class ExpressionTree : public BinaryTree<char, ExpressionTreeNode>
{
  public:
    ExpressionTree();
    ~ExpressionTree();

    virtual void VisitNode(ExpressionTreeNode *node);

  public:
    void LastIterBuild(const char *expr);
};


template<typename Element, typename Node>
class BinarySearchTree : public BinaryTree<Element, Node>
{
  public:
    BinarySearchTree();
    ~BinarySearchTree();

  public:
    Node *Insert(const Element &e, Node *tree){
      if (NULL = tree){
        Node *new_node = new Node;
        new_node->e = e;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
      }
      if (e > tree->e){
        tree->right = Insert(e, tree->right);
      }else if (e < tree->e){
        tree->left = Insert(e, tree->left);
      }
      return tree;
    }

    void Delete(const Element &e, Node *tree);

    bool Contrain(const Element &e, Node *tree);

    Node *FindMin(Node *tree){
      if (NULL == tree){
        return NULL;
      }
      Node *node = tree;
      while (node->left){
        node = node->left;
      }
      return node;
    }

    Node *FindMax(Node *tree){
      if (NULL == tree){
        return NULL;
      }
      Node *node = tree;
      while (node->right){
        node = node->right;
      }
      return node;
    }
};


template<typename Element>
struct AVLTreeNode
{
  Element e;
  AVLTreeNode *left;
  AVLTreeNode *right;
  int hight;
};


template<typename Element, typename Node>
class AVLTree : public BinarySearchTree<Element, Node>
{
  public: 
    AVLTree();
    ~AVLTree();

};



#endif//SRC_CHP04_H_
