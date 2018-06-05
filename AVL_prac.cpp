#include<bits/stdc++.h>
using namespace std;

struct Node{

  int key;
  struct Node* left;
  struct Node* right;
  int height;
};

int height(struct Node *N)
  {
    if (N == NULL)
        return 0;
    return N->height;
  }

int max(int a, int b)
  {
    return (a > b)? a : b;
  }

  struct Node* newNode(int key)
  {
      struct Node* node = new Node();
      node->key   = key;
      node->left   = NULL;
      node->right  = NULL;
      node->height = 1;  // new node is initially added at leaf
      return(node);
  }

struct Node* rightRotate(struct Node* y)
{
  struct Node* x = y->left;
  struct Node* z = x->right;

  x->right=y;
  y->left=z;

  y->height = max(height(y->left), height(y->right))+1;
  x->height = max(height(x->left), height(x->right))+1;

  return x;

}

struct Node* leftRotate(Node* x)
{
    struct Node* y = x->right;
    struct Node* z = y->left;


    y->left = x;
    x->right = z;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(Node* node,int key)
{
  if(node==NULL)
  return newNode(key);

  if(key < node->key)
    node->left=insert(node->left,key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else
    return node;

  node->height=max(height(node->left),height(node->right))+1;

  int bal =getBalance(node);

  if(bal > 1 && key < node->left->key)
  return rightRotate(node);

  if(bal > 1 && key > node->left->key)
  {
    node->left=leftRotate(node->left);
    return rightRotate(node);
  }

  if(bal < -1 && key > node->right->key)
  return leftRotate(node);

  if(bal < -1 && key < node->right->key)
  {
    node->right=rightRotate(node->right);
    return leftRotate(node);
  }


  return node;
}

void preOrder(Node* root)
{
  if(root==NULL)
    return;
  preOrder(root->left);
  cout<<root->key<<" ";
  preOrder(root->right);
}

int main()
{

  Node* root= NULL;

  root=insert(root,10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);


  preOrder(root);


  return 0;
}
