/*==========================================
  @Author      : zabambo
  @File        : src/chp04.cc
  @Encoding    : utf-8
  @Create      : 2014-07-17 10:48:39
  @Modified    : 2014-07-18 14:51:38
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
  if (NULL == tree){
    return;
  }
 
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
  if (NULL == tree){
    return;
  }
 
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
  if (NULL != node){
    node->Visit();
  }
}













template<class E>
BinaryTree<E>::BinaryTree()
  : tree_(NULL)
{

}

template<class E>
BinaryTree<E>::~BinaryTree()
{
  Release(tree_);
}

template<class E>
void BinaryTree<E>::FirstIterator(Node *tree)
{
  if (NULL == tree){
    return;
  }
  VisitNode(tree);
  FirstIterator(tree->left);
  FirstIterator(tree->right);
}

template<class E>
void BinaryTree<E>::LastIterator(Node *tree)
{
  if (NULL == tree){
    return;
  }
  FirstIterator(tree->left);
  FirstIterator(tree->right);
  VisitNode(tree);
}

template<class E>
void BinaryTree<E>::MiddleIterator(Node *tree)
{
  if (NULL == tree){
    return;
  }
  FirstIterator(tree->left);
  VisitNode(tree);
  FirstIterator(tree->right);
}

template<class E>
void BinaryTree<E>::Release(Node *&tree)
{
  if (NULL != tree){
    Release(tree->left);
    Release(tree->right);
    delete tree;
    tree = NULL;
  }
}

template<class E>
BinaryTree<E>& BinaryTree<E>::operator = (const BinaryTree<E>& bt)
{
  if (this == &bt){
    return *this;
  }
  Release(tree_);
  tree_ = Clone(bt.tree_);
  return *this;
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









template<class E>
BinarySearchTree<E>::BinarySearchTree()
{

}

template<class E>
BinarySearchTree<E>::~BinarySearchTree()
{

}


template<class E>
void BinarySearchTree<E>::Delete(const E &e, Node *tree)
{
  if (NULL == tree){
    return;
  }
  if (e == tree->e){
    if (NULL != tree->left && NULL != tree->right){
      Node *min = FindMin(tree->right);
      tree->e = min->e;
      Delete(min->e, tree->right);
    }else{
      Node *tmp = tree;
      tree = (NULL != tree->left ? tree->left : tree->right);
      delete tmp;
    }
  }else if (e < tree->e){
    Delete(e, tree->left);
  }else {
    Delete(e, tree->right);
  }
}

template<class E>
bool BinarySearchTree<E>::Contrain(const E &e, Node *tree)
{
  if (NULL == tree){
    return false;
  }else if (tree->e == e){
    return true;
  }else if (tree->e < e){
    return Contrain(e, tree->left);
  }else{
    return Contrain(e, tree->right);
  }
}
















