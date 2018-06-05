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
  if (N==NULL)
  return 0;
  else return N->height;
}

int max( int a , int b)
{
  return (a>b) ? a : b;
}

struct Node* newNode(int key)
{
  struct Node* node = new Node();
  node->key=key;
  node->left=NULL;
  node->right=NULL;
  node->height=1;
  return node;
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

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;


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

  if(key<node->key)
  node->left=insert(node->left,key);
  else if(key>node->key)
  node->right=insert(node->right,key);
  else return node;
  node->height=max(height(node->left),height(node->right))+1;

  int bal = getBalance(node);

  if(bal>1 && key < node->left->key)
  return rightRotate(node);

  if(bal>1 && key > node->left->key)
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

  return 0;
}





struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key)
{

    if (root == NULL)
        return root;

    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    else
    {

        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;
            free(temp);
        }
        else
        {

            struct Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}



struct node* insert(struct node* node, int key, int *count)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key, count);
    else
    {
        node->right = insert(node->right, key, count);

        *count = *count + size(node->left) + 1;
    }

    node->height = max(height(node->left), height(node->right)) + 1;
    node->size   = size(node->left) + size(node->right) + 1;

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void constructLowerArray (int arr[], int countSmaller[], int n)
{
  int i, j;
  struct node *root = NULL;
  for  (i = 0; i < n; i++)
     countSmaller[i] = 0;
  for (i = n-1; i >= 0; i--)
  {
     root = insert(root, arr[i], &countSmaller[i]);
  }
}
