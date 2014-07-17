/*==========================================
  @Author      : zabambo
  @File        : src/chp04.cc
  @Encoding    : utf-8
  @Create      : 2014-07-17 10:48:39
  @Modified    : 2014-07-17 15:32:02
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
  if (NULL == tree){return;}
  std::deque<Node*> child;
  Node *node = tree;
  child.push_bakc(node);
  while (!child.empty()){
    node = child.front();
    child.pop_front();
    while(node){
      VisitNode(node);
      if (node->child){
        child.push_back(node->child);
      }
      node = node->sibling;
    }
  }
}

template<class E>
void Tree<E>::VisitNode(Node *node)
{
  node->Visit();
}





