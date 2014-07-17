/*==========================================
  @Author      : zabambo
  @File        : src/chp04.cc
  @Encoding    : utf-8
  @Create      : 2014-07-17 10:48:39
  @Modified    : 2014-07-17 17:22:36
  @Description : 
==========================================*/


#include "chp04.h"


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
BinaryTree<E>::BinaryTree()
  : tree_(NULL)
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
void BinaryTree<E>::MiddleIterator(Node *tree)
{
  FirstIterator(tree->left);
  VisitNode(tree);
  FirstIterator(tree->right);
}

template<class E>
void BinaryTree<E>::VisitNode(Node *node)
{
  node->Visit();
}









void ExpressionTree::VisitNode(Node *node)
{
  printf("%c", node->e);
}

void ExpressionTree::LastIterBuild(const char *expr)
{
  if (NULL == expr){
    return;
  }
  Node *node = NULL;
  std::stack<Node*> node_stack;
  while(const char c = *(expr++)){
    if (' ' == c){
      continue;
    }
    node = new Node;
    node->e = c;
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))){
      if (node_stack.empty()){
        break;
      }
      node->right = node_stack.top();
      node_stack.pop();

      if (node_stack.empty()){
        break;
      }
      node->left = node_stack.top();
      node_stack.pop();
    }
    node_stack.push(node);
  }
  if (!node_stack.empty()){
    tree_ = node_stack.top();
  }
}

