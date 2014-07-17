/*==========================================
  @Author      : zabambo
  @File        : src/chp04.cc
  @Encoding    : utf-8
  @Create      : 2014-07-17 10:48:39
  @Modified    : 2014-07-17 16:02:27
  @Description : 
==========================================*/


#include "chp04.h"

template<class E>
void Tree<E>::Node::Visit()
{
  
}

template<class E>
Tree<E>::Tree()
{

}

template<class E>
Tree<E>::~Tree()
{

}

template<class E>
void Tree<E>::FirstIterator(Node *tree)
{
  VisitNode(tree);
  FirstIterator(tree->child);
  Node *node = tree->sibling;
  while(node){
    FirstIterator(node);
    node = node->sibling;
  }
}


template<class E>
void Tree<E>::LastIterator(Node *tree)
{
  FirstIterator(tree->child);
  Node *node = tree->sibling;
  while(node){
    FirstIterator(node);
    node = node->sibling;
  } 
  VisitNode(tree);
}
 

template<class E>
void Tree<E>::VisitNode(Node *node)
{
  node->Visit();
}












template<class E>
void BinaryTree<E>::Node::Visit()
{
  
}

template<class E>
BinaryTree<E>::BinaryTree()
{

}

template<class E>
BinaryTree<E>::~BinaryTree()
{

}

template<class E>
void BinaryTree<E>::FirstIterator(Node *tree)
{
  VisitNode(tree);
  FirstIterator(tree->left);
  FirstIterator(tree->right);
}

template<class E>
void BinaryTree<E>::LastIterator(Node *tree)
{
  FirstIterator(tree->left);
  FirstIterator(tree->right);
  VisitNode(tree);
}

template<class E>
void BinaryTree<E>::VisitNode(Node *node)
{
  node->Visit();
}


