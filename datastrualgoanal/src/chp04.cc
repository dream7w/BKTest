/*==========================================
  @Author      : zabambo
  @File        : src/chp04.cc
  @Encoding    : utf-8
  @Create      : 2014-07-17 10:48:39
  @Modified    : 2014-07-18 17:52:46
  @Description : 
==========================================*/


#include "chp04.h"


template<typename Element, typename Node>
Tree<Element,Node>::Tree()
{

}

template<typename Element, typename Node>
Tree<Element,Node>::~Tree()
{

}

template<typename Element, typename Node>
void Tree<Element,Node>::FirstIterator(Node *tree)
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


template<typename Element, typename Node>
void Tree<Element,Node>::LastIterator(Node *tree)
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
 

template<typename Element, typename Node>
void Tree<Element,Node>::VisitNode(Node *node)
{
  if (NULL != node){
    node->Visit();
  }
}













template<typename Element, typename Node>
BinaryTree<Element, Node>::BinaryTree()
  : tree_(NULL)
{

}

template<typename Element, typename Node>
BinaryTree<Element,Node>::~BinaryTree()
{
  Release(tree_);
}

template<typename Element, typename Node>
void BinaryTree<Element,Node>::FirstIterator(Node *tree)
{
  if (NULL == tree){
    return;
  }
  VisitNode(tree);
  FirstIterator(tree->left);
  FirstIterator(tree->right);
}

template<typename Element, typename Node>
void BinaryTree<Element,Node>::LastIterator(Node *tree)
{
  if (NULL == tree){
    return;
  }
  FirstIterator(tree->left);
  FirstIterator(tree->right);
  VisitNode(tree);
}

template<typename Element, typename Node>
void BinaryTree<Element,Node>::MiddleIterator(Node *tree)
{
  if (NULL == tree){
    return;
  }
  FirstIterator(tree->left);
  VisitNode(tree);
  FirstIterator(tree->right);
}

template<typename Element, typename Node>
void BinaryTree<Element,Node>::Release(Node *&tree)
{
  if (NULL != tree){
    Release(tree->left);
    Release(tree->right);
    delete tree;
    tree = NULL;
  }
}

template<typename Element, typename Node>
BinaryTree<Element,Node>& BinaryTree<Element,Node>::operator = (const BinaryTree<Element,Node>& bt)
{
  if (this == &bt){
    return *this;
  }
  Release(tree_);
  tree_ = Clone(bt.tree_);
  return *this;
}

template<typename Element, typename Node>
void BinaryTree<Element,Node>::VisitNode(Node *node)
{
  node->Visit();
}









void ExpressionTree::VisitNode(ExpressionTreeNode *node)
{
  printf("%c", node->e);
}

void ExpressionTree::LastIterBuild(const char *expr)
{
  if (NULL == expr){
    return;
  }
  ExpressionTreeNode *node = NULL;
  std::stack<ExpressionTreeNode *> node_stack;
  while(const char c = *(expr++)){
    if (' ' == c){
      continue;
    }
    node = new ExpressionTreeNode;
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









template<typename Element, typename Node>
BinarySearchTree<Element,Node>::BinarySearchTree()
{

}

template<typename Element, typename Node>
BinarySearchTree<Element,Node>::~BinarySearchTree()
{

}


template<typename Element, typename Node>
void BinarySearchTree<Element,Node>::Delete(const Element &e, Node *tree)
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

template<typename Element, typename Node>
bool BinarySearchTree<Element,Node>::Contrain(const Element &e, Node *tree)
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






template<typename Element, typename Node>
AVLTree<Element,Node>::AVLTree()
{

}

template<typename Element, typename Node>
AVLTree<Element,Node>::~AVLTree()
{
  
}

template<typename Element, typename Node>
int AVLTree<Element,Node>::Height(Node *node)
{
  return (NULL != node ? node->height : -1);
}


template<typename Element, typename Node>
void AVLTree<Element,Node>::Insert(const Element& e, Node *&node)
{
  if (NULL == node){
    node = new Node;
    node->e = e;
    node->left = NULL;
    node->right = NULL;
  }else if (e < node->e){
    Insert(e, node->left);
    if (Height(node->left) - Height(node->right) >= 2){
      if (e < node->left->e){
      }else{
      }
    }
  }else if (e > node->e){
    Insert(e, node->right);
  }else{
    return;
  }
  node->height = max(Height(node->left), Height(node->right)) + 1;
}








